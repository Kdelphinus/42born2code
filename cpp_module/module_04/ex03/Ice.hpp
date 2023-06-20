#ifndef ICE_HPP
#define ICE_HPP

class Ice {
    public:
        Ice();
        Ice(const Ice &ice);
        Ice &operator=(const Ice &ice);
        ~Ice();
};

#endif
