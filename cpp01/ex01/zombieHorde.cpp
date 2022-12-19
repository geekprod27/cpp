#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*zom = new Zombie[N];
	Zombie	*deb = zom;
	int i = 0;

	while(i < N)
	{
		zom->setName(name);
		zom++;
		i++;
	}
	return (deb);
}