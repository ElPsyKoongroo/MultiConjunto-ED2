#include "../inc/multiconjunto.h"
#include <iostream>

template <typename T>
Multiconjunto<T>::Multiconjunto(){

}

template <typename T>
bool Multiconjunto<T>::esVacio()const{
    return (bool)this->num;
}

template <typename T>
int Multiconjunto<T>::cardinalidad() const{
    return this->num;
};

template <typename T>
void Multiconjunto<T>::anade(const T &objeto){
    if (this->num == 100){
        return ;
    }
    for(int i = 0; i<100; i++){
        if(this->c[i] == NULL){
            this->c[i] = objeto;
            return ;
        }
    }
}

template <typename T>
void Multiconjunto<T>::elimina(const T &objeto){
    if (this->num == 0) return ;

    for(int i = 0; i<100; i++){
        if(this->c[i] == objeto)
            this->c[i] = NULL;
    }
}