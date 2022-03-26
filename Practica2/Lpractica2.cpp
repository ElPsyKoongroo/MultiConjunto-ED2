#include "Lincludes/abb.h"
#include "Lincludes/arbin.h"
#include <cstdlib>
#include <iostream>
#include <queue>

// Recorridos

template <typename T>
void inorden(const Arbin<T> &a, const typename Arbin<T>::Iterador &r) {
    if (!r.arbolVacio()) {
        inorden(a, a.subIzq(r));
        cout << r.observar() << " ";
        inorden(a, a.subDer(r));
    }
}

template <typename T>
void preorden(const Arbin<T> &a, const typename Arbin<T>::Iterador &r) {
    if (!r.arbolVacio()) {
        cout << r.observar() << " ";
        preorden(a, a.subIzq(r));
        preorden(a, a.subDer(r));
    }
}

template <typename T>
void postorden(const Arbin<T> &a, const typename Arbin<T>::Iterador &r) {
    if (!r.arbolVacio()) {
        postorden(a, a.subIzq(r));
        postorden(a, a.subDer(r));
        cout << r.observar() << " ";
    }
}

template <typename T> void anchura(const Arbin<T> &a) {
    if (!a.esVacio()) {
        queue<typename Arbin<T>::Iterador> c;
        typename Arbin<T>::Iterador ic = a.getRaiz();
        c.push(ic);
        while (!c.empty()) {
            ic = c.front();
            c.pop();
            cout << ic.observar() << " ";
            if (!a.subIzq(ic).arbolVacio())
                c.push(a.subIzq(ic));
            if (!a.subDer(ic).arbolVacio())
                c.push(a.subDer(ic));
        }
    }
}

/***************************************************************************/
/****************************** EJERCICIOS *********************************/
/***************************************************************************/
// Ejercicio 1
template <class T> int numHojas(const Arbin<T> arbol) {
    if (arbol.esVacio()) {
        return 0;
    }
    return 1 + numHojas(arbol, arbol.subDer(arbol.getRaiz())) +
           numHojas(arbol, arbol.subIzq(arbol.getRaiz()));
}

template <class T>
int numHojas(const Arbin<T> &arbolito,
             const typename Arbin<T>::Iterador &iterator) {
    try {
        iterator.observar();
        return 1 + numHojas(arbolito, arbolito.subDer(iterator)) +
               numHojas(arbolito, arbolito.subIzq(iterator));

    } catch (const std::exception &e) {
        return 0;
    }
}

/****************************************************************************/
// Ejercicio 2

template <class T>
const Arbin<T> simetrico(const Arbin<T> arbol,
                         const typename Arbin<T>::Iterador &Iterador) {
    try {
        Iterador.observar();
        return Arbin<T>(Iterador.observar(),
                        simetrico(arbol, arbol.subDer(Iterador)),
                        simetrico(arbol, arbol.subIzq(Iterador)));
    } catch (const std::exception &e) {
        return Arbin<T>();
    }
}

template <class T> Arbin<T> simetrico(Arbin<T> &arbol) {
    if (arbol.esVacio()) {
        return arbol;
    }
    return Arbin<T>(arbol.getRaiz().observar(),
                    simetrico<T>(arbol, arbol.subDer(arbol.getRaiz())),
                    simetrico<T>(arbol, arbol.subIzq(arbol.getRaiz())));
}

/****************************************************************************/
// Ejercicio 3

template <class T>
void recorridoZigzag(const typename Arbin<T>::Iterador &Iterador,
                     const Arbin<T> &a,
                     char sentido) {
    try {
        if (sentido == 'D') {
            cout << Iterador.observar() << " ";
            recorridoZigzag(a.subDer(Iterador), a, 'I');
        } else {
            cout << Iterador.observar() << " ";
            recorridoZigzag(a.subIzq(Iterador), a, 'D');
        }
    } catch (const std::exception &e) {
        return;
    }
}

template <class T> void recorridoZigzag(const Arbin<T> &a, char sentido) {
    if (!a.esVacio()) {
        if (sentido == 'D') {
            cout << a.getRaiz().observar() << " ";
            recorridoZigzag(a.subDer(a.getRaiz()), a, 'I');
        } else {
            cout << a.getRaiz().observar() << " ";
            recorridoZigzag(a.subIzq(a.getRaiz()), a, 'D');
        }
    }
}

