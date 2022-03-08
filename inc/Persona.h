#include<string>


class Persona 
{ 
    std::string nombre; 
    int edad; 
public: 
    Persona(const std::string& n = "", int e = 0); 
    const std::string& getNombre() const; 
    int getEdad() const; 
    void setNombre(const std::string& n); 
    void setEdad(int e); 
    bool operator==(const Persona& p) const; 
};