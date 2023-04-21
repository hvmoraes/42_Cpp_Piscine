/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:50:41 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/04/21 10:57:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "phonebookMain.hpp"
#include "contact.hpp"

class Phonebook {
	public:
	  Phonebook();
		~Phonebook();

		void newContact(int i,  std::string firstName, std::string lastMame, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		Contact getContact(int i);
		std::string getFirstName(int i);
		std::string getLastName(int i);
		std::string getNickname(int i);
		std::string getPhoneNumber(int i);
		std::string getDarkestSecret(int i);
		
	private:
	  Contact contact[8];
};

#endif