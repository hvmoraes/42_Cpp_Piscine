#include "../inc/AForm.hpp"

AForm::AForm() : _name("Adalberto"), _sign(false), _sign_grade(50), _exec_grade(50) {
	std::cout << "\033[34m" << "AForm created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

AForm::~AForm() {
	std::cout << "\033[34m" << "AForm destructed for " << this->_name << "\033[0m" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _sign(copy.getIsSignedBool()), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade()) {
	std::cout << "\033[34m" << copy._name << " copied into " << this->_name << "\033[0m" << std::endl;
	*this = copy;
}

AForm::AForm(std::string name) : _name(name), _sign(false), _sign_grade(50), _exec_grade(50) {
	std::cout << "\033[34m" << "AForm created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

AForm::AForm(int sign_grade, int exec_grade) : _name("Alberto"), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 0 || exec_grade < 0)
		throw GradeTooHighException();
	else
		std::cout << "\033[34m" << "AForm created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 0 || exec_grade < 0)
		throw GradeTooHighException();
	else
		std::cout << "\033[34m" << "AForm created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

AForm& AForm::operator=(const AForm& copy) {
	std::cout << "\033[34m" << "Default assignment operator called" << "\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.get_grade() <= this->getSignGrade() && this->_sign == false)
	{
		std::cout << "\033[34m" << "Bureaucrat " << bureaucrat.get_name() << " signed AForm " << this->getName() << " with grade " << bureaucrat.get_grade() << "\033[0m" << std::endl;;
		this->_sign = true;
	}
	else if (this->_sign == true)
		std::cout << "\033[34m" << "AForm for " << this->getName() << " is already signed!" << std::endl;
	else
		std::cout << "\033[34m" << this->getName() << ": Grade " << bureaucrat.get_grade() << " is not enough to sign AForm!" << std::endl << "Need " << this->getSignGrade() << " or better grade" << "\033[0m" << std::endl; 
}

std::string AForm::getName()const {
	return (this->_name);
}

std::string AForm::getIsSigned()const {
	if (this->_sign == false)
		return ("❌ False");
	return ("✅ True");
}

bool AForm::getIsSignedBool()const {
	return (this->_sign);
}

int AForm::getSignGrade()const {
	return (this->_sign_grade);
}

int AForm::getExecGrade()const {
	return (this->_exec_grade);
}

void AForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSignedBool() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.get_grade() > this->getExecGrade())
		throw(Bureaucrat::GradeTooLowException());
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("\033[34mI'm sorry but you can't have a lower grade :(\033[0m");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("\033[34mYou are too fabulous, your grade is already at max!\033[0m");
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return ("\033[34mForm needs to be signed before executing\033[0m");
}

std::ostream &operator<<(std::ostream &op, AForm const *copy) {
	op << "\033[34mAForm for " << copy->getName() << std::endl << "Signed: " << copy->getIsSigned() << std::endl << "Sign grade: " << copy->getSignGrade() << std::endl << "Execution grade: " << copy->getExecGrade() << "\033[0m" << std::endl;
	return (op);
}