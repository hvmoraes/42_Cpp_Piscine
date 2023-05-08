#include "DiamondTrap.hpp"

int main() {
	DiamondTrap jose("Jose");
	DiamondTrap antonio("Antonio");
	DiamondTrap alberto("Alberto");
	std::cout << std::endl;
	antonio.highFivesGuys();
	std::cout << std::endl;
	jose.attack("Antonio");
	antonio.takeDamage(20);
	std::cout << std::endl;
	jose.guardGate();
	std::cout << std::endl;
	jose.attack("Antonio");
	antonio.takeDamage(20);
	std::cout << std::endl;
	alberto.whoAmI();
	std::cout << std::endl;
	antonio.beRepaired(40);
	std::cout << std::endl;
	jose.attack("Antonio");
	antonio.takeDamage(20);
	std::cout << std::endl;
	jose.beRepaired(20);
	std::cout << std::endl;
}