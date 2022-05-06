#include "cartelera.h"
#include <iostream>
#include <algorithm>

using namespace std;

Cartelera::Cartelera() : espectaculos() {}

void Cartelera::insertaEspectaculo(const string &e) {
    if(existeEspectaculo(e)) espectaculos.insert(PEspectaculos(e, DSalas()));
}

void Cartelera::insertaSala(const string &espectaculo, const string &sala, const string &ciudad) {

    // for(auto it = espectaculos.begin(); it != espectaculos.end(); ++it){
    //     (*it).first
    // }

}

void Cartelera::eliminaEspectaculo(const string &e) {}

void Cartelera::eliminaSala(const string &e, const string &s) {}

void Cartelera::listaEspectaculos() {}

void Cartelera::listaSalas(const string &e) {}

bool Cartelera::existeEspectaculo(const string &espectaculo){
    return (find(espectaculos.begin(), espectaculos.end(), espectaculo) == espectaculos.end());
}