#include "Harl.h"

int main(int argc, char **argv) {
    int level;
    Harl harlFilter;

    if (argc != 2) {
        std::cout << "The number of arguments is incorrect." << std::endl;
        return 0;
    }
    level = harlFilter.getLevel(argv[1]);
    switch (level) {
        case 0:
            harlFilter.runDebug(level);
                    __attribute__((fallthrough));
        case 1:
            harlFilter.runInfo(level);
                    __attribute__((fallthrough));
        case 2:
            harlFilter.runWarning(level);
                    __attribute__((fallthrough));
        case 3:
            harlFilter.runError(level);
            break;
        default:
            harlFilter.runDefault();
            break;
    }
    return (0);
}
