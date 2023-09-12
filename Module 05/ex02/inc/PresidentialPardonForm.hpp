#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	protected:
		
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &op, PresidentialPardonForm *form);