#include "ClapTrap.hpp"

int main() {
	ClapTrap jose("Jose");
	ClapTrap antonio("Antonio");
	jose.attack("Antonio");
	antonio.takeDamage(5);
	jose.attack("Antonio");
	antonio.takeDamage(5);
	jose.attack("Antonio");
	antonio.takeDamage(5);
	jose.beRepaired(5);
}