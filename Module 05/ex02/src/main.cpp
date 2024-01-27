/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:31:22 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/27 14:03:12 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat *alfred = new Bureaucrat("alfred", 78);
	AForm	*president_alfred = new PresidentialPardonForm("president");
	AForm *robotomy_alfred = new RobotomyRequestForm("robotomy");
	AForm *shrubbery_alfred = new ShrubberyCreationForm("shrubbery");
	
	alfred->increment_grade(40);
	
	try	{
		alfred->decrement_grade(200);
	}
	catch(Bureaucrat::GradeTooLowException &error) {
		std::cout << error.what() << std::endl;
	}
	
	std::cout << president_alfred;
	try {
		president_alfred->execute(*alfred);
	}
	catch (AForm::FormNotSignedException &error) {
		std::cout << error.what() << std::endl;
	}
	
	alfred->increment_grade(18);
	president_alfred->beSigned(*alfred);
	
	try {
		president_alfred->execute(*alfred);
	}
	catch (Bureaucrat::GradeTooLowException &error) {
		std::cout << "Grade " << alfred->get_grade() << " is too low, need " << president_alfred->getExecGrade() << " or less" << std::endl;
	}
	
	alfred->increment_grade(17);
	president_alfred->execute(*alfred);

	alfred->decrement_grade(70);
	robotomy_alfred->beSigned(*alfred);
	alfred->increment_grade(5);
	robotomy_alfred->beSigned(*alfred);
	try {
		president_alfred->execute(*alfred);
	}
	catch (Bureaucrat::GradeTooLowException &error) {
		std::cout << "Grade " << alfred->get_grade() << " is too low, need " << robotomy_alfred->getExecGrade() << " or less" << std::endl;
	}
	alfred->increment_grade(30);
	robotomy_alfred->execute(*alfred);
	robotomy_alfred->execute(*alfred);
	robotomy_alfred->execute(*alfred);
	shrubbery_alfred->beSigned(*alfred);
	shrubbery_alfred->execute(*alfred);
	
	std::cout << alfred;
	std::cout << robotomy_alfred;
	alfred->decrement_grade(10);
	std::cout << alfred;
	alfred->executeForm(*robotomy_alfred);

	std::cout << president_alfred;
	std::cout << robotomy_alfred;
	std::cout << alfred;
	
	delete(alfred);
	delete(president_alfred);
	delete(robotomy_alfred);
	delete(shrubbery_alfred);
}