/******************************************************************************/
// Ejercicio 4
template <class T> bool compensado(const Arbin<T> &arbol) {
    if (arbol.esVacio()) {
        return true;
    }

    int diferencia = abs(arbol.subDer(arbol.getRaiz()).altura() -
                         arbol.subIzq(arbol.getRaiz()).altura());
    if ((diferencia) >= 2)
        return false;

    if (compensado(arbol, arbol.subIzq(arbol.getRaiz())) &&
        compensado(arbol, arbol.subDer(arbol.getRaiz()))) {
        return true;
    }
    return false;
}

template <class T>
bool compensado(const Arbin<T> &arbol,
                const typename Arbin<T>::Iterador &iterador) {

    int rHigh = 0, lHigh = 0;

    if (iterador.arbolVacio())
        return true;

    rHigh = (!arbol.subDer(iterador).arbolVacio())
                ? arbol.subDer(iterador).altura()
                : 0;
    lHigh = (!arbol.subIzq(iterador).arbolVacio())
                ? arbol.subIzq(iterador).altura()
                : 0;

    int diferencia = abs(rHigh - lHigh);

    if ((diferencia) >= 2)
        return false;

    if (!diferencia)
        return true;

    return compensado(arbol, arbol.subIzq(iterador)) &&
           compensado(arbol, arbol.subDer(iterador));
};

/*****************************************************************************/
// Ejercicio 5
template <class T> void palabras(const Arbin<T> &a) {
    std::string palabra;
    if (!a.esVacio()) {
        palabra += a.getRaiz().observar();
        palabras(a, a.subIzq(a.getRaiz()), palabra);
        palabras(a, a.subDer(a.getRaiz()), palabra);
    }
}

template <class T>
void palabras(const Arbin<T> &a,
              const typename Arbin<T>::Iterador &Iterador,
              std::string palabra) {
    bool empty = true;
    palabra += Iterador.observar();
    if (!a.subIzq(Iterador).arbolVacio()) {
        palabras(a, a.subIzq(Iterador), palabra);
        empty = false;
    }
    if (!a.subDer(Iterador).arbolVacio()) {
        palabras(a, a.subDer(Iterador), palabra);
        empty = false;
    }
    if (empty) {
        cout << palabra << " ";
    }
}

/******************************************************************************/
// Ejercicio 6

void siguiente(const ABB<int> &a,
               ABB<int>::Iterador iterador,
               int x,
               int &mayor) {
    iterador.observar();
    if (x < iterador.observar() && iterador.observar() < mayor) {
        mayor = iterador.observar();
    }
    if (mayor == -1 && x < iterador.observar()) {
        mayor = iterador.observar();
    }
    if (!a.subIzq(iterador).arbolVacio()) {
        siguiente(a, a.subIzq(iterador), x, mayor);
    }
    if (!a.subDer(iterador).arbolVacio()) {
        siguiente(a, a.subDer(iterador), x, mayor);
    }
}

int siguienteMayor(const ABB<int> &a, int x) {
    if (a.esVacio()) {
        throw NoHaySiguienteMayor();
    }
    int mayor = a.getRaiz().observar() > x ? a.getRaiz().observar() : -1;

    if (a.getRaiz().observar() == x + 1) {
        return a.getRaiz().observar();
    }

    if (a.getRaiz().observar() <= x) {
        siguiente(a, a.subDer(a.getRaiz()), x, mayor);
    } else {
        siguiente(a, a.subIzq(a.getRaiz()), x, mayor);
        siguiente(a, a.subDer(a.getRaiz()), x, mayor);
    }
    if (mayor == -1)
        throw NoHaySiguienteMayor();
    return mayor;
}

/******************************************************************************/
// Ejercicio 7

/******************************************************************************/
// Ejercicio 8

