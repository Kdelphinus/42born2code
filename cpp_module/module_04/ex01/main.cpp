#include "Brain.hpp"

int main() {
	Brain brain = Brain();

    brain.setIdeas(0, "Cat");
    brain.setIdeas(1, "Dog");
    std::cout << "ideas[0]: " << brain.getIdeas(0) << std::endl;
    std::cout << "ideas[1]: " << brain.getIdeas(1) << std::endl;
    std::cout << "ideas[2]: " << brain.getIdeas(2) << std::endl;

    Brain tmp;

    tmp = brain;
    std::cout << "ideas[0]: " << tmp.getIdeas(0) << std::endl;
    std::cout << "ideas[1]: " << tmp.getIdeas(1) << std::endl;
    std::cout << "ideas[2]: " << tmp.getIdeas(2) << std::endl;
	return 0;
}