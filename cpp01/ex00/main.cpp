#include "Zombie.hpp"

int main (void)
{
	Zombie *coucou;

	coucou = newZombie("Foo");
	coucou->announce();
	delete coucou;

	randomChump("Boo");
}