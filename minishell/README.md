# minishell

## Index

## 0. Subject

### 0.1 개요
- Version: 6
- Summary
	- 간단한 쉘 만들기
	- 프로세스와 file descriptor에 대해서 많은 것을 배울 것

### 0.2 Mandatory part

|Program name|minishell|
|:---|:---|
|Turn in files|Makefile, *.h, *.c|
|Makefile|NAME, all, clean, fclean, re|
|Arguments||
|External functs.|readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs|
|Libft authorized|Yes|
|Description|Write a shell|

- 새 명령어를 기다릴 때, **prompt**를 표시한다.
- 작업 이력이 있어야 합니다.
- 올바른 실행 파일을 검색하고 실행합니다. (PATH 변수를 기반 or 상대 경로 or 절대 경로)
- 전역 변수는 한 개만 사용 가능, 사용할 경우 사용한 목적을 설명해야 한다.
- Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign). 
- redirection을 구현
  - '<'는 입력을 redirection한다.
  - '>'는 출력을 redirection한다.
  - '<<'에 구분 기호를 지정한 다음 구분 기호가 포함된 줄이 보일 때까지 입력을 읽어야 합니다. 그러나 히스토리를 업데이트할 필요는 없습니다!
  - '>>'는 추가 모드에서 출력을 리디렉션해야 합니다.
- 파이프('|')를 구현합니다. 파이프라인에서 각 명령의 출력은 파이프를 통해 다음 명령의 입력에 연결된다.
- 해당 값으로 확장되어야 하는 환경 변수($ 뒤에 문자 시퀀스)를 처리합니다.
- 가장 최근에 실행된 전경 파이프라인의 종료 상태로 확장되어야 하는 $? 포그라운드 파이프라인의 종료 상태로 확장되어야 합니다.
- bash에서와 같이 ctrl-C, ctrl-D, ctrl-\ 이 작동해야 한다.
- 대화형 모드에서
  - ctrl-C는 새 줄에서 새 프롬프트를 표시한다.
  - ctrl-D는 쉘을 종료한다.
  - ctrl-\는 아무 작업도 수행하지 않는다.
- 쉘은 다음 내장 기능도 구현되어 있어야 한다.
  - -n이 있는 **echo**
  - 상대 경로나 절대 경로만 있는 **cd**
  - 옵션이 없는 **export**
  - 옵션이 없는 **unset**
  - 옵션이나 인자가 없는 **env**
  - 옵션이 없는 **exit**
- **readline()** 함수는 메모리 누수를 발생시킬 수 있다. 이것을 수정할 필요는 없으나 직접 작성한 코드에선 누수가 발생하면 안 된다.

> 구현과 설명은 subject에 국한되어야 하며 요청되지 않은 내용들은 필요하지 않다. 만약 의심스러운 요구가 있으면 bash를 참조해라.

### 0.3 submission

평소처럼 Git 저장소에 과제를 제출한다. 

## 1. Functions

### 1.1 errno

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

### 1.2 perror

```
#include <stdio.h>

void perror(const char *str);
```

``perror`` 은 오류 메세지를 출력하는 함수다.

전역 변수 ``errno`` 의 값을 해석하여 이에 해당하는 시스템 오류 메세지를 표준 오류 출력 스트림(stderr)에 출력한다.

``str`` 은 시스템 오류 메세지 다음에 이어서 출력할 사용자 정의 메세지를 받는다.
만약 널 포인터라면 시스템 오류 메세지만 출력된다.
관습적으로 프로그램의 이름이 인자로 주로 사용된다.

### 1.3 strerror

```
#include <string.h>

char	*strerror(int errnum);
```

``strerror`` 함수는 오류 메세지 문자열을 가리키는 포인터를 가져온다.

``errnum`` 인자는 오류 번호를 가지며 보편적으로 errno의 값을 넣는다.
errnum을 통해 발생한 오류에 알맞은 오류 메세지를 가리키는 포인터를 반환하며 이 때, 반환되는 포인터는 문자열 리터럴을 가리키기에 그 내용이 바뀔 수 없다.

또한 strerror에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.

### 1.4 fork

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

