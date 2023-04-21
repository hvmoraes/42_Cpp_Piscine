/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:50:43 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/04/21 11:56:48 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookMain.hpp"

Contact::Contact() {
	
}

Contact::~Contact() {
	
}

void Contact::print() {
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl << std::endl;
}

void Contact::setValues(std::string firstName, std::string last_name, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
	_firstName = firstName;
	_lastName = last_name;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return this->_firstName;
}

std::string Contact::getLastName() {
  return this->_lastName;
}

std::string Contact::getNickname() {
  return this->_nickname;
}

std::string Contact::getPhoneNumber() {
  return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() {
  return this->_darkestSecret;
}
