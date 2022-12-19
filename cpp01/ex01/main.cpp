#include "Zombie.hpp"

int main (void)
{
	Zombie *coucou;
	Zombie *save;

	coucou = zombieHorde(50, "Foo");
	save = coucou;
	int i = 0;
	while (i < 5)
	{
		coucou->announce();
		coucou++;
		i++;
	}
	delete [] save;
}