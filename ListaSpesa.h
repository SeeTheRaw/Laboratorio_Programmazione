#ifndef LISTASPESA_H
#define LISTASPESA_H
#include <string>
#include <list>
#include "Subject.h"
#include "Oggetto.h"


class ListaSpesa : public Subject{

public:
    ListaSpesa(std::string nl) : nomeLista(nl) {}
    ~ListaSpesa() {}

    const std::string &getNomeLista();
    void setNomeLista(const std::string &nl);

    void AddObserver(Observer *o) override;
    void RemoveObserver(Observer *o) override;
    void Notify() override;

    void addOggetto(Oggetto &o);
    void removeOggetto(Oggetto &o);
    void printLista();




private:

    std::string nomeLista;
    std::list<Oggetto> lista;
    std::list<Observer*> observers;


};

#endif
