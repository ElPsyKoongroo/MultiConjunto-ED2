#include <iostream>
#include "../inc/multiconjunto.h"
#include "../inc/Persona.h"
#include "multiconjunto.cpp"

int main()
{
    Multiconjunto<int> m1 = Multiconjunto<int>();
    Multiconjunto<char> m2 = Multiconjunto<char>();

    for (int i = 1; i < 20; i++)
    {
        std::cout << m1.cardinalidad() << std::endl;
        m1.anade(i);
    }

    std::cout << m1.cardinalidad() << std::endl;

    for(int i = 0; i < 20; i++)
    {
        m1.elimina(i);
        std::cout << "Quedan: " << m1.cardinalidad() << std::endl;
    }
    for(int i = 0; i < m1.cardinalidad(); i+=3)
    {
        std::cout << "El elemento (" << i << ")" << (m1.pertenece(i)? " ":" no") << "pertenece al conjunto" << std::endl;
    }
    int x;
    std::cin >> x;
    return 0;
}