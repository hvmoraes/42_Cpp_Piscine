/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebookMain.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:15:56 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/04/21 16:58:51 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookMain.hpp"

bool isPhoneNumberValid(const std::string& phoneNumber) {
  for (std::string::const_iterator it = phoneNumber.begin(); it != phoneNumber.end(); ++it) {
    if (!std::isdigit(*it)) {
      return false;
    }
  }
  return true;
}

void addContact(Phonebook *phonebook, int i) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	input;
	
	int index;
	if (i < 8) {
		index = i;
		std::cout << "Saving new Contact's info in Phonebook's index " << index + 1 << std::endl;
	}
	else {
	  index = 7;
		std::cout << "Becase the Phonebook is full, replacing Phonebook's index " << index + 1 << " (name: " << (*phonebook).getFirstName(7) << " " << (*phonebook).getLastName(7) << ") with new Contact's info" << std::endl;
	}
	
	std::cout << "Please enter your first name: ";
	std::getline(std::cin, firstName);
	while(firstName.empty() || firstName.find_first_of(" ") != std::string::npos || firstName.find_first_of("\t") != std::string::npos) {
		std::cout << "Field {first name} cannot be empty or contain any spaces or tabs: ";
  	std::getline(std::cin, firstName);
	}
		
	std::cout << "Please enter your last name: ";
  std::getline(std::cin, lastName);
	while(lastName.empty() || lastName.find_first_of(" ") != std::string::npos || lastName.find_first_of("\t") != std::string::npos) {
		std::cout << "Field {last name} cannot be empty or contain any spaces or tabs: ";
  	std::getline(std::cin, lastName);
	}

	std::cout << "Please enter your nickname: ";
  std::getline(std::cin, nickname);
	while(nickname.empty()) {
		std::cout << "Field {nickname} cannot be empty: ";
  	std::getline(std::cin, nickname);
	}
		
	std::cout << "Please enter your phone number: ";
  std::getline(std::cin, phoneNumber);
	while(!isPhoneNumberValid(phoneNumber) || phoneNumber.empty()) {
		if (!isPhoneNumberValid(phoneNumber)) {
			std::cout << "Please insert a valid number: ";
  		std::getline(std::cin, phoneNumber);
		}
		if (phoneNumber.empty()) {
			std::cout << "Field {phone number} cannot be empty: ";
  		std::getline(std::cin, phoneNumber);
		}
	}
	
	std::cout << "Please enter your darkest secret: ";
  std::getline(std::cin, darkestSecret);
	while(darkestSecret.empty()) {
		std::cout << "Field {darkest secret} cannot be empty: ";
  	std::getline(std::cin, darkestSecret);
	}
	
	(*phonebook).newContact(index, firstName, lastName, nickname, phoneNumber, darkestSecret);
	
	std::cout << "Contact added successfully! Press ENTER to continue...";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
}

int showList (Phonebook *phonebook, int i, bool ignore) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	userIndex;

	system("clear");
	
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int j = 1; j < i + 1; j++) {
		firstName = (*phonebook).getFirstName(j - 1);
		lastName = (*phonebook).getLastName(j - 1);
		nickname = (*phonebook).getNickname(j - 1);
		if (firstName.length() >= 10) {
			firstName.resize(9);
			firstName.resize(10, '.');
		}
		if (lastName.length() >= 10) {
      lastName.resize(9);
      lastName.resize(10, '.');
    }
		if (nickname.length() >= 10) {
      nickname.resize(9);
      nickname.resize(10, '.');
    }
		std::cout << "|" << std::setw(10) << j << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickname << "|" << std::endl;
	}

	if (!ignore)
		std::cout << std::endl;
			
	if ((*phonebook).getFirstName(0).empty()) {
  	while (!(strcmp(userIndex.c_str(), "menu") == 0)) {
			std::cout << "List is empty, get back to main menu (with {menu} command) to add a new Contact: ";
			std::getline(std::cin, userIndex);
		}
		return 0;
	} else {
		std::cout << std::endl << "KO Please enter the contact's index to see more information or {menu} to get back to the main menu: ";
		std::getline(std::cin, userIndex);
			
		while(userIndex.empty()) {
			std::cout << "WTF Please enter the contact's index to see more information or {menu} to get back to the main menu: ";
			std::getline(std::cin, userIndex);
		}
		if (strcmp(userIndex.c_str(), "menu") == 0)
			return 0;
		
		int index;
		std::istringstream(userIndex) >> index;
		while (!index || index < 1 || index > i + 1) {
			std::cout << "OK Please enter the contact's index to see more information or {menu} to get back to the main menu: ";
			std::getline(std::cin, userIndex);
			if (strcmp(userIndex.c_str(), "menu") == 0)
				return 0;
			std::istringstream(userIndex) >> index;
		}
		if (strcmp(userIndex.c_str(), "menu") == 0)
			return 0;
		
		system("clear");
		(*phonebook).getContact(index - 1).print();
	}

	return 1;
}

void search(Phonebook *phonebook, int i) {
	std::string userIndex;
	
	while (1) {
		if (showList(phonebook, i, false) == 0)
			return;
		else {
			std::cout << "Please enter {menu} to get back to the main menu or {list} to get back to the contacts' list: ";
			std::getline(std::cin, userIndex);
			while ((!(strcmp(userIndex.c_str(), "menu") == 0) && !(strcmp(userIndex.c_str(), "list") == 0)) || (userIndex.empty())) {
				std::cout << "Please enter {menu} to get back to the main menu or {list} to get back to the contacts' list: ";
				std::getline(std::cin, userIndex);
			}
			if (strcmp(userIndex.c_str(), "menu") == 0)
				return;
			else if (strcmp(userIndex.c_str(), "list") == 0)
				if (showList(phonebook, i, true) == 0)
					return;
		}
	}
}

int main () {
	Phonebook phonebook;
	std::string cmd;
	int i = 0;
	
	while (1)
	{
		system("clear");
		std::cout << "Please enter one of this commands: ADD, SEARCH or EXIT: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			continue;
		if (strcmp(cmd.c_str(), "EXIT") == 0) {
			system("clear");
			return (0);
		}
		else if (strcmp(cmd.c_str(), "ADD") == 0) {
			addContact(&phonebook, i);
			i++;
		}
		else if (strcmp(cmd.c_str(), "SEARCH") == 0) {
			if (i < 8)
				search(&phonebook, i);
			else
				search(&phonebook, 8);
		}
	}
	
	return (0);
}
