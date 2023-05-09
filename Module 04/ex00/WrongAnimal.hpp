#pragma once

#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal();
		~WrongAnimal();
		void makeSound();
		std::string getType();
};