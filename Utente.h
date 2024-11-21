#ifndef UTENTE_H
#define UTENTE_H
#include <iostream>
#include <string>
#include <list>
#include "Observer.h"
#include "ListaSpesa.h"

class Utente : public Observer{

public:

    Utente(std::string nu, ListaSpesa* lista ) : nomeUtente(nu), s(lista){
        attach();
        std::cout << "[UTENTE] ==> " << nomeUtente << " Ha iniziato a gestire la [LISTA] ==> " << lista->getNomeLista() << "\n" << std::endl;
    }
    ~Utente() {
        detach();
        std::cout << "[UTENTE] ==> " << nomeUtente << " Ha smesso di gestire la lista \n" << std::endl;
    }


    void attach(){
        s->AddObserver(this);
    }

    void detach(){
        s->RemoveObserver(this);
    }

    void update(const std::string &nomeLista, std::list<Oggetto> &lista) override{
        std::cout << "Nuova Notifica !!!!   [UTENTE] ==> " << nomeUtente << "  la [LISTA] ==> "<< nomeLista << " Ha subito delle modifiche! " << std::endl;
        std::cout << "{{ LISTA ATTUALE }} : \n" << std::endl;
        for (auto it = lista.begin(); it != lista.end(); it++){
            it->printOggetto();
        }
        std::cout << "\n" << std::endl;
    }

private:

    std::string nomeUtente;
    ListaSpesa *s;
};

#endif
