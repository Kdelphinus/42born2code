#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostram>

class Brain {
    private:
        std::string[100] ideas;
    public:
        Brain();
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
        ~Brain();
};

#endif
