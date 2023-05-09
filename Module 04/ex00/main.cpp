#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal* animal = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	
	delete(animal);
	delete(dog);
	delete(cat);
	delete(wrongAnimal);
	delete(wrongCat);
	return 0;
}