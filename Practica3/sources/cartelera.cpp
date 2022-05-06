#include "cartelera.h"
#include <iostream>
#include <algorithm>

using namespace std;

Cartelera::Cartelera() : espectaculos() {}

void Cartelera::insertaEspectaculo(const string &e) {
    if(!existeEspectaculo(e)) espectaculos.insert(PEspectaculos(e, DSalas()));
}

void Cartelera::insertaSala(const string &espectaculo, const string &sala, const string &ciudad) {

    if(existeEspectaculo(espectaculo)) {
        DSalas& Sala = espectaculos.at(espectaculo);
        if(Sala.find(sala) != Sala.end()) return;
        Sala.insert(PSalas(sala, ciudad));
    }
    else{
        DSalas Sala;
        Sala.insert(PSalas(sala, ciudad));
        espectaculos.insert(PEspectaculos(espectaculo, Sala));
    }
}

void Cartelera::eliminaEspectaculo(const string &e) {
    if(existeEspectaculo(e)) espectaculos.erase(e);
}

void Cartelera::eliminaSala(const string &e, const string &s) {
    if(existeEspectaculo(e)) {
        DSalas& Sala = espectaculos.at(e);
        if(Sala.find(s) != Sala.end()) Sala.erase(s);
    }
}

void Cartelera::listaEspectaculos() {
    //std:: cout << "Espectaculos" << std::endl;
    for(auto it = espectaculos.begin(); it != espectaculos.end(); ++it) {
        cout << it->first << endl;
    }
}

void Cartelera::listaSalas(const string &e) {
    if(existeEspectaculo(e)) {
        //std::cout << "Salas Ciudad" << std::endl;
        DSalas& Sala = espectaculos.at(e);
        for(auto it = Sala.begin(); it != Sala.end(); ++it) {
            cout << it->first << "  " << it->second << endl;
        }
    }
}

bool Cartelera::existeEspectaculo(const string &espectaculo){
    return espectaculos.find(espectaculo) != espectaculos.end();
}