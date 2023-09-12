#include "../inc/Form.hpp"

Form::Form() : _name("Adalberto"), _sign(false), _sign_grade(50), _exec_grade(50) {
	std::cout << "\033[34m" << "Form created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

Form::~Form() {
	std::cout << "\033[34m" << "Form destructed for " << this->_name << "\033[0m" << std::endl;
}

Form::Form(const Form& copy) : _name(copy.getName()), _sign(copy.getIsSignedBool()), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade()) {
	std::cout << "\033[34m" << copy._name << " copied into " << this->_name << "\033[0m" << std::endl;
	*this = copy;
}

Form::Form(std::string name) : _name(name), _sign(false), _sign_grade(50), _exec_grade(50) {
	std::cout << "\033[34m" << "Form created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

Form::Form(int sign_grade, int exec_grade) : _name("Alberto"), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 0 || exec_grade < 0)
		throw GradeTooHighException();
	else
		std::cout << "\033[34m" << "Form created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 0 || exec_grade < 0)
		throw GradeTooHighException();
	else
		std::cout << "\033[34m" << "Form created for " << this->_name << " with sign grade " << this->_sign_grade << " and execution grade " << this->_exec_grade << "\033[0m" << std::endl;
}

Form& Form::operator=(const Form& copy) {
	std::cout << "\033[34m" << "Default assignment operator called" << "\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.get_grade() <= this->getSignGrade() && this->_sign == false)
	{
		std::cout << "\033[34m" << "Bureaucrat " << bureaucrat.get_name() << " signed Form " << this->getName() << " with grade " << bureaucrat.get_grade() << "\033[0m" << std::endl;;
		this->_sign = true;
	}
	else if (this->_sign == true)
		std::cout << "\033[34m" << "Form for " << this->getName() << " is already signed!" << std::endl;
	else
		std::cout << "\033[34m" << this->getName() << ": Grade " << bureaucrat.get_grade() << " is not enough to sign Form!" << std::endl << "Need " << this->getSignGrade() << " or better grade" << "\033[0m" << std::endl; 
}

std::string Form::getName()const {
	return (this->_name);
}

std::string Form::getIsSigned()const {
	if (this->_sign == false)
		return ("❌ False");
	return ("✅ True");
}

bool Form::getIsSignedBool()const {
	return (this->_sign);
}

int Form::getSignGrade()const {
	return (this->_sign_grade);
}

int Form::getExecGrade()const {
	return (this->_exec_grade);
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("I'm sorry but you can't have a lower grade :(");
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("You are too fabulous, your grade is already at max!");
}

std::ostream &operator<<(std::ostream &op, Form const *copy) {
	op << "Form for " << copy->getName() << std::endl << "Signed: " << copy->getIsSigned() << std::endl << "Sign grade: " << copy->getSignGrade() << std::endl << "Execution grade: " << copy->getExecGrade() << std::endl;
	return (op);
}