### 1.5 waitpid

```
#include <sys/wait.h>

pid_t	waitpid(pid_t pid, int *stat_loc, int options);
```

``waitpid`` 함수는 자식 프로세스가 종료될 때까지 대기한다. ``wait`` 역시 같은 기능을 하는데 차이는 wait은 자식 프로세스 중 하나라도 종료되면 대기를 끝내지만 waitpid는 특정 자식 프로세스가 종료될 때까지 대기한다.

또한 wait 함수는 자식 프로세스가 종료될 때까지 block 되지만 waitpid 함수는 WNOHANG 옵션을 사용하여 block 되지 않고 다른 작업을 진행할 수 있다.

#### **파라미터**

- ``pid_t pid``: 지켜볼 자식 프로세스의 id이다. 이 id 값에는 자식 프로세스 id 외에도 다양한 값을 지정할 수 있다.
  - -1: 여러 자식 중 하나라도 종료되면 복귀, 즉 wait과 같은 동작
  - 0: 현재의 프로세스 그룹 id와 같은 그룹의 자식 프로세스가 종료되면 복귀
  - 양수: pid에 해당하는 자식 프로세스가 종료되면 복귀
  - -1보다 작은 경우: 프로세스 그룹 id가 pid의 절대값과 같은 자식 프로세스를 기다림
- ``int *stat_loc``: 자식 프로세스의 종료 상태 정보
  - 정상 종료 시: status의 하위 8비트에는 0이 저장되며, 상위 8비트에는 프로세스가 종료되게한 exit 함수의 인자가 기록된다.
  - 비정상 종료 시: status의 하위 8비트에는 프로세스를 종료시킨 시그널의 번호가 저장되며 상위 8비트에는 0이 저장된다.

	> |매크로|설명|
	> |:---:|:---:|
	> |WIFEXITED(status)|자식 프로세스가 정상적으로 종료되었다면 TRUE|
	> |WIFSIGNALED(status)|자식 프로세스가 시그널에 의해 종료되었다면 TRUE|
	> |WIFSTOPPED(status)|자식 프로세스가 중단되었다면 TRUE|
	> |WEXITSTATUS(status)|자식 프로세스가 정상 종료되었을 때 반환한 값|

- ``int options``: 여러 상수값이 있지만 대체로 두 가지를 많이 사용한다.
  - ``WNOHANG``: 자식 프로세스가 종료되었는지 실행 중인지 확인만 하고 바로 복귀, 즉 부모 프로세스는 block되지 않는다.
  - 0: 자식 프로세스가 종료될 때까지 block, 즉 wait과 같은 동작

#### **리턴값**

- 성공: 종료된 자식 프로세스 id
- 오류: -1
  - 지정한 pid의 프로세스나 프로세스 그룹이 없는 경우의 발생
  - pid가 자식 프로세스가 아닐 때 발생
- 0: WNOHANG을 사용했고 자식 프로세스가 종료되지 않았을 때

### 1.6 wait3, wait4

```c
#include <sys/wait.h>

pid_t wait3(int *stat_loc, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage);
```

wait3, wait4 함수는 사용자의 시간 정보를 확보할 수 있다.

#### **파라미터**

- stat_loc, options, pid: waitpid의 파라미터와 동일
- ``rusage``: 자식 프로세스의 리소스 사용량에 대한 정보가 struct rusage 형태로 담긴다. 

#### **리턴값**

- 성공
	- 종료된 자식 프로세스 id
	- 만약 함수가 WNOHANG 옵션으로 실행되었고, 자식 프로세스가 종료되지 않았다면 0
- 실패 시: -1

### 1.7 exit

```
#include <stdlib.h>

void	exit(int status);
```

status가 1이면 에러로 인한 종료, 0은 정상 종료를 뜻한다. EXIT_SUCCESS, EXIT_FAILURE로 미리 정의되어 있기 때문에 사용 가능하다.

자식 프로세스가 비정상적으로 종료되었을 경우에는 커널에서 비정상 종료 상태를 별도로 설정한다. 부모 프로세스는 자식의 종료 상태(정상/비정상)를 wait 함수 또는 waitpid 함수로 얻을 수 있다.

