#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "\033[33mShrubberyCreationForm constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\033[33mShrubberyCreationForm destructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) {
	std::cout << "\033[33mShrubberyCreationForm copy constructor called\033[0m" << std::endl;
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	std::cout << "\033[33mShrubberyCreationForm assignment operator called\033[0m" << std::endl;
	(void)copy;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::string filename = this->getTarget().append("_shrubbery").c_str();
	std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());
	outfile <<
  "      /\\      " << std::endl <<
  "     /  \\     " << std::endl <<
  "    /    \\    " << std::endl <<
  "   /      \\   " << std::endl <<
  "  /________\\  " << std::endl <<
  "     ||||      " << std::endl <<
	std::endl <<
  "    ^^^    " << std::endl <<
  "   ^^^^^   " << std::endl <<
  "  ^^^^^^^  " << std::endl <<
  " ^^^^^^^^^ " << std::endl <<
  "    ||||    " << std::endl <<
	std::endl <<
  "    /\\  " << std::endl <<
  "   /  \\ " << std::endl <<
  "  /____\\ " << std::endl <<
  "    ||    " << std::endl <<
	std::endl <<
  "    *   " << std::endl <<
  "   ***  " << std::endl <<
  "  ***** " << std::endl <<
  "   ||   " << std::endl <<
	std::endl <<
  "    ++   " << std::endl <<
  "   ++++  " << std::endl <<
  "  ++++++ " << std::endl <<
  "    ||   " << std::endl;
	outfile.close();
	std::cout << "\033[33mSuccessfully wrote an ASCII forest inside " << filename << "\033[0m" << std::endl;
}