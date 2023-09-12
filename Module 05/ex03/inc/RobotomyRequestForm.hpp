#pragma once

#include <fstream>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	protected:
		
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &op, RobotomyRequestForm *form);