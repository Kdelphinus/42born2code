import sys
from srcs_py import forks


def main ():
    fork = forks.Forks(sys.argv, True)
    #fork = forks.Forks(sys.argv, False)
    fork.advanced_tests()

if __name__ == "__main__":
    main()
