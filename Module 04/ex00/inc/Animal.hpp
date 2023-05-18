#pragma once

#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		~Animal();
		void makeSound();
		std::string getType();
};