/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:42 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/01/27 14:03:39 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

int	main()
{
	Bureaucrat bur1 = Bureaucrat("Jose", 100);
	Bureaucrat bur2 = Bureaucrat();
	Bureaucrat bur3 = Bureaucrat("Antonio", 140);
	Bureaucrat bur4 = Bureaucrat("Junior", 10);
	Form form1 = Form("Jose");
	Form form2 = Form();
	Form form3 = Form("Antonio", 145, 145);
	Form form4 = Form("Junior", 20, 20);

	
	form1.beSigned(bur1);
	std::cout << "Form1 signed: " + form1.getIsSigned() << std::endl;
	form2.beSigned(bur2);
	form3.beSigned(bur3);
	std::cout << "Form1 signed: " + form3.getIsSigned() << std::endl;
	form3.beSigned(bur3);
	form4.beSigned(bur4);
}