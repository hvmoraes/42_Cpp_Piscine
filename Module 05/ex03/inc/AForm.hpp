#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		
	protected:
		const std::string _name;
		bool _sign;
		const int _sign_grade;
		const int _exec_grade;
		AForm();
		AForm(std::string name);
		AForm(int sign_grade, int exec_grade);
		AForm(std::string name, int sign_grade, int exec_grade);
	public:
		virtual ~AForm();
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		void beSigned(Bureaucrat &bureaucrat);
		std::string getName()const;
		std::string getIsSigned()const;
		bool getIsSignedBool()const;
		int getSignGrade()const;
		int getExecGrade()const;
		virtual void execute(Bureaucrat const & executor) const;
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

		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream & operator<<( std::ostream &op, AForm const *copy);