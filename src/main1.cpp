#include <iostream>
#include "../inc/multiconjunto.h"
#include "../inc/Persona.h"
#include "multiconjunto.cpp"

int main()
{
    Multiconjunto<int> m1 = Multiconjunto<int>();
    Multiconjunto<char> m2 = Multiconjunto<char>();

    std::cout << "\nPrueba M1, INT\n\n";

#pragma region M1
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
#pragma endregion

    std::cout << "\n\nPrueba M2, CHAR\n\n";

#pragma region M2
    for (int i = 1; i < 20; i++)
    {
        std::cout << m2.cardinalidad() << std::endl;
        m2.anade(i);
    }

    std::cout << m2.cardinalidad() << std::endl;

    for(int i = 0; i < 20; i++)
    {
        m2.elimina(i);
        std::cout << "Quedan: " << m2.cardinalidad() << std::endl;
    }
    for(int i = 0; i < m2.cardinalidad(); i+=3)
    {
        std::cout << "El elemento (" << i << ")" << (m2.pertenece(i)? " ":" no") << "pertenece al conjunto" << std::endl;
    }
#pragma endregion

    std::cout << "\n\nPrueba 3, PERSONA\n\n";

#pragma region M3
    Multiconjunto<Persona> m3 = Multiconjunto<Persona>();

    std::string nombres[] = {"Adrian", "Sergio", "Eddie"};

    Persona p1 = Persona(nombres[0], 20);
    Persona p2 = Persona(nombres[1], 19);
    Persona p3 = Persona(nombres[2], 21);

    m3.anade(p1);
    m3.anade(p2);
    m3.anade(p3);

    std::cout << m3.cardinalidad() << std::endl;

    m3.elimina(p1);

    std::cout << m3.cardinalidad() << std::endl;

    std::cout << (m3.pertenece(p1)? "":"no ") << "pertenece al conjunto" << std::endl;

    std::cout << (m3.pertenece(p2)? "":"no ") << "pertenece al conjunto" << std::endl;

#pragma endregion

    system("pause");
    return 0;
}