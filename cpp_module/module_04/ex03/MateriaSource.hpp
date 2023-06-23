#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria *source;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &materiaSource);
        MateriaSource &operator=(const MateriaSource &materiaSource);
        ~MateriaSource();

        AMateria *getSource() const;
        void setSource(AMateria *m);
        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
};

#endif