/****************************************************************************/
/****************************************************************************/
int main(int argc, char *argv[]) {
    Arbin<char> A('t',
                  Arbin<char>('m', Arbin<char>(),
                              Arbin<char>('f', Arbin<char>(), Arbin<char>())),
                  Arbin<char>('k',
                              Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                              Arbin<char>()));

    Arbin<char> B(
        't',
        Arbin<char>('n', Arbin<char>(),
                    Arbin<char>('d',
                                Arbin<char>('e', Arbin<char>(), Arbin<char>()),
                                Arbin<char>())),
        Arbin<char>('m', Arbin<char>('f', Arbin<char>(), Arbin<char>()),
                    Arbin<char>('n', Arbin<char>(), Arbin<char>())));

    Arbin<char> D('t',
                  Arbin<char>('k',
                              Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                              Arbin<char>()),
                  Arbin<char>('m', Arbin<char>(),
                              Arbin<char>('f', Arbin<char>(), Arbin<char>())));

    Arbin<char> E('o',
                  Arbin<char>('r', Arbin<char>(),
                              Arbin<char>('o', Arbin<char>(), Arbin<char>())),
                  Arbin<char>('l',
                              Arbin<char>('a', Arbin<char>(), Arbin<char>()),
                              Arbin<char>('e', Arbin<char>(), Arbin<char>())));

    Arbin<int> F(
        2,
        Arbin<int>(7, Arbin<int>(2, Arbin<int>(), Arbin<int>()),
                   Arbin<int>(6, Arbin<int>(5, Arbin<int>(), Arbin<int>()),
                              Arbin<int>(11, Arbin<int>(), Arbin<int>()))),
        Arbin<int>(5, Arbin<int>(),
                   Arbin<int>(9, Arbin<int>(),
                              Arbin<int>(4, Arbin<int>(), Arbin<int>()))));

    ABB<int> BB6, BB7;

    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;

    // COPIA SIMETRICA //
    Arbin<char> C = simetrico(B);
    cout << "Recorrido en inorden del arbol B: " << endl;
    inorden(B, B.getRaiz());
    cout << endl << "Recorrido en inorden del arbol C: " << endl;
    inorden(C, C.getRaiz());
    cout << endl << endl;

    // RECORRIDO EN ZIG-ZAG //
    cout << "Recorrido en zigzag I de B:\n";
    recorridoZigzag(B, 'I');
    cout << endl;
    cout << "Recorrido en zigzag D de C:\n";
    recorridoZigzag(C, 'D');
    cout << endl << endl;

    // COMPENSADO //
    cout << "Esta A compensado?:";
    cout << (compensado(A) ? " SI" : " NO") << endl;
    cout << "Esta B compensado?:";
    cout << (compensado(B) ? " SI" : " NO") << endl << endl;
    // PALABRAS DE UN ARBOL //

    cout << "PALABRAS DE A:\n";
    palabras(E);
    cout << "PALABRAS DE B:\n";
    palabras(B);
    cout << endl;

    // SIGUIENTE MAYOR
    BB6.insertar(8);
    BB6.insertar(3);
    BB6.insertar(10);
    BB6.insertar(1);
    BB6.insertar(6);
    BB6.insertar(14);
    BB6.insertar(4);
    BB6.insertar(7);
    BB6.insertar(13);
    try {
        cout << "Siguiente mayor en BB6 de 5: " << siguienteMayor(BB6, 5)
             << endl;
        cout << "Siguiente mayor en BB6 de 8: " << siguienteMayor(BB6, 8)
             << endl;
        cout << "Siguiente mayor en BB6 de 13: " << siguienteMayor(BB6, 13)
             << endl;
        cout << "Siguiente mayor en BB6 de 14: " << siguienteMayor(BB6, 14)
             << endl;
    } catch (const NoHaySiguienteMayor &e) {
        cout << e.Mensaje() << endl << endl;
    }
    /*
    // POSICION INORDEN //
    BB7.insertar(5);
    BB7.insertar(1);
    BB7.insertar(3);
    BB7.insertar(8);
    BB7.insertar(6);
    cout << "Posicion Inorden en BB7 de 3: ";
    cout << posicionInorden(BB7, 3);
    cout << endl
         << "Posicion Inorden en BB7 de 8:
            "; cout << posicionInorden(BB7, 8); cout << endl << " Posicion
                Inorden en BB7 de 7
        : "; cout << posicionInorden(BB7, 7); cout << endl << endl;

          // SUMA CAMINO
          cout
         << "Hay un camino de suma 26 en F?:";
    cout << (haySumaCamino(F, 26) ? " SI" : " NO") << endl;
    cout << "Hay un camino de suma 9 en F?:";
    cout << (haySumaCamino(F, 9) ? " SI" : " NO") << endl;
    */
    system("PAUSE");
    return 0;
}
