#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	bob = Zombie(name);
	
	bob.announce();
}