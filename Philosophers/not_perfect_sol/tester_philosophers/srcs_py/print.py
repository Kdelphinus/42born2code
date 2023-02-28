from srcs_py import const
from srcs_py.err_flags import Error

class Print():

    def print_instruction ():
        print(f'{const.GREEN}green = eating')
        print(f'{const.YELLOW}yellow = waiting a fork{const.RESET}')
        print(f'{const.RED}red = dead{const.RESET}')
        print()
        print(f'{"time(elapsed)":<10}')

    def print_result (nb_of_eat, error):
        print("[result]")
        for err_flag in Error:
            if nb_of_eat == -1 and err_flag == Error.NBEAT:
                continue
            if nb_of_eat != -1 and err_flag == Error.DEATH:
                continue
            print(f'{Error.flag2str(err_flag)}: ' , end='')
            if error & err_flag:
                print(f'{const.RED}[KO]{const.RESET}', end='\n')
            else:
                print(f'{const.GREEN}[OK]{const.RESET}', end='\n')
        print()
        print(f'see {const.LOG_FILE} for philo output')
        print(f'see {const.RESULTS_FILE} for more details')


    def count_forks(philo_id, forks, nb_of_pilos):
        fork_left = forks[philo_id - 1]
        if philo_id == nb_of_pilos:
            fork_right = forks[0]
        else:
            fork_right = forks[philo_id]

        return (fork_left == philo_id) + (fork_right == philo_id)


    def is_philo_eating(philo_id, forks, nb_of_pilos):
        if nb_of_pilos == 1:
            return False

        if (Print.count_forks(philo_id, forks, nb_of_pilos) == 2):
            return True
        return False

    def is_philo_taking_a_fork(philo_id, forks, nb_of_pilos):
        if (Print.count_forks(philo_id, forks, nb_of_pilos) > 0):
            return True
        return False

    def print_forks(forks, time_start, time_prev, philo_dead, nb_of_pilos):
        # print timepassed
        time_passed = time_prev - time_start
        print("{1}({0:>8})".format(time_passed, str(time_prev)[-3:]), end=" ")

        if (forks[0] == nb_of_pilos):
            print(f'{const.GRAY}', end="")

        philo_id = 1
        for afork in forks:
            print(f'[{afork}]', end="")
            print(f'{const.RESET}', end=" ")

            # set philo color
            if (philo_id == philo_dead):
                print(f'{const.RED}', end="")
            elif (Print.is_philo_eating(philo_id, forks, nb_of_pilos)):
                print(f'{const.GREEN}', end="")
            elif (Print.is_philo_taking_a_fork(philo_id, forks, nb_of_pilos)):
                print(f'{const.YELLOW}', end="")
            print(philo_id, end="")
            print(f'{const.RESET}', end=" ")
            philo_id = philo_id + 1

        if (forks[0] == nb_of_pilos):
            print(f'[{forks[0]}]', end="")
        print()


