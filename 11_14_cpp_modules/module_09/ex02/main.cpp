#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    try {
        PmergeMe pmg(ac, av);
        pmg.compareMergeInsertion();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}