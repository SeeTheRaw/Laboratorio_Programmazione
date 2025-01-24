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
    if (o.getQuantita() <= 0) {
        std::cerr << "Errore: impossibile aggiungere un oggetto con quantita' pari a zero o negativa." << std::endl;
        return;
    }
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

void ListaSpesa::searchPrint(const std::string& categoria){
    std::cout << "\n[ Oggetti nella categoria: " << categoria << " ] " << std::endl;
    for ( auto& oggetto : lista){
        if (oggetto.getCategoria() == categoria){
            oggetto.printOggetto();
        }
    }
}

Oggetto* ListaSpesa::searchOggetto(const std::string& nome){
    for (auto& oggetto : lista){
        if (oggetto.getNome() == nome){
            return &oggetto;
        }
    }
    return nullptr;
}

int ListaSpesa::countOggettiDaAcquistare() const{
    int count = 0;
    for (const auto& oggetto : lista){
        if (!oggetto.isAcquistato()){
            count++;
        }
    }
    return count;
}