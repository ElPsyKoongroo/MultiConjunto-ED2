#include "../inc/multiconjunto.h"
#include "../inc/Persona.h"
#include <iostream>
#include <cstring>


template class Multiconjunto <char>;
template class Multiconjunto <int>;
template class Multiconjunto <Persona>;

template <typename T>
Multiconjunto<T>::Multiconjunto(){
    num = 0;
    memset(c, 0, sizeof(T)*MAX_ELEMENTS);
}

template <typename T>
bool Multiconjunto<T>::esVacio()const{
    return (bool)this->num;
}

template <typename T>
int Multiconjunto<T>::cardinalidad() const{
    return this->num;
}

template <>
void Multiconjunto<Persona>::anade(const Persona &objeto){
    if (this->num == MAX_ELEMENTS || objeto == Persona()){
        return ;
    }
    for(int i = 0; i<MAX_ELEMENTS; i++){
        if(this->c[i] == Persona()){
            this->c[i] = objeto;
            this->num++;
            return ;
        }
    }
}

template <typename T>
void Multiconjunto<T>::anade(const T &objeto){
    if (this->num == MAX_ELEMENTS || objeto == 0){
        return ;
    }
    for(int i = 0; i<MAX_ELEMENTS; i++){
        if(this->c[i] == 0){
            this->c[i] = objeto;
            this->num++;
            return ;
        }
    }
}

template<>
void Multiconjunto<Persona>::elimina(const Persona &objeto){
    if (this->num == 0 || objeto == Persona()) return ;

    for(int i = 0; i<MAX_ELEMENTS; i++){
        if(this->c[i] == objeto){
            this->c[i] = Persona();
            this->num--;
        }
    }
}

template <typename T>
void Multiconjunto<T>::elimina(const T &objeto){
    if (this->num == 0 || objeto == 0) return ;

    for(int i = 0; i<MAX_ELEMENTS; i++){
        if(this->c[i] == objeto){
            this->c[i] = 0;
            this->num--;
        }
    }
}


template <typename T>
bool Multiconjunto<T>::pertenece(const T &objeto) const{
    if (this->num == 0) return false;

    for(int i = 0; i<MAX_ELEMENTS; i++){
        if(this->c[i] == objeto) return true;
    }
    return false;
}
