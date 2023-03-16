# minishell

## Index

- [0. Subject](#0-subject)
	- [0.1 개요](#01-개요)
	- [0.2 Mandatory part](#02-mandatory-part)
	- [0.3 Submission](#03-submission)
- [1. Functions](#1-functions)
	- [1.1 errno](#11-errno)
	- [1.2 perror](#12-perror)
	- [1.3 strerror](#13-strerror)
	- [1.4 fork](#14-fork)
	- [1.5 waitpid](#15-waitpid)
	- [1.6 wait3, wait4](#16-wait3-wait4)
	- [1.7 exit](#17-exit)
	- [1.8 execve](#18-execve)
	- [1.9 dup](#19-dup)
	- [1.10 dup2](#110-dup2)
	- [1.11 pipe](#111-pipe)
	- [1.12 access](#112-access)
	- [1.13 signal](#113-signal)
	- [1.14 sigset_t](#114-sigset_t)
	- [1.15 sigemptyset, sigaddset](#115-sigemptyset-sigaddset)
	- [1.16 sigaction](#116-sigaction)
	- [1.17 kill](#117-kill)
	- [1.18 unlinik](#118-unlink)
	- [1.19 readline](#119-readline)
	- [1.20 rl_clear_history](#120-rl_clear_history)
	- [1.21 rl_on_new_line](#121-rl_on_new_line)
	- [1.22 rl_replace_line](#122-rl_replace_line)
	- [1.23 rl_redisplay](#123-rl_redisplay)
	- [1.24 add_history](#124-add_history)
	- [1.25 getcwd](#125-getcwd)
	- [1.26 chdir](#126-chdir)
	- [1.27 stat, lstat, fstat](#127-stat-lstat-fstat)
	- [1.28 opendir, readdir, closedir](#128-opendir-readdir-closedir)
	- [1.29 ttyname, isatty](#129-ttyname-isatty)
	- [1.30 ttyslot](#130-ttyslot)
	- [1.31 ioctl](#131-ioctl)
	- [1.32 getenv](#132-getenv)
	- [1.33 tcsetattr, tcgetattr](#133-tcsetattr-tcgetattr)
	- [1.34 tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs](#134-tgetent-tgetflag-tgetnum-tgetstr-tgoto-tputs)
- [참고 자료](#참고-자료)

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
|External functs.|readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs|
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

### 1.14 sigset_t

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

### 1.16 sigaction

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
> 	- SA_ONSTACK
> 		- 이 값을 설정하면 시그널을 처리할 프로세스에 sigaltstack 시스템 호출로 생성한 대체 시그널 스택이 있는 경우에만 대체 스택에서 시그널을 처리한다. 
> 		- 그렇지 않으면 시그널은 일반 스택에서 처리된다.
> 	- SA_RESETHAND
> 		- 이 값을 설정하면 시그널의 기본 처리 방법은 SIG_DFL로 재설정되고 시그널이 처리되는 동안 시그널을 블록하지 않는다.
> 	- SA_NODEFEER
> 		- 이 값을 설정하면 시그널이 처리되는 동안 유닉스 커널에서 해당 시그널을 자동으로 블록하지 못한다.
> 	- SA_RESTART
> 		- 이 값을 설정하면 시스템은 시그널 핸들러에 의해 중지된 기능을 재시작하게 된다.
> 	- SA_SIGINFO
> 		- 이 값을 설정하지 않고 시그널을 받으면 시그널 번호만 시그널 핸들러로 전달된다.
> 	- SA_NOCLDWAIT
> 		- 이 값이 설정되어 있고 시그널이 SIGCHLLD면 시스템은 자식 프로세스가 종료될 때 좀비 프로세스를 만들지 않는다.
> 	- SA_NOCLDSTOP
> 		- 이 값이 설정되어 있고 시그널이 SIGHLD면 자식 프로세스가 중지나 재시작할 때, 부보 프로세스에 SIGCHILD 시그널을 전달하지 않는다.

### 1.17 kill

```c
#include <signal.h>

int kill(pid_t pid, int sig);
```

 **kill** 함수는 특정 프로세스나 프로세스 그룹에 시그널을 보내기 위해서 사용한다.

#### 파라미터

- pid
	- 양수일 때: sig 시그널을 pid로 보낸다.
	- 0일 때: 현재 프로세스가 속한 프로세스 그룹의 모든 프로세스에게 sig 시그널을 보낸다.
	- -1일 때: 1번 프로세스를 제외한 모든 프로세스에게 sig 시그널을 보낸다.
	- -1보다 작을 때: -pid 프로세스가 포함된 모든 그룹의 프로세스에게 sig 시그널을 보낸다.
- sig
	- 0일 때: 어떤 시그널도 보내지 않지만 에러 검사는 할 수 있다.
	- 시그널 목록 중 하나일 때: 지정된 시그널을 보낸다.

#### 반환값

- 성공 시: 0
- 실패 시: -1
	- 적당한 errno 값을 설정

### 1.18  unlink

```c
#include <unistd.h>

int	unlink(const char *pathname);
```

``unlink`` 함수는 파일을 삭제하는 system call 함수이다.
그러나 정확하게 이야기하면 ``unlink`` 함수는 hard link의 이름을 삭제하고 hard link가 참고하는 count를 하나 감소시킨다.
그리고 hard link의 참조 count가 0이 되면 실제 파일의 내용이 저장되어 있는 disk space를 free하여 삭제한다.
그렇기에 만약 hard link를 생성하지 않은 파일에 unlink를 사용하면 사실상 파일 삭제와 같은 역할을 한다.

> #### hard link 복습
> 1. i-node  
> - 파일이 생성될 때, 파일마다 주어지는 고유 번호
> - ls 명령어에서 -i 옵션을 주면 i-node를 확인할 수 있다.
>   
> 2. hard link
> - 간단하게는 파일을 복사하는 것
> - 허나 cp 명령어와는 다른데 어떤 파일을 수정해도 hard link로 연결된 모든 파일이 같이 수정된다.
> - 왜냐하면 완전 새로운 파일을 만드는 것이 아니라 같은 i-node를 가리키는 파일을 하나 더 만드는 것이기 때문이다.
>   
> 3. soft link
> - 바로가기 기능과 거의 비슷
> - 그렇기에 i-node의 값이 원본과 다르다.

그러나 만약 open 함수로 파일이 열려진 상태에서 unlink를 호출하여 hard link의 참조 count를 0으로 만들면 directory entry에서 파일 이름 등의 정보는 삭제되어도 disk space는 해제되지 않는다.

즉, OS는 hard link의 참조 count가 0이면서 file open 참조 count도 0일 때, 파일의 내용이 저장된 disk space를 free한다.

정상적으로 파일이나 link가 삭제되면 0을 반환한다. 오류가 발생하면 -1을 반환하고 errno에 상세오류 내용이 저장된다.

### 1.19 readline

> #### GNU readline
> 
> **GNU readline** 은 명령 줄 인터페이스(CLI)에서 줄 편집 및 입력 기록 저장 등의 역할을 하는 라이브러리이다. 입력 자동 완성, 커서 이동, 잘라내기, 복사, 붙여녛기 등의 기능을 지원하며 Bash 등의 CLI 기반 인터랙티브 소프트웨어에서 사용된다.
> 
> 컴파일할 때, ``-lreadline`` 컴파일러 플래그를 사용해야 한다.

```c
#include <readline/readline.h>

char *readline(const char *prompt);
```

**readline** 함수는 입력받은 문자열을 저장하고 저장된 메모리 주소를 반환하는 함수다. 

입력 받은 문자열이 할당되어 주소가 반환되는 것이기에 free를 해줘야 한다.

#### 파라미터

- prompt: 실행 시, 출력할 문장

#### 반환값

- 문자열 입력 시: 입력된 문자열이 저장된 주소
- 빈 문자열 입력 시: NULL

### 1.20 rl_clear_history

```c
#include <readline/readline.h> // 정확하지 않음 history.h 일수도

void rl_clear_history(void);
```

**rl_clear_history** 함수는 history.h안에 있는 clear_history() 함수와 동일한 방식으로 모든 항목을 삭제하여 히스토리 목록을 지운다. clear_history() 함수와 다른 점은 Readline이 히스토리 목록에 저장하는 비공개 데이터를 해제한다는 것이다.

### 1.21 rl_on_new_line

```c
#include <readline/readline.h>

int rl_on_new_line(void);
```

**rl_on_new_line** 함수는 일반적으로 update와 관련된 함수들에게 커서가 개행문자를 통해 다음 줄로 이동한 것을 알려준다. 그렇기에 개행 문자 출력 이후에 사용된다.

#### 반환값

- 성공 시: 0
- 실패 시: -1

### 1.22 rl_replace_line

```c
#include <readline/readline.h>

void rl_replace_line(const char *text, int clear_undo);
```

**rl_replace_line** 함수는 rl_line_buffer의 내용을 text로 바꾼다. 가능하면 point와 mark는 유지한다.

> #### rl_line_buffer
> 
> 지금까지 얻은 줄이다. rl_extend_line_buffer 함수를 사용하면 rl_line_buffer에 할당된 메모리를 늘릴 수 있다.
> 
> 아마 readline으로 받은 줄을 의미하는 것 아닐까....?

#### 파라미터

- text: rl_line_buffer를 대체할 문장
- clear_undo
	- 0일 경우: 현재 줄과 연결된 실행 취소 목록을 지우지 않음
	- 그 외의 경우: 현재 줄과 연결된 실행 취소 목록을 지움

### 1.23 rl_redisplay

```c
#include <readline/readline.h>

void rl_redisplay(void);
```

**rl_redisplay** 함수는 화면에 표시되는 내용을 변경하여 rl_line_buffer의 현재 내용을 반영한다. 이때, 프롬프트 값은 readline 함수에 프롬프트로 준 문자열로 이동한다. 

시그널을 받았을 때의 상황에서 rl_redisplay 함수를 사용한다.

### 1.24 add_history

```c
#include <readline/history.h>

void add_history(const char *string);
```

**add_history** 함수는 주어진 문자열을 히스토리 목록 끝에 배치한다. 연결된 데이터 필드가 있는 경우는 NULL로 설정된다. 

만약 stifle_history 함수를 사용하여 설정된 최대 히스토리 목록의 개수를 초과하면 가장 오래된 히스토리 목록을 제거한다. 히스토리 목록은 터미널처럼 방향키로 하나씩 불러올 수 있으며 스택처럼 가장 마지막 목록부터 확인할 수 있다.

#### 파라미터

- string: 히스토리 목록에 넣을 문자열

### 1.25 getcwd

```c
#include <unistd.h>

char *getcwd(char *buf, size_t size);
```

**getcwd** 함수는 현재 작업 디렉토리의 절대 경로명을 buf가 참조하는 메모리에 복사하고 buf에 대한 포인터를 반환한다.

만약 buf가 NULL이면 경로명을 저장하는데 필요한 공간이 size와 관계없이 할당된다. 그리고 이렇게 할당된 공간은 free할 수 있다.

buf의 길이는 <sys/param.h>에 정의된 MAXPATHLEN보다 커야한다.

이러한 방법은 많이 사용되었으나 현재 디렉토리('.')를 열고 fchdir 함수를 사용하여 반환하는 것이 훨씬 빠르고 오류 발생 가능성이 적은 방법이다. 

#### 파라미터

- buf
	- 할당되어있는 경우: 경로가 저장될 문자열
- size
	- buf의 크기
	- 만약 buf에 NULL을 입력하면 size의 크기는 의미가 없다.

#### 반환값

- 성공 시
	- buf가 할당되어 있는 경우: 할당된 buf의 주소를 반환
	- buf에 NULL 포인터를 넣은 경우: 새로 할당된 주소를 반환
- 실패 시
	- NULL 포인터 반환
	- 전역 변수 errno가 오류를 나타내도록 설정

### 1.26 chdir

```c
#include <unistd.h>

int chdir(const char *path);
```

**chdir** 함수는 현재 작업 중인 디렉토리를 변경한다. 쉘 상에서 cd 명령어와 동일한 동작을 한다.

디렉토리가 현재 디렉토리가 되려면 프로세스에 디렉토리에 대한 실행(검색) 권한이 있어야 한다.

#### 파라미터

- path
	- 변경할 디렉토리의 경로명
	- 현재 디렉토리가 검색의 시작점이 된다.

#### 반환값

- 성공 시: 0
- 실패 시
	- -1 반환
	- errno 설정됨

### 1.27 stat, lstat, fstat

```c
#include <sys/stat.h>

int stat(const char *restrict path, struct stat *resrict buf);
int lstat(const char *restrict path, struct stat *resrict buf);
int fstat(int fildes, struct stat *buf);
```

위 함수들은 파일에 대한 정보를 반환한다. 파일 자체에 대한 권한은 필요하지 않지만 stat()과 lstat()
의 경우, 파일로 연결되는 경로의 모든 디렉토리에 대한 실행(검색) 권한이 필요하다.

**stat** 함수의 경우, 경로가 가리키는 파일에 대한 통계를 작성하고 buf를 채웁니다.

**lstat** 함수의 경우, stat과 동일하지만 경로가 심볼릭 링크인 경우 참조하는 파일이 아니라 링크 자체를 통계화한다는 점이 다르다.

**fstat** 함수의 경우, stat과 동일하지만, 통계 처리할 파일이 파일 기술자 fd로 지정된다는 점이 다르다.

#### 파라미터

- path: 확인할 파일의 경로
- buf: 파일에 대한 정보를 저장할 buf
- fildes: 확인할 파일의 fd

### 반환값

- 성공 시: 0
- 실패 시
	- -1을 반환
	- errno 설정됨

### 1.28 opendir, readdir, closedir

```c
#include <dirent.h>

typedef struct _dirdesc {
	int	dd_fd;		/* file descriptor associated with directory */
	long	dd_loc;		/* offset in current buffer */
	long	dd_size;	/* amount of data returned by getdirentries */
	char	*dd_buf;	/* data buffer */
	int	dd_len;		/* size of data buffer */
	long	dd_seek;	/* magic cookie returned by getdirentries */
	long	dd_rewind;	/* magic cookie for rewinding */
	int	dd_flags;	/* flags for readdir */
	pthread_mutex_t	dd_lock; /* for thread locking */
	struct _telldir *dd_td;	/* telldir position recording */
} DIR;

struct dirent {
	u_int32_t d_fileno;		/* file number of entry */
	u_int16_t d_reclen;		/* length of this record */
	u_int8_t  d_type; 		/* file type, see below */
	u_int8_t  d_namlen;		/* length of string in d_name */
#ifdef _POSIX_SOURCE
	char	d_name[255 + 1];	/* name must be no longer than this */
#else
#define	MAXNAMLEN	255
	char	d_name[MAXNAMLEN + 1];	/* name must be no longer than this */
#endif
};

DIR           *opendir(const char *filename);
sturct dirent *readdir(DIR *dirp);
int           closedir(DIR *dirp);
```

> #### directory streadm
>
> DIR * 를 directory stream이라고 부른다. 이 디렉토리 스트림은 정규 파일 조작을 위한 파일 스트림(FILE * )과 상당히 비슷한 방식으로 쓰인다. 

**opendir** 함수는 filename으로 디렉토리를 열고 디렉토리 스트림을 연결한 다음 후속 작업에서 디렉토리 스트림을 식별하는데 사용할 포인터를 반환한다.

만약 filename에 access 할 수 없거나 전체 내용을 담을 수 있는 충분한 메모리를 할당할 수 없는 경우 NULL 포인터가 반환된다.

#### 파라미터 

- filename: 열고자 하는 디렉토리 이름

#### 반환값

- 성공 시: 디렉토리 스트림을 식별하는데 사용할 포인터
- 실패 시: NULL 포인터

**readdir** 함수는 다음 디렉토리 항목에 대한 포인터를 반환한다. 디렉토리 항목은 동일한 디렉토리 스트림에서 readdir이나 closedir 함수가 실행될 때까지 유효하게 유지된다.

이 함수는 디렉토리 끝에 도달하거나 오류가 발생하면 NULL을 반환한다. 그리고 에러가 발생했을 땐, errno는 getdirentries(2) 시스템 콜에 대해 문서화된 값 중 하나로 설정될 수 있다.

그리고 readdir 함수가 반환하는 디렉토리의 항목 순서는 지정되지 않는다. 즉, 정렬 순서 항목으로 반환된다는 보장이 없다.

#### 파라미터

- dirp: 현재 디렉토리 항목

#### 반환값

- 성공 시
	- 다음이 있을 때: 다음 디렉토리 항목
	- 끝까지 도달했을 때: NULL 포인터
- 실패 시
	- NULL 포인터 반환
	- errno 설정

**closedir** 함수는 주어진 디렉토리 스트림을 닫고 dirp 포인터와 연결된 구조체를 해제하는 함수다.

#### 파라미터

- dirp: 닫을 디렉토리 스트림

#### 반환값

- 성공 시: 0
- 실패 시
	- -1을 반환
	- errno 설정

### 1.29 ttyname, isatty

```c
#include <unistd.h>

char *ttyname(int fd);
int   isatty(int fd);
```

위 함수들은 터미널 유형 장치의 fd에서 작동한다.

**isatty** 함수는 fd가 유효한 터미널 유형 장치를 참조하는지 확인하는 함수다.

**ttyname** 함수는 isatty 함수가 참인 fd 관련 장치의 이름을 가져온다. ttyname은 정적 버퍼에 저장된 이름을 반환하며, 이후에 호출하면 덮어쓴다.

#### 파라미터

- fd: 터미널 유형 장치의 fd

#### 반환값

- isatty
	- fd가 터미널 유형 장치를 참조하는 경우: 1을 반환
	- 그렇지 않는 경우
		- 0을 반환
		- errno 설정

- ttyname
	- fd가 발견되고 isatty가 참을 반환할 경우: 이름 반환
	- 실패 시: NULL 포인터

### 1.30 ttyslot

```c
#include <unistd.h>

int ttyslot(void);
```

**ttyslot** 함수는 /etc/ttys 파일에 있는 항목 중 호출 프로세스에서 사용 중인 터미널의 인덱스를 반환하며, 일반적으로 이 값은 /etc/ 파일에 있는 현재 사용자에 대한 항목의 인덱스와 동일하다.

### 반환값

- 성공 시: 사용 중인 터미널의 인덱스
- 실패 시: 0

### 1.31 ioctl

```c
#include <sys/ioctl.h>

int ioctl(int fildes, unsigned long request, ...);
```

**ioctl** 함수는 하드웨어의 제어하고 상태 정보를 얻을 수 있는 함수다. 예를 들어 터미널의 많은 작동 특성은 ioctl 요청으로 제어할 수 있다. input output control의 약자이다.

다른 말로 read 함수와 write 함수만으로 해결되지 않는 제어에 사용된다. 예를 들어 CD-ROM 드라이버에 실제 장치에서 디스크를 꺼내도록 지시하는 등의 low level의 하드웨어를 제어하는 행위는 ioctl만 가능하다.

#### 파라미터

- fildes
	- fd값으로 열려있어야 한다.
- request
	- 장치에 따라 달라지는 요청 코드
	- 사용되는 매크로는 <sys/ioctl.h> 파일에 있다.
	- 우리는 <sys/ioccom.h>에 있는 듯...
- ...
	- 타입이 지정되지 않은 메모리 포인터
	- 전통적으로 *argp라고 한다.

#### 반환값

- 성공 시
	- 일반적인 상황: 0을 반환
	- 몇몇 요청의 경우
		- 출력 매개변수로 사용
		- 음수가 아닌 값
- 실패 시
	- -1 반환
	- errno 설정

### 1.32 getenv

```c
#include <stdlib.h>

char *getenv(const char *name);
```

**getenv** 함수는 name이라는 이름을 가진 환경변수를 가져온다. 

환경변수는 "key=value" 형태로 저장되며 name이 key가 된다. 즉, name이란 key를 가진 value를 반환하는 것이다.

#### 파라미터

- name: 가져올 환경변수 key

#### 반환값

- 성공 시: name과 일치하는 환경변수의 value
- 실패 시: NULL

### 1.33 tcsetattr, tcgetattr

```c
#include <termios.h>

typedef unsigned long	tcflag_t;
typedef unsigned char	cc_t;
typedef long		speed_t;	/* XXX should be unsigned long */

struct termios {
	tcflag_t	c_iflag;	/* input flags */
	tcflag_t	c_oflag;	/* output flags */
	tcflag_t	c_cflag;	/* control flags */
	tcflag_t	c_lflag;	/* local flags */
	cc_t		c_cc[NCCS];	/* control chars */
	speed_t		c_ispeed;	/* input speed */
	speed_t		c_ospeed;	/* output speed */
};

int tcgetattr(int fildes, struct termios *termios_p);
int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);
```

**tcgetattr** 함수는 터미널 파일에 대한 속성을 얻어서 termios_p에 저장한다.

#### 파라미터

- fd: 터미널의 fd
- termios_p: 터미널 속성을 저장할 포인터

#### 반환값

- 성공 시: 0
- 실패 시
	- -1을 반환
	- errno 설정
		- EBADF: 유효하지 않은 fd
		- ENOTTY: 터미널이 아닌 fd
		- EINVAL: termios_p is NULL

**tcsetatter** 함수는 터미널 파일에 대한 속성을 설정한다.

#### 파라미터

- fd: 터미널 fd
- optional_actions
	- 동작 선택
	- TCSNOW: 속성을 바로 변경한다
	- TCSADRAIN: 송신을 완료한 후 변경한다.
	- TCSAFLUSH: 송수신 완료 후 변경한다.
- termios_p: 터미널 속성을 저장할 포인터

#### 반환값

- 성공 시: 0
- 실패 시
	- -1
	- errno 설정
		- EBADF: 유효하지 않은 fd
		- ENOTTY: 터미널이 아닌 fd
		- EINVAL: termios_p is NULL

#### c_lflag의 속성

|이름|설명|
|:---|:---|
|ISIG|signal을 받아들인다. 이 플래그가 on이면 INTR, QUIT, SUSP, DSUSP와 같은 특수문자를 받아들인다.|
|ICANON|이 플래그가 on이면 정규모드로 입력이 이루어진다.|
|NOFLSH|queue flush를 비활성화 시킨다.|
|ECHO|반향(어떤 사건이나 발표 따위가 세상에 영향을 미치어 일어나는 반응)을 설정한다. 이 플래그가 off되어 있으면 입력은 반향되지 않는다.|
|ECHOE|erase 문자를 반향한다. ECHO 플래그가 on이면 스크린의 마지막 문자를 지운다.|
|ECHOPRT|ECHO, ECHOPRT가 on인 상태에서 ERASE가 발생하면 삭제되는 문자가 '\\' 뒤에 표시된다. 만약 모든 문자를 삭제했다면 '/'가 출력된다.|
|ECHONL|NL 문자가 반향된다. ECHO 플래그와 상관없이 NL 문자를 반향한다.|
|ECHOCTL|제어문자가 반향되도록 한다. 이 플래그를 on 시킨 상태에서 ctrl + x를 누르면 ^X로 화면에 표시된다.|

### 1.34 tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

```c
#include <term.h>

int tgetent(char *bp, const char *name);
int tgetflag(char *id);
int tgetnum(char *id);
char *tgetstr(char *id, char **area);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));
```

> #### termcap.h
>  
>  터미널 등에서 커서를 제어하기 위해서 사용하는 라이브러리이다. 이 라이브러리를 사용할 시, -lncurses 옵션을 붙어주어야 한다.

위 함수들은 termcap 라이브러리를 사용하는 프로그램들을 위한 함수이다.

**tgetent** 함수는 name에 대한 항목을 불러온다. 

#### 파라미터

- bp
	- 대부분 무시한다.
	- 만일 이를 사용한다면 다른 루틴 함수에서도 이용한다.
	- 그러나 대부분 루틴들이 공통적으로 사용하는 BUFFER를 내부적으로 할당하여 사용한다.
- name
	- 보편적으로 TERM 환경 변수로 할당된 터미널 타입을 이용한다.

#### 반환값

- 성공 시: 1
- name의 값이 비어있는 경우: 0
- 실패 시: -1

**tgetflag** 함수는 id에 대한 플래그를 얻을 수 있으면 1, 없으면 0을 반환한다.

**tgetnum** 함수는 id에 대한 값을 가져올 수 있으면 그 값을, 없으면 -1을 반환한다.

**tgetstr** 함수는 id에 대한 문자열 항목을 가져올 수 있으면 반환하고, 없으면 NULL을 반환한다. area인자는 tgetent에서 사용된 bp를 의미하는데 일반적으로 쓰지 않기에 대부분 NULL을 넣는다.

**tgoto** 함수는 커서 모션의 세로열(col), 가로열(row)를 고려한 것을 반환한다. 여기서 인자인 cap은 capablilty를 의미하며 일반적으로 cursor motion이 cm에 대한 것을 사용한다. tgoto에서 반환된 값은 tputs 함수의 인자로 사용된다. 실패할 경우, NULL을 반환한다.

**tputs** 함수는 터미널 출력 결과를 나타내는 루틴이다. str의 인자는 tgetstr이나 tgoto를 통해 얻은 값을 넣으며, affcnt의 경우 영향을 끼칠 줄의 수를 나타내는데 일반적으로 1을 준다. putc는 ASCII 문자 값을 인자로 받아 표준 출력의 쓰기 작업으로 터미널에 ASCII 문자 값을 출력해주는 함수다. 함수의 동작이 성공하면 0, 그렇기 않으면 -1을 반환한다.

## 참고 자료

- [42 seoul, minishell](https://cdn.intra.42.fr/pdf/pdf/68660/en.subject.pdf)
- [Kdelphinus's github, pipex README](https://github.com/Kdelphinus/42born2code/blob/main/pipex/README.md)
- [길은 가면, 뒤에 있다. , (시스템프로그래밍) 시그널](https://12bme.tistory.com/224)
- [네이버 블로그 d, sigaction 함수의 활용](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skssim&logNo=121271980)
- [GNU, GNU Readline Library](https://web.archive.org/web/20111029034104/http://cnswww.cns.cwru.edu/php/chet/readline/readline.html)
- [GNU, GNU History Library](https://web.archive.org/web/20111107191103/http://cnswww.cns.cwru.edu/php/chet/readline/history.html)
- [Apple Computer, sys/dirent.h](https://opensource.apple.com/source/xnu/xnu-124.8/bsd/sys/dirent.h.auto.html)
- [Apple Computer, dirent.h](https://opensource.apple.com/source/Libc/Libc-320/include/dirent.h.auto.html)
- [Apple Computer, sys/termios.h](https://opensource.apple.com/source/xnu/xnu-201/bsd/sys/termios.h.auto.html)
- [팔만코딩경, 표준입력으로 들어오는 ctrl + d Handling](https://80000coding.oopy.io/13bd7bb7-3a7f-4b51-b84a-905c47368277)
- [오늘도 밤이야, UNIX termcap 라이브러리를 이용한 커서 제어)](https://hyeonski.tistory.com/6)
- [팔만코딩경, minishell](https://bigpel66.oopy.io/library/42/inner-circle/10)
- 