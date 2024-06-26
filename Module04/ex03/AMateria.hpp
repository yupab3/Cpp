#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	type;
public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria &_AMateria);
	virtual ~AMateria(void);
	AMateria&	operator=(const AMateria &_AMateria);

	std::string const & getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif
