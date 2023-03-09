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

## 0.3 submission

평소처럼 Git 저장소에 과제를 제춯한다. 
