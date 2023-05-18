#include "../inc/MateriaSource.hpp"
#include "../inc/AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m materia source created\n";
	for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource const& copy)
{
	for (int i = 0; i < 4; i++)
	{
		// Deep copy!
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
	}
	std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m materia source created from copy\n";
}

MateriaSource& MateriaSource::operator=(MateriaSource const& copy)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = (copy._inventory[i])->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m materia source destoryed\n";
}

void MateriaSource::learnMateria(AMateria *materia)
{
	int i = 0;

	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m can't learn more than 4 Materias";
		return ;
	}
	(this->_inventory)[i] = materia;
	std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m materia " << materia->getType() << " learned\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_inventory)[i])
	{
		std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m " << type << " materia does not exit\n";
		return (NULL);
	}
	std::cout << "\033[38;2;244;164;96mMateria Source:\033[0m materia " << type << " created\n";
	return (((this->_inventory)[i])->clone());
}
