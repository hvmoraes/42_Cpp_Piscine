#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "\033[31mRobotomyRequestForm constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\033[31mRobotomyRequestForm destructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) {
	std::cout << "\033[31mRobotomyRequestForm copy constructor called\033[0m" << std::endl;
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << "\033[31mRobotomyRequestForm assignment operator called\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

static int count = 0;

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	if (count++ % 2)
		std::cout << "\033[31m" << this->getTarget() << " has been successfully robotomized\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Robotomy for " << this->getTarget() << " failed\033[0m" << std::endl;
}