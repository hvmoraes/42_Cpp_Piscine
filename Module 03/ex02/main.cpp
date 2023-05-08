#include "FragTrap.hpp"

int main() {
	FragTrap jose("Jose");
	FragTrap antonio("Antonio");
	antonio.highFivesGuys();
	jose.attack("Antonio");
	antonio.takeDamage(20);
	jose.attack("Antonio");
	antonio.takeDamage(20);
	antonio.beRepaired(40);
	jose.attack("Antonio");
	antonio.takeDamage(20);
	jose.beRepaired(20);
}