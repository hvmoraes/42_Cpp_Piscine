#include "../inc/Dog.hpp"

Dog::Dog() {
	std::cout << "\033[0;33mDog:\033[0m " << "Dog created!" << std::endl;
	this->_type = "Dog";
	
	std::string dogIdeas[10] = {
		"Fetch time! Ball, go!", "Squirrels beware, I'm coming!",
		"Treats, please, now!", "Grass, paws, zoom!",
		"Homecoming = wagging tail!", "New toy, playtime, chew!",
		"Belly rubs = pure bliss!", "Walk time, sniff, mark.",
		"Puddle fun, splash, joy!", "Blanket snuggles, snooze mode."
	};
	std::string ideas[100];
	std::srand(std::time(0));
	for (int i = 0; i < 100; i++) {
    std::string randomIdea = dogIdeas[std::rand() % 10];
		ideas[i] = randomIdea;
	}
	this->brain = new Brain(ideas);
}

Dog::~Dog() {
	std::cout << "\033[0;33mDog:\033[0m " << "Dog deleted!" << std::endl;
	delete(this->brain);
}

Dog::Dog(const Dog& copy) {
	this->_type = copy._type;
	this->brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog& copy) {
	if (this == &copy) {
		return *this;
	}
	
	this->_type = copy._type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	
	return *this;
}

void Dog::showIdeas() {
	std::cout << "\033[0;33mDog:\033[0m My ideas below" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << this->brain->ideas[i];
		if (i != 99) std::cout << " | ";
	}
	std::cout << std::endl;
}