### 1.8 execve

```
#include <unistd.h>

int	execve(const char *filename, char *const argv[], char *const envp[]);
```

``execve``는 실행 가능한 파일인 filename의 실행 코드를 현재 프로세스에 적재하여 기존의 실행코드와 교체하고 새로운 기능으로 실행한다. 즉, 현재 실행되는 프로그램의 기능은 없어지고 filename 프로그램을 메모리에 loading하여 처음부터 실행한다.

#### 파라미터
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

#### envp

```
int	main(int argc, char **argv, char **envp);
```

위에서 environ이란 전역변수로 간단하게 환경변수를 불러올 수 있다고 했지만 과제에서 전역변수가 선언에 관한 허용이 없다.
그렇기에 argc, argv를 main의 파라미터로 받듯이 envp도 파라미터로 받아주어야 한다.

### 1.9 dup

```
#include <unistd.h>

int	dup(int fd);
```

``dup``는 새로운 fd를 반환하지만 숫자만 다를 뿐 기존 fd와 복제된 fd는 완전히 같은 파일을 가리킨다. 또한 파라미터로 전달된 값이 유효한 fd가 아니거나 더 이상 fd를 할당하지 못할 경우, -1을 반환한다.

복제된 fd가 기존 fd와 같은 파일을 가리키지만 기존 fd를 닫는다하여도 복제된 fd는 계속해서 열려있다.

### 1.10 dup2

```
#incldue <unistd.h>

int	dup2(int fd, int fd2);
```

``dup2``는 파일 식별자를 복제해 fd2를 fd1으로 바꿔주는 함수다. 예를 들어 ``int dup2(fd, stdout);``으로 사용하면 모든 출력이 fd로 향하게 된다.

### 1.11 pipe

```
#include <unistd.h>

int	pipe(int filedes[2]);
```

``pipe`` 는 프로세스간 통신 할 때, 사용하는 커뮤니케이션의 한 방법이다.

pipe를 이용하면 2개의 파일 지시자를 생성할 수 있는데 이는 읽기 전용과 쓰기 전용의 파이프를 생성하기 위함이다. 파라미터로 들어가는 filedes[0]은 읽기 전용, filedes[1]은 쓰기 전용 파이프로 사용된다. 이렇게 만들어진 파이프는 주로 부모 프로세스와 자식 프로세스 간의 통신을 위한 목적으로 사용된다.

pipe 함수가 성공적으로 호출되었다면 0, 실패했다면 -1을 반환한다.

