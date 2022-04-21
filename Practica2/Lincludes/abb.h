#ifndef _ABB_H_
#define _ABB_H_

#include "nodoB.h"
#include "excep_abb.h"
#include "arbin.h"

template <typename T>
class ABB : public Arbin<T> {
	typedef NodoB<T>* PtrNodoB;
	public:
         ABB();
         void insertar(const T& objeto);
         bool buscar(const T& objeto) const;
         const T& minimo() const;
         const T& maximo() const;
         void eliminar(const T& objeto); 
         ~ABB();
};

#endif







