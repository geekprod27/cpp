#include "Base.hpp"

int main()
{
	Base *b = generate();
	Base &i = *b;

	identify(b);
	identify(i);
	delete b;
}