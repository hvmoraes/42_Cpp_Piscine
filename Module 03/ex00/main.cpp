#include "ClapTrap.hpp"

int main() {
	ClapTrap jose("Jose");
	ClapTrap antonio("Antonio");
	jose.attack("Antonio");
	antonio.takeDamage(0);
	jose.attack("Antonio");
	antonio.takeDamage(0);
	jose.attack("Antonio");
	antonio.takeDamage(0);
	jose.beRepaired(5);
}