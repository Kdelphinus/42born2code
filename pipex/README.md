# pipex

# 0. External functs

## 0.1 errno

``errno`` 는 <errno.h> 파일에 있는 광역변수로써 라이브러리 함수 수행 중 에러가 발생하면 에러 코드를 가진다.
함수 실행 중 에러없이 리턴되었다면 errno는 0을 가지지만 수행 중 에러가 발생했다면 0 이외의 값을 갖는다.

```
#include <stdio.h>
#include <errno.h>

int	main(void)
{
	FILE *fp;

	fp = fopen( "./test.c", "r");	// 파일이 있음
	printf( "error = %d\n", errno);	// error = 0
	fclose( fp);
	printf( "error = %d\n", errno);	// error = 0

	fp = fopen( "./nofile.c", "r");	// 파일이 없음
	printf("error = %d\n", errno);	// error = 2
	fclose(fp);	// segmentation fault
	printf("error = %d\n", errno);

	return 0;
}
```

## 0.2 perror

```
#include <stdio.h>

void perror(const char *str);
```

``perror`` 은 오류 메세지를 출력하는 함수다.

전역 변수 ``errno`` 의 값을 해석하여 이에 해당하는 시스템 오류 메세지를 표준 오류 출력 스트림(stderr)에 출력한다.

``str`` 은 시스템 오류 메세지 다음에 이어서 출력할 사용자 정의 메세지를 받는다.
만약 널 포인터라면 시스템 오류 메세지만 출력된다.
관습적으로 프로그램의 이름이 인자로 주로 사용된다.

## 0.3 strerror

```
#include <string.h>

char	*strerror(int errnum);
```

``strerror`` 함수는 오류 메세지 문자열을 가리키는 포인터를 가져온다.

``errnum`` 인자는 오류 번호를 가지며 보편적으로 errno의 값을 넣는다.
errnum을 통해 발생한 오류에 알맞은 오류 메세지를 가리키는 포인터를 반환하며 이 때, 반환되는 포인터는 문자열 리터럴을 가리키기에 그 내용이 바뀔 수 없다.

또한 strerror에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.

## 0.4 fork

```
#include <unistd.h>

pid_t	fork(void);
```

``fork`` 함수는 현재 실행되는 프로세스에 대한 복사본을 만들어 자식 프로세스를 생성한다.


> pid_t 자료형
>
> 프로세스 id를 저장하는 자료형

> 프로세스
>
> - 디스크에 있던 프로그램 파일이 메모리에 올려지고 시스템의 스케쥴에 따라 실행되는 실행 단위
> - 프로세스는 운영체제로부터 시스템 자원을 할당 받는 단위이고 스레드는 프로그램 실행 단위이다.
> - 프로세스는 운영체제로부터 메모리, 주소공간 등을 할당받고 스레드는 할당 받은 자원들을 스레드끼리 공유하며 실행된다.

fork 함수를 호출하는 프로세스는 부모 프로세스가 되고 새롭게 생성되는 프로세스는 자식 프로세스가 된다. 자식 프로세스는 부모 프로세스의 메모리를 그대로 복사하여 가지게 된다. 그리고 fork 함수 호출 이후 코드부터 각자의 메모리를 사용하여 실행된다.

반환값은 다음과 같다.

- 성공시
  - 부모 프로세스: 자식 프로세스의 pid(0보다 큰 값)
  - 자식 프로세스: 0

- 실패시
  - 부모 프로세스: -1
  - 자식 프로세스는 생성되지 않는다.

```
int	x = 0;

fork();

x = 1;
printf("PID: %d, x: %d\n", getpid(), x);
```

```
PID: 35501, x: 1
PID: 35502, x: 2
```

위 예시처럼 fork 함수 코드 이후부터는 부모 프로세스와 자식 프로세스가 각자 printf() 코드를 실행한다. 부모 프로세스(pid: 35501)에서 x값을 1로 출력했고, 자식 프로세스(pid: 35502)에서도 x값을 1이라 출력했다.

