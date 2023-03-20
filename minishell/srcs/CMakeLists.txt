ADD_EXECUTABLE(
        minishell
        main.c
        pipe_split_set.c
        pipe_utils.c
        pipe_pid.c
        pipe_error.c
        pipe_run.c
#        builtin_func.c
        envp_init.c
#        parsing_start.c
        run_cmd.c
#        signal_func.c
)