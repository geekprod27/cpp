#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:

		ScavTrap();
		ScavTrap( std::string named );
		ScavTrap( ScavTrap const & src );
		~ScavTrap();

		ScavTrap &		operator=( ScavTrap const & rhs );
		
		void	attack(const std::string& target);
		void 	guardGate( void );
};

#endif /* ******************************************************** SCAVTRAP_H */