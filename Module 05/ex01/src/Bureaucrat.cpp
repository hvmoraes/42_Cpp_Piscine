#include "../inc/Bureaucrat.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Adalberto"), grade(75) {
	std::cout << "\033[32m" << "Adalberto born with grade 75" << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->set_grade(grade);
	std::cout << "\033[32m" << this->get_name() << " born with grade " << this->get_grade() << "\033[0m" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "\033[32m" << this->get_name() << " killed, had grade " << get_grade() << "\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::cout << "\033[32m" << "Default copy constructor called" << "\033[0m" << std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << "\033[32m" << "Default assignment operator called" << "\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

int Bureaucrat::get_grade() const
{
	return this->grade;
}

void	Bureaucrat::increment_grade(int grade)
{
	std::cout << "\033[32m" << "Increment " << this->get_name() << "'s grade by " << grade << "\033[0m" << std::endl;
	this->set_grade(this->get_grade() - grade);
}

void	Bureaucrat::decrement_grade(int grade)
{
	std::cout << "\033[32m" << "Decrement " << this->get_name() << "'s grade by " << grade << "\033[0m" << std::endl;
	this->set_grade(this->get_grade() + grade);
}

void Bureaucrat::set_grade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

std::string Bureaucrat::get_name() const
{
	return this->name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("You are too fabulous, your grade is already at max!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("I'm sorry but you can't have a lower grade :(");
}

std::ostream &operator<<(std::ostream &op, Bureaucrat const *copy)
{
	op << copy->get_name() << ", grade " << copy->get_grade() << std::endl;
	return (op);
}
