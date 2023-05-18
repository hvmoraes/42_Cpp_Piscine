#include "../inc/Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal *animal[10];
	Animal *defaultAnimal = new Animal();

	for (int i = 0; i < 5; i++) {
		animal[i] = new Dog();
	}

	defaultAnimal->makeSound();
	defaultAnimal->showIdeas();

	for (int i = 5; i < 10; i++) {
		animal[i] = new Cat();
	}

	animal[4]->showIdeas();

	animal[4]->makeSound();
	animal[5]->makeSound();

	animal[5]->showIdeas();

	for (int i = 0; i < 10; i++) {
		delete(animal[i]);
	}

	delete(defaultAnimal);

	return 0;
}