from srcs_py import const, log, err_flags
from srcs_py.read import Read
from srcs_py.print import Print

class Forks():

    def __init__(self, av, readfromstdin):
        try:
            self.nb_of_pilos = int(av[1])
            self.time_to_die = int(av[2])
            self.time_to_eat = int(av[3])
            self.time_to_sleep = int(av[4])
            try:
                self.nb_of_eat = int(av[5])
            except:
                self.nb_of_eat = -1
        except:
            print("argv is required for checking death\n")
        self.max = self.nb_of_pilos
        self.error = err_flags.Error(0)
        self.instructions = []
        log.print_start_log(av)
        print("Start loading instructions ...")
        if readfromstdin:
            self.instructions = Read.read_stdin(self.error)
        else:
            self.instructions = Read.read_file(self.error)
        self.forks = [0] * self.max
        # write in log file
        av.pop(0)

    def advanced_tests (self):
        print("Start running tests ...")
        Print.print_instruction()
        self.check_actionlength()
        self.time_start = self.instructions[0][0]
        time_prev = self.time_start
        philo_dead = -1
        for step in self.instructions:
            time = step[0]
            # when timestamp changed
            if (time != time_prev):
                Print.print_forks(self.forks, self.time_start, time_prev, philo_dead, self.nb_of_pilos)
                time_prev = time
            self.check_fork_status(time, step[1], step[2])
        philo_dead = self.instructions[-1][1]
        Print.print_forks(self.forks, self.time_start, time_prev, philo_dead, self.nb_of_pilos)
        print()
        if self.nb_of_eat == -1:
            self.check_death()
        else:
            self.check_nb_eat()
        Print.print_result(self.nb_of_eat, self.error)

    def check_fork_status (self, time, philo_nb, action):
        right = philo_nb
        if (right == self.max):
            right = 0
        left = philo_nb - 1
        if (action == const.fork):
            if (self.forks[right] == philo_nb):
                if (self.forks[left] != 0):
                    self.error |= err_flags.Error.FORK
                    log.set_error_print_log(err_flags.Error.FORK, time=time, philo_nb=philo_nb)
                self.forks[left] = philo_nb
            else:
                if (self.forks[right] != 0):
                    self.error |= err_flags.Error.FORK
                    log.set_error_print_log(err_flags.Error.FORK, time=time, philo_nb=philo_nb)
                self.forks[right] = philo_nb
        elif (action == const.sleep):
            self.forks[right] = 0
            self.forks[left] = 0

    def check_death (self):
        philo_dead = self.instructions[-1][1]
        last_eat = self.instructions[0][0]
        num_fork = 0
        for step in self.instructions:
            time = step[0]
            philo_nb = step[1]
            action = step[2]
            if (last_eat - time >= self.time_to_die + 10 and action != const.died):
                self.error |= err_flags.Error.DEATH
                log.set_error_print_log(err_flags.Error.DEATH, philo_nb=philo_dead,
                time_exp=last_eat + self.time_to_die, time_act=time)
            if (time - last_eat < self.time_to_die and action == const.died):
                self.error |= err_flags.Error.DEATH
                log.set_error_print_log(err_flags.Error.DEATH, philo_nb=philo_dead,
                time_exp=last_eat + self.time_to_die, time_act=time)
            if (philo_nb == philo_dead and action == const.fork):
                num_fork = num_fork + 1
            if (num_fork == 2):
                last_eat = time
                num_fork = 0
        if (self.instructions[-1][2] != const.died or self.instructions[-2][2] == const.died):
            self.error |= err_flags.Error.EOS
            log.set_error_print_log(err_flags.Error.EOS)

    def check_nb_eat(self):
        cnt = [0] * (self.nb_of_pilos + 1)
        exceed = 0
        for step in self.instructions:
            if step[2] == const.eat:
                cnt[step[1]] = cnt[step[1]] + 1
        for i in range(1, self.nb_of_pilos + 1):
            if cnt[i] < self.nb_of_eat:
                self.error |= err_flags.Error.NBEAT
                log.set_error_print_log(err_flags.Error.NBEAT, philo_nb=step[1], eat=cnt[i])
            if cnt[i] > self.nb_of_eat:
                exceed = exceed + 1
        if exceed == self.nb_of_pilos:
            self.error |= err_flags.Error.NBEAT
            log.set_error_print_log(err_flags.Error.NBEAT, philo_nb=step[1], eat=cnt[1])

    def check_actionlength(self):
        dict_tmp = {"time_eatst":0, "time_sleepst":0}
        lst = [dict_tmp.copy() for i in range(self.nb_of_pilos)]
        for step in self.instructions:
            lst_i = lst[step[1] - 1]
            time_now = step[0]
            action = step[2]
            if action == const.eat:
                lst_i["time_eatst"] = time_now
            elif action == const.sleep:
                diff = time_now - lst_i["time_eatst"] - self.time_to_eat
                if diff < -const.ACCEPTABLE_DIFF or diff > const.ACCEPTABLE_DIFF:
                    self.error |= err_flags.Error.TIME
                    log.set_error_print_log(err_flags.Error.TIME, time=time_now,
                        philo_nb=step[1], action="ate", diff=diff)
                lst_i["time_sleepst"] = time_now
            elif action == const.think:
                diff = time_now - lst_i["time_sleepst"] - self.time_to_sleep
                if diff < -const.ACCEPTABLE_DIFF or diff > const.ACCEPTABLE_DIFF:
                    self.error |= err_flags.Error.TIME
                    log.set_error_print_log(err_flags.Error.TIME, time=time_now,
                        philo_nb=step[1], action="slept", diff=diff)
