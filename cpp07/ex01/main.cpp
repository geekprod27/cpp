#include "iter.hpp"

int main()
{
	int		tab[10];

	for (int i = 0; i < 10; i++)
		tab[i] = i;

	iter(tab, 10, print);

	float		tabd[30];

	for (int i = 0; i < 30; i++)
		tabd[i] = i + 42;

	iter(tabd, 30, print);
}