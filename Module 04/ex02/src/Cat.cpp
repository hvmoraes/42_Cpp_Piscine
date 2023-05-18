#include "../inc/Cat.hpp"

Cat::Cat() {
	std::cout << "\033[38;2;70;130;180mCat: \033[0m" << "Cat created!" << std::endl;
	this->_type = "Cat";

	std::string catIdeas[10] = {
			"Purrfect Hideout", "Chasing Shadows",
			"Tempting Treat Dispenser", "Whisker Tickler",
			"Catnip Bliss", "Smart Interactive Toy",
			"Luxurious Lounger", "Interactive Puzzle Feeder",
			"Feathered Friends", "Scratchy Paradise"
		}; 
	std::string ideas[100];
	std::srand(std::time(0));
	for (int i = 0; i < 100; i++) {
    std::string randomIdea = catIdeas[std::rand() % 10];
		ideas[i] = randomIdea;
	}
	this->brain = new Brain(ideas);
}

Cat::~Cat() {
	std::cout << "\033[38;2;70;130;180mCat: \033[0m" << "Cat deleted!" << std::endl;
	delete(this->brain);
}

Cat::Cat(const Cat& copy) {
	this->_type = copy._type;
	this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& copy) {
	if (this == &copy) {
		return *this;
	}
	
	this->_type = copy._type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	
	return *this;
}

void Cat::showIdeas() {
	std::cout << "\033[38;2;70;130;180mCat:\033[0m My ideas below" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << this->brain->ideas[i];
		if (i != 99) std::cout << " | ";
	}
	std::cout << std::endl;
}

void Cat::makeSound() {
	std::cout << "\033[38;2;70;130;180mCat:\033[0m " << "Miau" << std::endl;
}
