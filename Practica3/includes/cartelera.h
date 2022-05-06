#ifndef _CARTELERA_H_
#define _CARTELERA_H_

#include <map>
#include <string>
#include <utility>

using namespace std;

class Cartelera {
  public:
    Cartelera();
    void insertaEspectaculo(const string &e);
    void insertaSala(const string &espectaculo, const string &sala, const string &ciudad);
    void eliminaEspectaculo(const string &e);
    void eliminaSala(const string &e, const string &s);
    void listaEspectaculos();
    void listaSalas(const string &e);

    bool existeEspectaculo(const string &espectaculos);

  private:

    typedef map<string, string> DSalas;

    // Sala, Ciudad
    typedef pair<string, string> PSalas;

    // Tipo de espectaculo, Salas
    typedef pair<string, DSalas> PEspectaculos; 

    typedef map<string, DSalas> DEspectaculos;

    DEspectaculos espectaculos;
};

#endif
