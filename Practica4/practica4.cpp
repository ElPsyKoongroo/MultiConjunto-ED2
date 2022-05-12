#include "inc/conjunto.h"
#include "inc/grafo.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>

// Ejercicio 1
template <typename T> T verticeMaxCoste(const Grafo<T, float> &G) {

    Conjunto<Vertice<T> > conj_vertice = G.vertices();

    map<T, float> coste_vertice;

    while (!conj_vertice.esVacio()) {
        T vert = conj_vertice.quitar().getObj();
        coste_vertice[vert] = 0;
    }

    Conjunto<Arista<T, float> > conj_aristas = G.aristas();

    while (!conj_aristas.esVacio()) {
        Arista<T, float> arista = conj_aristas.quitar();

        coste_vertice[arista.getOrigen()] += arista.getEtiqueta();
    }

    float max_coste = 0;
    T vert_max;

    for (std::pair<T, float> costes : coste_vertice) {
        if (costes.second > max_coste) {
            max_coste = costes.second;
            vert_max = costes.first;
        }
    }
    return vert_max;
}

// Ejercicio 2
template <typename T, typename U> void inaccesibles(const Grafo<T, U> &G) {
    Conjunto<Vertice<T> > conjVertice = G.vertices();

    map<T, int> verticesRefe;

    while (!conjVertice.esVacio()) {
        T vert = conjVertice.quitar().getObj();
        verticesRefe[vert] = 0;
    }

    Conjunto<Arista<T, U> > conjAristas = G.aristas();
    
    while (!conjAristas.esVacio()) {
        Arista<T, U> arista = conjAristas.quitar();
        verticesRefe[arista.getDestino()]++;
    }

    for(std::pair<T, int> par: verticesRefe){
        if(par.second == 0)
            std::cout << par.first << ", ";
    }
    std::cout << "\n";
}


// Ejercicio 3
template <typename T>
void funsionsita(Conjunto<Vertice<T> > adyacentes, std::queue<T>& cola_innecesaria, Conjunto<T>& visitados){
    T a;
    while(!adyacentes.esVacio()){
        a = adyacentes.quitar().getObj();
        if(!visitados.pertenece(a)){
            visitados.anadir(a);
            cola_innecesaria.push(a);
        }
    }
}

template <typename T, typename U>
bool caminoEntreDos(const Grafo<T, U> &G, const T &vertice_origen, const T &vertice_destino) {
    Conjunto<Vertice<T> > adyacentes = G.adyacentes(vertice_origen);
    Conjunto<T> visitados;
    std::queue<T> cola_innecesaria;
    T a = adyacentes.quitar().getObj();
    cola_innecesaria.push(a);
    funsionsita(adyacentes, cola_innecesaria, visitados);
    
    while(!cola_innecesaria.empty()){
        a = cola_innecesaria.front();
        cola_innecesaria.pop();
        if(a == vertice_destino) return true;
        adyacentes = G.adyacentes(a);
        funsionsita(adyacentes, cola_innecesaria, visitados);
    }
    return false;
}



//Ejercicio 4
template <typename T>
bool existeArista(const std::map<T, float> &verticesCostes, const Arista<T, float> aristita){
    return verticesCostes.find(aristita.getDestino()) != verticesCostes.end();
}

