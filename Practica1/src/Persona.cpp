#include "Persona.h"

Persona::Persona(const std::string& n, int e) {
    nombre = n;
    edad = e;
}

const std::string& Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const{
    return edad;
}

void Persona::setNombre(const std::string& n){
    nombre = n;
}

void Persona::setEdad(int e){
    edad = e;
}

bool Persona::operator==(const Persona& p) const{
    if(p.getEdad() == this->edad && p.getNombre() == this->nombre){
        return true;
    }
    return false;
} 