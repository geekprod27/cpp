#include "data.hpp"

uintptr_t serialize(data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<data *>(raw));
}