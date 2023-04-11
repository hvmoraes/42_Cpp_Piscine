/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:15:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/04/11 17:32:26 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class Contact
{
	public:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	int phone_number;
	std::string darkest_secret;
};

class PhoneBook
{
	public:
	int index;
	Contact *contact[8];
	std::string cmd;
	void exec_cmd(PhoneBook *phonebook);
	void add_contact(PhoneBook *phonebook, int i);
};

void PhoneBook::add_contact(PhoneBook *phonebook, int i)
{
	if (i < 8)
	{
		phonebook->contact[i]->index = i;
		std::cout << phonebook->contact[i]->index;
	}
	else
	{
		phonebook->contact[7]->index = 7;
		std::cout << phonebook->contact[7]->index;
	}
	return ;
}

void PhoneBook::exec_cmd(PhoneBook *phonebook)
{
	if (strcmp((phonebook->cmd).c_str(), "ADD") == 0)
	{
		phonebook->add_contact(phonebook, phonebook->index);
	}
	else if (strcmp((phonebook->cmd).c_str(), "SEARCH") == 0)
	{
		
	}
	else
		return;
}

int main ()
{
	PhoneBook *phonebook;
	phonebook->index = 0;
	while (1)
	{
		std::cout << "Please enter one of this commands: ADD, SEARCH or EXIT: ";
		std::cin >>  phonebook->cmd;
		if (strcmp((phonebook->cmd).c_str(), "EXIT") == 0)
			break;
		phonebook->exec_cmd(phonebook);
		phonebook->index++;
	}
}
