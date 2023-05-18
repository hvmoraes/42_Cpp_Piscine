#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "../inc/Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain *brain;
	protected:
		
	public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		void showIdeas();
		void makeSound();
};

#endif