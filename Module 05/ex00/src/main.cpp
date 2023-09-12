/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:42 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 13:05:56 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main(int argc, char **argv)
{
	Bureaucrat *test = NULL;
	if (argc == 3)
	{
		try
		{
			test = new Bureaucrat(argv[1], atoi(argv[2]));
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << argv[1] << " can't be created with more than 150 of atribute grade!" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << argv[1] << " can't be created with less than 0 of atribute grade!" << std::endl;
		}
	}
	else
	{
		std::string name;
		int	grade;
		std::cout << "Please specify a name: ";
		std::cin >> name;
		std::cout << "Please specify " << name << "'s grade: ";
		std::cin >> grade;
		try
		{
			test = new Bureaucrat(name, grade);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << name << " can't be created with more than 150 of atribute grade!" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << name << " can't be created with less than 0 of atribute grade!" << std::endl;
		}
	}
	if (test)
	{
		try
		{
			test->increment_grade(50);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << test;
		try
		{
			test->decrement_grade(100);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << test;
		delete(test);
	}
}
