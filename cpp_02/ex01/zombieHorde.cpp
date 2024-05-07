#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	(void)name;
	Zombie* horde = new Zombie[N];

	// for (int i = 0; i < N; ++i) {
	// 	horde[i] = Zombie();
	// }
	return horde;
}
