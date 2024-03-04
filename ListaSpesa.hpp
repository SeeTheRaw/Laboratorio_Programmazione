#ifndef LISTASPESA_H
#define LISTASPESA_H
#include <iostream>
#include <string>
#include <list>
#include "Oggetto.hpp"

class ListaSpesa{

    public:
    ListaSpesa(std::string nl) : nomeLista(nl) {}
    ~ListaSpesa() {}

    const std::string &getNomeLista();
    void setNomeLista(const std::string &nl);

    void addOggetto(Oggetto &o);
    void removeOggetto(Oggetto &o);
    void printLista();


    private:

    std::string nomeLista;
    std::list<Oggetto> lista;

};


#endif // LISTASPESA_H