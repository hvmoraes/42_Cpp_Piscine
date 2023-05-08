#include "ScavTrap.hpp"

int main() {
	ScavTrap jose("Jose");
	ScavTrap antonio("Antonio");
	jose.guardGate();
	jose.attack("Antonio");
	antonio.takeDamage(20);
	jose.attack("Antonio");
	antonio.takeDamage(20);
	antonio.beRepaired(40);
	jose.attack("Antonio");
	antonio.takeDamage(20);
	jose.beRepaired(20);
}