template <typename T>
void caminosAcotados(const Grafo<T, float> &G,
                     const T &vertice,
                     float costeActual,
                     float maxCoste,
                     int nivel) {

    std::map<T, float> verticesCostes;
    Conjunto<Vertice<T> > conexiones = G.adyacentes(vertice);
    while (!conexiones.esVacio()){
        T vertisito = conexiones.quitar().getObj();
        verticesCostes[vertisito] = 0;
    }

    Conjunto<Arista<T, float> > aristas = G.aristas();

    while (!aristas.esVacio()) {
        Arista<T, float> aristita = aristas.quitar();
        if (aristita.getOrigen() == vertice && existeArista(verticesCostes, aristita))
            verticesCostes[aristita.getDestino()] += aristita.getEtiqueta();
    }

    
    for (std::pair<T, float> verticeYCoste : verticesCostes) {
        if ((costeActual + verticeYCoste.second) <= maxCoste) {
            std::cout << "\r";
            for (int _ = 0; _ < nivel; ++_) {
                std::cout << "\t";
            }
            std::cout << vertice << " --> " << verticeYCoste.first << "\n";
            caminosAcotados(G, verticeYCoste.first,
                            costeActual + verticeYCoste.second, maxCoste,
                            nivel + 1);
        }
    }
}

template <typename T>
void caminosAcotados(const Grafo<T, float> &G, const T &vertice, float maxCoste) {
    caminosAcotados(G, vertice, 0, maxCoste, 0);
}
/*
// Ejercicio 5
template <typename T, typename U> T outConectado(const Grafo<T, U> &G) {}

// Ejercicio 6
template <typename T, typename U>
void recorrido_profundidad(const Grafo<T, U> &G, const T &v) {}
*/
//********************************************************************//
int main() {
    Grafo<int, float> G(7);
    for (int i = 1; i <= 7; i++)
        G.insertarVertice(i);
    G.insertarArista(2, 1, 4);
    G.insertarArista(1, 3, 3);
    G.insertarArista(1, 4, 2);
    G.insertarArista(1, 6, 1);
    G.insertarArista(6, 4, 5);
    G.insertarArista(4, 7, 3);
    G.insertarArista(5, 1, 6);

    Grafo<string, float> H(7);
    H.insertarVertice("Huelva");
    H.insertarVertice("Lepe");
    H.insertarVertice("Niebla");
    H.insertarVertice("Mazagon");
    H.insertarVertice("Almonte");
    H.insertarVertice("Aljaraque");
    H.insertarVertice("Matalasca�as");
    H.insertarArista("Lepe", "Huelva", 4);
    H.insertarArista("Huelva", "Niebla", 3);
    H.insertarArista("Huelva", "Mazagon", 2);
    H.insertarArista("Huelva", "Aljaraque", 1);
    H.insertarArista("Mazagon", "Almonte", 3);
    H.insertarArista("Mazagon", "Matalasca�as", 4);
    H.insertarArista("Aljaraque", "Mazagon", 5);
    H.insertarArista("Almonte", "Huelva", 6);

    // H.insertarArista("Almonte", "Lepe", 4);

    
    std::cout << " Vertice de maximo coste en G: " << verticeMaxCoste(G) << endl;
    std::cout << " Vertice de maximo coste en H: " << verticeMaxCoste(H) << endl;

    std::cout << endl << " Vertices inaccesibles en G: ";
    inaccesibles(G);
    
    std::cout << endl << " Camino entre Dos en H de Lepe a Almonte: ";
    std::cout << (caminoEntreDos(H, string("Lepe"), string("Almonte")) ? "SI" : " NO ") << endl; 
    std::cout << endl << " Camino entre Dos en H de Aljaraque a Lepe: "; 
    std::cout << (caminoEntreDos(H, string("Aljaraque"),string("Lepe")) ? " SI " : " NO ") << endl;

    std::cout << endl
              << " Caminos acotados en G a coste 9 desde el vertice2 : "
              << endl;
    caminosAcotados(G, 2, 9);
    /*
    std::cout << endl << endl << " Vertice outConectado en G: " <<
   outConectado(G); std::cout << endl << " Vertice outConectado en H: " <<
   outConectado(H);

    std::cout << endl << endl << " Recorrido en profundidad de H desde el
   vertice Huelva:  "; recorrido_profundidad(H, string("Huelva")); std::cout
   << endl << endl;
*/

    // system("PAUSE"); muy bonito pero en linux no funciona
    return EXIT_SUCCESS;
}
