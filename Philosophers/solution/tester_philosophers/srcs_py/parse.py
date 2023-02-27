from pyparsing import *

class Parse():

    def delete_escapesquence(str):
        ESC = Literal('\x1b')
        integer = Word(nums)
        escapeSeq = Combine(ESC + '[' + Optional(delimitedList(integer,';')) +
                oneOf(list(alphas)))

        nonAnsiString = lambda s : Suppress(escapeSeq).transformString(s)

        unColorString = nonAnsiString(str)

        return unColorString

    def parse_log_line(line):
        line = Parse.delete_escapesquence(line)

        line = line.rstrip('\n').split(" ", 1)

        timestamp = line[0]
        timestamp = int(timestamp)

        status = line[1]
        philo_nb = status.strip(" ").split(" ", 1)[0]
        philo_nb = int(philo_nb)
        action = status.strip(" ").split(" ", 1)[1]

        parsed_line = [timestamp, philo_nb, action]

        return parsed_line
