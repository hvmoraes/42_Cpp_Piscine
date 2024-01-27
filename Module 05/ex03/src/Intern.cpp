#include "../inc/Intern.hpp"

Intern::Intern() {
	std::cout << "\033[32mIntern constructor called\033[0m" << std::endl;
}

Intern::~Intern() {
	std::cout << "\033[32mIntern destructor called\033[0m" << std::endl;
}

Intern::Intern(const Intern& copy) {
	std::cout << "\033[32mIntern copy constructor called\033[0m" << std::endl;
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
	std::cout << "\033[32mIntern assignment operator called\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) {
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "\033[32mIntern creates " << form << "\033[0m" << std::endl;
			return (all_forms[i](target));
		}
	}

	std::cout << "\033[32mIntern can not create a form called " << form << "\033[0m" << std::endl;
	return (NULL);
}