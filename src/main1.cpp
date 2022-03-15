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
        std::cout << "Se incluye: " << i << std::endl;
        m1.anade(i);
        std::cout << "Hay " << m1.cardinalidad() << " elementos" << std::endl;
    }

    std::cout << "En total al final hay: " << m1.cardinalidad() << " elementos" << std::endl;

    for(int i = 0; i < m1.cardinalidad()+10; i+=3)
    {
        std::cout << "El elemento (" << i << ")" << (m1.pertenece(i)? " ":" no ") << "pertenece al conjunto" << std::endl;
    }

    for(int i = 0; i < 20; i++)
    {
        std::cout << "Se elimina: " << i << std::endl;
        m1.elimina(i);
        std::cout << "Quedan: " << m1.cardinalidad() << std::endl;
    }
#pragma endregion

    system("pause");
    system("cls");
    std::cout << "\n\nPrueba M2, CHAR\n\n";

#pragma region M2

    for (char i = 65; i < 91; i++)
    {
        std::cout << "Se incluye: " << i << std::endl;
        m2.anade(i);
        std::cout << "Hay " << m2.cardinalidad() << " elementos" << std::endl;
    }

    std::cout << "En total hay " << m2.cardinalidad() << " elementos" << std::endl;

    for(char i = 65; i < 100; i+=3)
    {
        std::cout << "El elemento (" << i << ")" << (m2.pertenece(i)? " ":" no ") << "pertenece al conjunto" << std::endl;
    }

    for(char i = 65; i < 91; i++)
    {
        std::cout << "Se elimina: " << i << std::endl;
        m2.elimina(i);
        std::cout << "Quedan: " << m2.cardinalidad() << std::endl;
    }
#pragma endregion
    
    system("pause");
    system("cls");
    std::cout << "\n\nPrueba 3, PERSONA\n\n";

#pragma region M3
    Multiconjunto<Persona> m3 = Multiconjunto<Persona>();

    std::string nombres[] = {"Adrian", "Sergio", "Eddie"};

    Persona p1 = Persona(nombres[0], 20);
    Persona p2 = Persona(nombres[1], 19);
    Persona p3 = Persona(nombres[2], 21);

    std::cout << "Se incluyen tres personas, p1, p2 y p3\n\n";
    m3.anade(p1);
    m3.anade(p2);
    m3.anade(p3);

    std::cout << "Hay " << m3.cardinalidad() << " personas incluidas\n\n" << std::endl;

    //show p1, p2, p3
    std::cout << "p1: " << p1.getNombre() << " " << p1.getEdad() << std::endl;
    std::cout << "p2: " << p2.getNombre() << " " << p2.getEdad() << std::endl;
    std::cout << "p3: " << p3.getNombre() << " " << p3.getEdad() << std::endl;

    std::cout << "Se elimina p1\n\n" << std::endl;
    m3.elimina(p1);

    std::cout << "Ahora hay " << m3.cardinalidad() << " personas incluidas\n\n" << std::endl;

    std::cout << p1.getNombre() << " - " << p1.getEdad() << (m3.pertenece(p1)? " ":" no ") << "pertenece al conjunto\n\n" << std::endl;

    std::cout << p2.getNombre() << " - " << p2.getEdad() << (m3.pertenece(p2)? " ":" no ") << "pertenece al conjunto\n\n" << std::endl;

#pragma endregion

    system("pause");
    return 0;
}