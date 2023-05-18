#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include "Brain.hpp"

class Animal {
	private:
		
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		void makeSound();
		std::string getType();
		virtual void showIdeas();
};

#endif