#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

void Leaks(void)
{
    system("leaks brain");
}

int main ( void )
{
     atexit(Leaks);
    Animal *_Animal  = new Animal[5];
    for (int i = 0 ; i < 5 ; i++)
    {
        if (!(i % 2))
            _Animal[i] = Cat();
        else
            _Animal[i] = Dog();
    }
    for (int i = 0; i < 5; i++)
        std::cout << "Animal type : " << _Animal[i].getType() << std::endl;
    return (delete[] _Animal, 0);
}
