#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef enum e_errno { BADARGCD, WRONGPATHCD, FAILEXEC } t_errno;

int print_err(t_errno errno, char *av) {
    if (errno == BADARGCD)
        write(2, "error bad arg blablabla", 22);
    else if (errno == WRONGPATHCD)
        write(2, "error wrong path blablabla ", 27);
    else if (errno == FAILEXEC)
        write(2, "error fail exec blablabla ", 26);
    write(2, "\n", 1);
    return (1);
}

int run_exec(char **av, int i, int tmp_fd, char **envp) {
    av[i] = NULL;
    dup2(tmp_fd, STDIN_FILENO);
    if (tmp_fd)
      close(tmp_fd);
    execve(av[0], av, envp);
    return (1);
}

int main(int ac, char **av, char **envp) {
    int i = 0;
    int fd[2];
    int tmp_fd;

    if (ac < 2)
        return (0);
    tmp_fd = STDIN_FILENO;
    while (av[i] && av[i + 1]) {
        av = &av[i + 1];
        i = 0;
        while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
            i++;
        if (!strcmp(av[0], "cd")) {
            if (i != 2)
                print_err(BADARGCD, NULL);
            else if (chdir(av[1]) == -1)
                print_err(WRONGPATHCD, av[1]);
        } else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";"))) {
            if (fork() == 0) {
                if (run_exec(av, i, tmp_fd, envp))
                    return (print_err(FAILEXEC, av[0]));
            } else {
                if (tmp_fd)
                    close(tmp_fd);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                tmp_fd = STDIN_FILENO;
            }
        } else if (i != 0 && !strcmp(av[i], "|")) {
            pipe(fd);
            if (fork() == 0) {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
                if (run_exec(av, i, tmp_fd, envp))
                    return (print_err(FAILEXEC, av[0]));
            } else {
                close(fd[1]);
                if (tmp_fd)
                    close(tmp_fd);
                tmp_fd = fd[0];
            }
        }
    }
}