![fork](https://velog.velcdn.com/images%2Ft1won%2Fpost%2F143d2ba6-3811-4c0d-9fe9-416a217243ca%2Fimage.png)

fork 함수가 실행된 직후에는 자식 프로세스는 부모 프로세스와 동일한 주소 공간의 복사본을 가진다. fork 함수 실행 이후, 부모와 자식 프로세스는 동일한 코드를 각자 메모리 상에서 실행하는 것이다.

```
int	main(void)
{
	pid_t	pid;

	int	x = 0;

	pid = fork();

	if (pid > 0) // 부모 프로세스
	{
		x = 1;
		printf("Parents PID: %ld, x: %d, pid: %d\n", (long)getpid(), x, pid);
	}
	else if (pid == 0) // 자식 프로세스
	{
		x = 2;
		printf("Child PID: %ld, x: %d\n", (long)getpid(), x);
	}
	else // fork 실패
	{
		printf("fork fail\n");
		return -1;
	}
```

```
Parents PID: 36318, x: 1, pid: 36319
Child PID: 36319, x: 2
```

부모 프로세스와 자식 프로세스의 작업을 다르게 하려면 fork에서 반환되는 pid값을 이용하면 된다. 부모 프로세스는 자식 프로세스의 PID를 가지고 자식 프로세스는 pid를 가지기 않기에 위처럼 다른 값을 가지게 할 수 있다.

![fork2](https://velog.velcdn.com/images%2Ft1won%2Fpost%2Fe21d5583-b61e-4626-9ba6-55abf60e9580%2Fimage.png)

그 외에도 하나의 변수를 선언하고 프로세스의 작업을 나누면 다른 값으로 저장하여 사용할 수 있다.

## 0.5 waitpid

```
#include <unistd.h>

pid_t	waitpid(pid_t pid, int *status, int options);
```

``waitpid`` 함수는 자식 프로세스가 종료될 때까지 대기한다. ``wait`` 역시 같은 기능을 하는데 차이는 wait은 자식 프로세스 중 하나라도 종료되면 대기를 끝내지만 waitpid는 특정 자식 프로세스가 종료될 때까지 대기한다.

또한 wait 함수는 자식 프로세스가 종료될 때까지 block 되지만 waitpid 함수는 WNOHANG 옵션을 사용하여 block 되지 않고 다른 작업을 진행할 수 있다.

### **파라미터**

- ``pid_t pid``: 지켜볼 자식 프로세스의 id이다. 이 id 값에는 자식 프로세스 id 외에도 다양한 값을 지정할 수 있다.
  - -1: 여러 자식 중 하나라도 종료되면 복귀, 즉 wait과 같은 동작
  - 0: 현재의 프로세스 그룹 id와 같은 그룹의 자식 프로세스가 종료되면 복귀
  - 양수: pid에 해당하는 자식 프로세스가 종료되면 복귀
  - -1보다 작은 경우: 프로세스 그룹 id가 pid의 절대값과 같은 자식 프로세스를 기다림
- ``int *status``: 자식 프로세스의 종료 상태 정보
  - 정상 종료 시: status의 하위 8비트에는 0이 저장되며, 상위 8비트에는 프로세스가 종료되게한 exit 함수의 인자가 기록된다.
  - 비정상 종료 시: status의 하위 8비트에는 프로세스를 종료시킨 시그널의 번호가 저장되며 상위 8비트에는 0이 저장된다.
- ``int options``: 여러 상수값이 있지만 대체로 두 가지를 많이 사용한다.
  - ``WNOHANG``: 자식 프로세스가 종료되었는지 실행 중인지 확인만 하고 바로 복귀, 즉 부모 프로세스는 block되지 않는다.
  - 0: 자식 프로세스가 종료될 때까지 block, 즉 wait과 같은 동작

### **리턴값**

- 성공: 종료된 자식 프로세스 id
- 오류: -1
  - 지정한 pid의 프로세스나 프로세스 그룹이 없는 경우의 발생
  - pid가 자식 프로세스가 아닐 때 발생
- 0: WNOHANG을 사용했고 자식 프로세스가 종료되지 않았을 때

## 0.6 exit

```
#include <stdlib.h>

void	exit(int status);
```

status가 1이면 에러로 인한 종료, 0은 정상 종료를 뜻한다. EXIT_SUCCUSS, EXIT_FAIURE로 미리 정의되어 있기 때문에 사용 가능하다.

자식 프로세스가 비정상적으로 종료되었을 경우에는 커널에서 비정상 종료 상태를 별도로 설정한다. 부모 프로세스는 자식의 종료 상태(정상/비정상)를 wait 함수 또는 waitpid 함수로 얻을 수 있다.

## 0.7 execve

```
#include <unistd.h>

int	execve(const char *filename, char *const argv[], char *const envp[]);
```

``execve``는 실행 가능한 파일인 filename의 실행 코드를 현재 프로세스에 적재하여 기존의 실행코드와 교체하고 새로운 기능으로 실행한다. 즉, 현재 실행되는 프로그램의 기능은 없어지고 filename 프로그램을 메모리에 loading하여 처음부터 실행한다.

### 파라미터
- filename
  - 교체할 실행 파일 / 명령어
  - filename은 실행 가능한 binary이거나 shell이어야 한다.
  - filename은 path가 설정되어 있는 디렉토리여도 절대 경로나 상대 경로로 정확한 위치를 지정해야 한다.
- argv
  - main에서의 argv와 비슷하며, argc가 없기에 argv 마지막에 NULL이 있다.
- envp
  - key=value 형식의 환경 변수 문자열 배열리스트로 마지막은 NULL이 와야 한다.
  - 만약 설정된 환경 변수를 사용하려면 ``environ`` 전역변수를 그냥 사용한다.
    - C 프로그램에서는 environ이라는 전역 변수가 미리 만들어 있어 이를 통해 환경 변수 목록을 확인할 수 있다. 다른 곳에서 미리 선언한 상태이므로 extern 문으로 environ 변수를 참조하여 환경 변수 목록을 확인할 수 있다.

```
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;

int	main(int argc, char *argv[])
{
	char	**new_argv;
	char	command[] = "ls";
	int		idx;

	new_argv = (char **)malloc(sizeof(char *) * (argc + 1));

	new_argv[0] = command; // 명령어를 ls로 변경

	// command line으로 넘어온 parameter를 그대로 사용
	for (idx = 1; idx < argc; idx++)
		new_argv[idx] = argv[idx];

	// argc를 execve 파라미터에 전달할 수 없기 때문에 NULL이 파라미터의 끝을 의미한다.
	new_argv[argc] = NULL;
	if (execve("/bin/ls", new_argv, environ) == -1)
	{
		fprintf(stderr, "프로그램 실행 error: %s\n", strerror(errno));
		return 1;
	}

	// ls 명령어 binary로 실행로직이 교체되었으므로 이후의 로직은 절대 실행되지 않는다.
	printf("이것은 이제 ls 명령어러 이 라인은 출력되지 않는다. \n");
	return 0;
}
```

위 코드는 ls 프로그램을 실행한다.

## 0.8 dup

```
#include <unistd.h>

int	dup(int fd);
```

``dup``는 새로운 fd를 반환하지만 숫자만 다를 뿐 기존 fd와 복제된 fd는 완전히 같은 파일을 가리킨다. 또한 파라미터로 전달된 값이 유효한 fd가 아니거나 더 이상 fd를 할당하지 못할 경우, -1을 반환한다.

복제된 fd가 기존 fd와 같은 파일을 가리키지만 기존 fd를 닫는다하여도 복제된 fd는 계속해서 열려있다.

## 0.9 dup2

```
#incldue <unistd.h>

int	dup2(int fd, int fd2);
```

``dup2``는 파일 식별자를 복제해 fd2를 fd1으로 바꿔주는 함수다. 예를 들어 ``int dup2(fd, stdout);``으로 사용하면 모든 출력이 fd로 향하게 된다.

## 0.10 pipe

```
#include <unistd.h>

int	pipe(int filedes[2]);
```

``pipe`` 는 프로세스간 통신 할 때, 사용하는 커뮤니케이션의 한 방법이다.

# 참고 자료
- [tseo.log, [C]](https://velog.io/@t1won/C-C-yee43s5w)
- [팔만코딩경, [pipex]파이프 이해하기](https://80000coding.oopy.io/a19eda17-f1e2-454d-8182-7ae3271506fd#8a6afcee-eb48-4f63-836a-d25f16c57fc9)
- [바다야크, C언어 에러 번호 구하는 변수 errno](https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%97%90%EB%9F%AC-%EB%B2%88%ED%98%B8-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%B3%80%EC%88%98-errno)