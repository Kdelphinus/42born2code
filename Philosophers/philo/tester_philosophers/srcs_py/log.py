import logging
from srcs_py import const, err_flags

logger = logging.getLogger("logger")    #logger名loggerを取得
logger.setLevel(logging.DEBUG)  #loggerとしてはDEBUGで
#handlerを作成
handler = logging.FileHandler(filename=const.RESULTS_FILE, mode='a')
handler.setFormatter(logging.Formatter("%(filename)8s: %(message)s"))
logger.addHandler(handler)

def set_error_print_log(err_flag, **kwargs):
    if err_flag == err_flags.Error.FORK:
        logger.debug(f"at {kwargs['time']}, the fork philosopher {kwargs['philo_nb']} grabbed was not yet released")
    elif err_flag == err_flags.Error.DEATH:
        logger.debug(f"the philosopher {kwargs['philo_nb']} died at wrong time.\n\
          philosopher {kwargs['philo_nb']} was supposed to die at {kwargs['time_exp']}, \
but died at {kwargs['time_act']}; {kwargs['time_exp'] - kwargs['time_act']}ms early")
    elif err_flag == err_flags.Error.EOS:
        logger.debug(f"operation after death")
    elif err_flag == err_flags.Error.LOGFORMAT:
        logger.debug(f"log format is wrong {kwargs['line']}")
    elif err_flag == err_flags.Error.TIME:
        logger.debug(f"at {kwargs['time']}, philosopher {kwargs['philo_nb']} {kwargs['action']} {kwargs['diff']}ms longer")
    elif err_flag == err_flags.Error.NBEAT:
        logger.debug(f"philosopher {kwargs['philo_nb']} only ate {kwargs['eat']} times")

def print_start_log(av):
    logger.debug(f"./philo {av}")
