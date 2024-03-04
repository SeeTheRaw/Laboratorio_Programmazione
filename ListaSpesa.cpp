#include "ListaSpesa.hpp"


const std::string &ListaSpesa::getNomeLista(){
    return nomeLista;
}

void ListaSpesa::setNomeLista(const std::string &nl){
    nomeLista = nl;
}



void ListaSpesa::addOggetto(Oggetto &o){
    lista.push_back(o);
}

void ListaSpesa::removeOggetto(Oggetto &o){
    lista.remove(o);
}

void ListaSpesa::printLista(){
    std::cout << "\n[ NOME LISTA ] ===> " << nomeLista << std::endl;
    for (std::list<Oggetto>::iterator it = lista.begin(); it != lista.end(); it++){
        it->printOggetto();
    }
}