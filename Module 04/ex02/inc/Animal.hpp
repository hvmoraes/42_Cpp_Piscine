#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include "Brain.hpp"

class Animal {
	private:
		
	protected:
		std::string _type;
		Animal();
	public:
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual void makeSound();
		std::string getType();
		virtual void showIdeas();
};

#endif