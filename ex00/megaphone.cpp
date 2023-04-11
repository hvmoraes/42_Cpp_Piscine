/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:11:10 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/04/11 14:11:11 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				if ((argv[i][j] >= 'a' && argv[i][j] <= 'z')
					|| (argv[i][j] >= 'A' && argv[i][j] <= 'Z'))
					std::cout << char(toupper(argv[i][j]));
				else
					std::cout << argv[i][j];
			}
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	return (0);
}
