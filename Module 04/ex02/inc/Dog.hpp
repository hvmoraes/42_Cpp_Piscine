#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "../inc/Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain *brain;
	protected:
		
	public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		void showIdeas();
		void makeSound();
};

#endif