#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _sign;
		const int _sign_grade;
		const int _exec_grade;
	protected:
		
	public:
		Form();
		~Form();
		Form(const Form& copy);
		Form(std::string name);
		Form(int sign_grade, int exec_grade);
		Form(std::string name, int sign_grade, int exec_grade);
		Form& operator=(const Form& copy);
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName()const;
		std::string getIsSigned()const;
		bool getIsSignedBool()const;
		int getSignGrade()const;
		int getExecGrade()const;
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream & operator<<( std::ostream &op, Form const *copy);

#endif