![pipe](https://velog.velcdn.com/images%2Ft1won%2Fpost%2F35ac9870-cbea-422b-86c3-5639b5f040ea%2Fimage.png)

2개의 파일 지시자를 생성하는 자세한 이유를 보자면 파이프는 커널영역에 생성되어 파이프를 생성한 프로세스는 파일 디스크립터만 갖고 있게 된다. 앞서 봤듯이 fd[0]은 읽기용 파이프, fd[1]은 쓰기용 파이프다. 그렇기에 만약 데이터를 fd[1]에 쓰게 된다면 fd[0]에서 그 데이터를 읽을 수 있다.

#### 자식 프로세스와 통신

자식 프로세스를 fork하면 파일 디스크립터는 부모의 파일 디스크립터를 자식이 그대로 사용할 수 있는 기능을 활용한다. 부모 프로세스는 파이프에 데이터를 쓰는 프로세스, 자식 프로세스는 그 파이프에서 데이터를 읽는 프로세스로 설계한다.

![pipe2](https://velog.velcdn.com/images%2Ft1won%2Fpost%2Fb0315ed8-1af0-47ad-af81-152e9f7622b1%2Fimage.png)

우선 부모 프로세스에서 파이프를 생성하면 데이터를 쓸 것이기 때문에 읽기 파이프(fd[0])은 닫는다. 그 후, 쓰기 파이프(fd[1])로 데이터를 작성한다.

자식 프로세스는 쓰기 파이프는 사용하지 않기에 fd[1]은 항상 닫혀 있고 fd[0]으로 데이터를 읽는다.

#### 부모와 자식 프로세스 간의 읽기 쓰기

만약 파이프 한 개만을 이용해 부모 프로세스와 자식 프로세스가 읽기, 쓰기가 가능하게 구현가능한가?

![pipe3](https://velog.velcdn.com/images%2Ft1won%2Fpost%2F038871b7-65a5-4ff2-841f-49e4acf418d3%2Fimage.png)

다음과 같은 상황을 가정해보자.

1. 부모 프로세스가 파이프 fd[1]로 데이터를 보낸다.
2. 자식 프로세스가 부모 프로세스가 쓴 데이터를 fd[0]으로 읽는다.
3. 자식 프로세스는 바로 fd[1]로 파이프에 응답값을 보낸다.
4. 부모 프로세스는 fd[0]으로 자식 프로세스가 보낸 응답값을 읽는다.

그러나 위와 같은 상황은 항상 일어나지 않으며 부모가 쓰고 바로 읽으려 하여 서순이 꼬여 망할 수 있다. 그렇기에 파이프 한 개만 사용하면 불가하다.

그렇기에 파이프를 2개 사용해야 한다.

![pipe4](https://velog.velcdn.com/images%2Ft1won%2Fpost%2F1ed4ab69-60a2-40b9-b04b-e4f0395ac925%2Fimage.png)

fdA와 fdB 두 개의 파일 디스크렙터를 이용한다.

부모 프로세스는 자식 프로세스에게 쓰기용 fdA[1], 자식 프로세스로부터 읽기용 fdB[0]만 있으면 된다. 필요없는 fdA[0]과 fdB[1]은 닫아준다.

자식 프로세느는 부모 프로세스로부터 읽기용 fdA[0], 쓰기용으로 fdB[1]만 있으면 된다. 역시 필요없는 fdA[1], fdB[0]은 닫아준다.

### 1.12 access

```
#include <unistd.h>

int	access(const char *pathname, int mode);
```

``access``함수는 파일이나 디렉토리의 사용자 권한을 체크하는 함수다. mode에 따라 권한을 체크할 수 있으며 mode의 종류는 다음과 같다.

- R_OK: 파일 존재 여부, 읽기 권한 여부
- W_OK: 파일 존재 여부, 쓰기 권한 여부
- X_OK: 파일 존재 여부, 실행 권한 여부
- F_OK: 파일 존재 여부

access의 반환값은 성공 시 0, 실패 시 -1을 반환하며 오류 원인은 errno에 세팅된다.

아래의 예시처럼 사용할 수 있다.

```
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *pathname = "./hello.txt"
	int	mode = R_OK | W_OK;

	if (access(pathname, mode) == 0)
		printf("have permission to read and write");
	else
		printf("do not have permission or the file does not exist");
}
```

이때 mode에 비트 연산을 이용해서 여러가지 권한을 한 번에 체크할 수 있다. ([비트 연산 참고](https://gksid102.tistory.com/90))

### 1.13 signal

```c
#include <signal.h>

void (*signal(int sig, void (*func)(int)))(int);
```

**signal** 함수는 시그널 처리를 설정한다.

#### 파라미터
- sig
	- 처리할 시그널
	- man signal을 치면 이미 정의된 시그널 중 하나를 사용
- func
	- 어떤 것을 넣느냐에 따라 동작이 다른다.
		- SIG_DFL: 기존 정의된 방법을 따른다.
		- SIG_IGN: 시그널을 무시한다.
		- 함수 이름: 시그널이 발생하면 지정된 함수를 호출한다.

### 1. 14 sigset_t

```c
typedef struct {
	unsigned int __sigbits[4];
}   sigset_t;
```

**sigset_t** 는 복수의 시그널을 처리할 수 있도록 만든 구조체이다. 

### 1.15 sigemptyset, sigaddset

```c
#include <signal.h>

int sigemptyset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
```

**sigemptyset** 함수는 인자로 주어진 set에 포함되어 있는 모든 시그널들을 비운다.

**sigaddset** 함수는 signum 번호의 시그널을 set에 추가한다.

#### 반환값

- 성공 시: 0
- 실패 시: -1

### 1.15 sigaction

```c
#include <signal.h>

struct sigaction {
	union __sigaction_u    __sigaction_u; /* signal handler */
	sigset_t    sa_mask;                  /* signal maks to apply */
	int         sa_flags;                 /* see signal options below */ 
};

union __sigaction_u {
	void   (*__sa_handler)(int);
	void   (*__sa_sigaction)(int, siginfo_t *, void *);
};

#define sa_handler.     __sigaction_u.__sa_handler
#define sa_sigaction    __sigaction_u.__sa_sigaction

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
```

**sigaction** 함수는 특정 시그널의 수신에 대해서 취할 액션을 설정하거나 변경하기 위해서 사용된다.

#### 파라미터

- signum
	- 시그널을 명시한다.
	- SIGKILL, SIGSTOP을 제외한 모든 시그널을 넣을 수 있다.
- act
	- NULL이 아니라면 signum 번호를 가지는 시그널에 대해서 act함수가 설치된다.
- oldact
	- NULL이 아니라면 이전의 액션은 oldact에 저장된다.

#### 반환값
 
- 성공 시: 0
- 실패 시: -1

> **struct sigaction**
>
> - sa_handler과 sa_sigaction
> 	- signum 번호를 가지는 시그널이 발생했을 때, 실행된 함수를 설치한다.
> 	- 함수 외에도 SIG_DFL, SIG_IGN을 지정할 수 있다.
> 
> 	- 만약 sa_flags에 SA_SIGINFO가 설정되어 있지 않으면 sa_handler에 시그널을 처리할 동작을 지정한다.
> 	- 반대로 SA_SIGINFO가 설정되어 있다면 sa_sigaction 멤버를 사용한다.
>
> - sa_mask
> 	- 시그널 핸들러가 동작 중일 때, 블록할 시그널을 시그널 집합으로 지정한다.
> 	- 시그널 핸들러가 시작되어 시그널을 전달할 때, 이미 블록된 시그널 집합에 sa_mask로 지정한 시그널 집합을 추가한다.
> 	- sa_flags에 SA_NODEFER을 설정하지 않으면 시그널 핸들러를 호출하게 한 시그널도 블록된다.
>
> - sa_flags
> |플래그|설명|
> |:---|:---|
> |SA_ONSTACK|이 값을 설정하면 시그널을 처리할 프로세스에 sigaltstack 시스템 호출로 생성한 대체 시그널 스택이 있는 경우에만 대체 스택에서 시그널을 처리한다. 그렇지 않으면 시그널은 일반 스택에서 처리된다.|
> |SA_RESETHAND|이 값을 설정하면 시그널의 기본 처리 방법은 SIG_DFL로 재설정되고 시그널이 처리되는 동안 시그널을 블록하지 않는다.|
> |SA_NODEFEER|이 값을 설정하면 시그널이 처리되는 동안 유닉스 커널에서 해당 시그널을 자동으로 블록하지 못한다.|
> |SA_RESTART|이 값을 설정하면 시스템은 시그널 핸들러에 의해 중지된 기능을 재시작하게 된다.|
> |SA_SIGINFO|이 값을 설정하지 않고 시그널을 받으면 시그널 번호만 시그널 핸들러로 전달된다.|
> |SA_NOCLDWAIT|이 값이 설정되어 있고 시그널이 SIGCHLLD면 시스템은 자식 프로세스가 종료될 때 좀비 프로세스를 만들지 않는다.|
> |SA_NOCLDSTOP|이 값이 설정되어 있고 시그널이 SIGHLD면 자식 프로세스가 중지나 재시작할 때, 부보 프로세스에 SIGCHILD 시그널을 전달하지 않는다.



## 참고 자료

- [42 seoul, minishell](https://cdn.intra.42.fr/pdf/pdf/68660/en.subject.pdf)
- [Kdelphinus's github, pipex README](https://github.com/Kdelphinus/42born2code/blob/main/pipex/README.md)
- [길은 가면, 뒤에 있다. , (시스템프로그래밍) 시그널](https://12bme.tistory.com/224)
- [네이버 블로그 d, sigaction 함수의 활용](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121271980)
- 