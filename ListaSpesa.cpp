#include "ListaSpesa.h"

const std::string &ListaSpesa::getNomeLista(){
    return nomeLista;
}

void ListaSpesa::setNomeLista(const std::string &nl){
    nomeLista = nl;
}

void ListaSpesa::AddObserver(Observer *o){
    observers.push_back(o);
}

void ListaSpesa::RemoveObserver(Observer *o){
    observers.remove(o);
}

void ListaSpesa::Notify(){
    for (Observer *observer : observers){
        observer->update(nomeLista, lista);
    }
}


void ListaSpesa::addOggetto(Oggetto &o){
    lista.push_back(o);
    Notify();
}

void ListaSpesa::removeOggetto(Oggetto &o){
    lista.remove(o);
    Notify();
}

void ListaSpesa::printLista(){
    std::cout << "\n[ NOME LISTA ] ===> " << nomeLista << std::endl;
    for (auto it = lista.begin(); it != lista.end(); it++){
        it->printOggetto();
    }
}
