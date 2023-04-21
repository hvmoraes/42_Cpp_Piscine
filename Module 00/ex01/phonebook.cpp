/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:50:39 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/04/21 10:56:39 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebookMain.hpp"

Phonebook::Phonebook() {

}

Phonebook::~Phonebook() {
	
}

void	Phonebook::newContact(int i, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
	contact[i].setValues(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

Contact	Phonebook::getContact(int i) {
	return contact[i];
}

std::string Phonebook::getFirstName(int i) {
	return contact[i].getFirstName();
}

std::string Phonebook::getLastName(int i) {
  return contact[i].getLastName();
}

std::string Phonebook::getNickname(int i) {
  return contact[i].getNickname();
}

std::string Phonebook::getPhoneNumber(int i) {
  return contact[i].getPhoneNumber();
}

std::string Phonebook::getDarkestSecret(int i) {
  return contact[i].getDarkestSecret();
}
