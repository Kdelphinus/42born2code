#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef enum e_errno { BADARGCD, WRONGPATHCD, FAILEXEC } t_errno;

int ft_strlen(char *str) {
  int i = 0;
  while (str[i++]);
  return (i);
}

// 에러 출력은 서브젝트에서 하라는 대로 시스템 에러 안해도 됨(포크에러 파이프에러 이런애들은 안해도 됨)
int print_err(t_errno errno, char *av) {
  if (errno == BADARGCD)
	write(2, "error bad arg blablabla", 22);
  else if (errno == WRONGPATHCD) {
	write(2, "error wrong path blablabla ", 27);
	write(1, av, ft_strlen(av));
  } else if (errno == FAILEXEC)
	write(2, "error fail exec blablabla ", 26);
  write(2, "\n", 1);
  return (1);
}

int run_exec(char *(*av), int i, int tmp_fd, char **envp) {
  av[i] = NULL;
  if (tmp_fd != 0) {
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
  }
  execve(av[0], av, envp);
  return (1);
}

int main(int ac, char **av, char **envp) {
  int i = 0;
  int fd[2];
  int tmp_fd;

  if (ac < 2)
	return (0);
  tmp_fd = 0;
  while (av[i] && av[i + 1]) {
	av = &av[i + 1];
	i = 0;
	while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|")) // ;나 |를 만나기 전까지
	  i++;
	if (!strcmp(av[0], "cd")) {
	  if (i != 2)
		print_err(BADARGCD, NULL);
	  else if (chdir(av[1]) == -1)
		print_err(WRONGPATHCD, av[1]);
	} else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";"))) // ;거나 eof 일 때
	{
	  if (fork() == 0) // 포크떠서 자식으 여기로
	  {
		if (run_exec(av, i, tmp_fd, envp))
		  return (print_err(FAILEXEC, av[0]));
	  } else // 포크 후 부모는 여기로
	  {
		if (tmp_fd != 0)
		  close(tmp_fd);
		while (waitpid(-1, NULL, WUNTRACED)
			!= -1) // while(waitpid(-1, NULL, 2) != -1) ; 걍 외우셈 WUNTRACED로 옵션 주면 -1리턴이 샷다리턴
		  ;
		tmp_fd = 0; // 이거 정말 중요함. 초기화를 해줘야한다. 안하면? 죽어야지
	  }
	} else if (i != 0 && !strcmp(av[i], "|")) // |일 때
	{
	  pipe(fd);
	  if (fork() == 0) // 자식이 생김
	  {
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		if (run_exec(av, i, tmp_fd, envp))
		  return (print_err(FAILEXEC, av[0]));
	  } else {
		close(fd[1]);
		if (tmp_fd != 0)
		  close(tmp_fd);
		tmp_fd = fd[0];
	  }
	}
  }
}