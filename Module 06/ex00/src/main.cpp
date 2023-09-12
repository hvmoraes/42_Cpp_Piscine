/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:54:48 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/09/05 18:12:24 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "Invalid number of arguments!" << std::endl;
	else {
		ScalarConverter convert;
		try {
			convert.convert(argv[1]);
			convert.printOutput();
		}
		catch (const ScalarConverter::ErrorException& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
