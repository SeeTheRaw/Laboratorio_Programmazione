#ifndef UTENTE_HPP
#define UTENTE_HPP
#include <iostream>
#include <string>
#include <list>
#include "Observer.hpp"
#include "ListaSpesa.hpp"

class Utente : public Observer{

    public:

    Utente(std::string nu) : nomeUtente(nu) {}
    ~Utente() {}

    void update(const std::string &nomeLista, std::list<Oggetto> &lista){
        std::cout << "Nuova Notifica !!!!   [UTENTE] ==> " << nomeUtente << " Ha modificato la [LISTA] ==> "<< nomeLista << std::endl;
        std::cout << "{{ LISTA ATTUALE }} : \n" << std::endl;
        for (auto it = lista.begin(); it != lista.end(); it++){
            it->printOggetto();
        }
    }

    private:

    std::string nomeUtente;
};

#endif // UTENTE_HPP