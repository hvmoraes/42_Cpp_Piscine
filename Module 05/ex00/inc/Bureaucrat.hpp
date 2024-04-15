#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdlib.h>

class Bureaucrat {
	private:
		const	std::string name;
		int grade;
		void	set_grade(int grade);
	protected:
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		int		get_grade() const;
		void	increment_grade(int grade);
		void	decrement_grade(int grade);
		std::string get_name() const;
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream & operator<<( std::ostream &op, Bureaucrat const *copy);

#endif