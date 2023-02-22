import sys
from srcs_py import const, err_flags, log
from srcs_py.parse import Parse

class Read():

    def read_stdin (error):
        instructions = []
        f = open(const.LOG_FILE, 'w')
        for line in sys.stdin:
            try:
                f.write(line)
                parsed_line = Parse.parse_log_line(line)
                if parsed_line == "":
                    break
                instructions.append(parsed_line)
            except:
                error |= err_flags.Error.LOGFORMAT
                log.set_error_print_log(err_flags.Error.LOGFORMAT, line=line)
                pass
        f.close()
        return instructions

    # *************** May Buggy ****************** #
    def read_file (instructions, error):
        with open(const.READ_FILE) as f:
            for line in f:
                try:
                    parsed_line = Parse.parse_log_line(line)
                    if parsed_line == "":
                        break
                    instructions.append(parsed_line)
                except:
                    error |= err_flags.Error.LOGFORMAT
                    log.set_error_print_log(err_flags.Error.LOGFORMAT, line=line)
                    pass
