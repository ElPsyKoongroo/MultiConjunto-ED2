#include <iostream>
#include "inc/multiconjunto.h"
#include "inc/Persona.h"

int main()
{
    Multiconjunto<int> m1;
    Multiconjunto<char> m2;

    for (int i = 0; i < 30; i++)
    {
        m1.anade(i);
    }
    for(char i = 'a'; i < 'z'; i++)
    {
        m2.anade(i);
    }

    for(int i = 0; i < 30; i+=4)
    {
        m1.elimina(i);
        std::cout << "Quedan: " << m1.cardinalidad() << std::endl;
    }
    for(int i = 0; i < m1.cardinalidad(); i+=3)
    {
        std::cout << "El elemento (" << i << ")" << (m1.pertenece(i)? " ":" no") << "pertenece al conjunto" << std::endl;
    }
}