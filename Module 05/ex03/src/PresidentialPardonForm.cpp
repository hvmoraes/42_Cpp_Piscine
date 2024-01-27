#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "\033[35mPresidentialPardonForm constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\033[35mPresidentialPardonForm destructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) {
	std::cout << "\033[35mPresidentialPardonForm copy constructor called\033[0m" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	std::cout << "\033[35mPresidentialPardonForm assignment operator called\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << "\033[35m" << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
}