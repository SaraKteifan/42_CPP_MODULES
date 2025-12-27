#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("Sara");
    randomChump("Maha");
    zombie->announce();
    (*zombie).announce();
    delete zombie;
    return (0);
}