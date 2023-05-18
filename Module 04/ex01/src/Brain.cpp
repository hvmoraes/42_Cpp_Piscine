#include "../inc/Brain.hpp"

Brain::Brain(std::string ideas[100]) {
	std::cout << "\033[95mBrain:\033[0m " << "Brain created!" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = ideas[i];
	}
}

Brain::Brain() {
	std::cout << "\033[95mBrain:\033[0m " << "Brain created!" << std::endl;
}

Brain::~Brain() {
	std::cout << "\033[95mBrain:\033[0m " << "Brain deleted!" << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Default assignment operator called" << std::endl;
	(void)copy;
	return(*this);
}

