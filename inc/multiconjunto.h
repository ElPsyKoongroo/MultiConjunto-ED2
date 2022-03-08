#ifndef _MULTI_CONJ_H
#define _MULTI_CONJ_H

#define MAX_ELEMENTS 100

template <typename T> class Multiconjunto {
  public:
    // Constructor  
    Multiconjunto(int a = 1);
    // Comprueba si el multiconjunto es o no vacío
    bool esVacio() const;
    // Devuelve el número de elementos
    int cardinalidad() const;
    // Añade un objeto de tipo T al multiconjunto. Se permiten elementos
    // repetidos
    void anade(const T &objeto);
    // Elimina todas las ocurrencias del objeto
    // pasado como parámetro
    void elimina(const T &objeto);
    // Comprueba si el objeto pasado como parámetro
    // existe en el multiconjunto
    bool pertenece(const T &objeto) const;
  private:
    // Vector de almacenamiento de elementos
    T c[MAX_ELEMENTS];
    // Indica el número de elementos en el multiconjunto
    int num;
};

#endif