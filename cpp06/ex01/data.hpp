#ifndef DATA_HPP
# define DATA_HPP

#include <stdint.h>

typedef struct s_data
{
	char			*coucou;
	int				cos;
	char			d;
} data;

uintptr_t serialize(data* ptr);
data* deserialize(uintptr_t raw);

#endif