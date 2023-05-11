#include "data.hpp"
#include <iostream>

int main()
{
	data dat;

	dat.d = 'c';
	dat.coucou = &dat.d;
	dat.cos = 42;


	std::cout << "dat.d : " << dat.d << " dat.coucou : " << dat.coucou << " dat.cos : " << dat.cos << std::endl;

	uintptr_t tmp = serialize(&dat);

	data *out = deserialize(tmp);

	std::cout << "out.d : " << out->d << " out.coucou : " << out->coucou << " out.cos : " << out->cos << std::endl;
}