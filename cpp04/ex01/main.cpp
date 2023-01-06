#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int size = 10;
	Animal *tab[size];

	for (int i = 0; i < size / 2; i++)
		tab[i] = new Dog();
	for (int i = 0; i < size / 2; i++)
		tab[i + (size / 2)] = new Cat();
	


	for (int i = 0; i < size; i++)
		delete tab[i];
}