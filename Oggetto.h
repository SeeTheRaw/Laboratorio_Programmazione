#ifndef OGGETTO_H
#define OGGETTO_H
#include <iostream>
#include <string>

class Oggetto{

public:

    Oggetto(std::string n, std::string c, int p, int q) : nome(n), categoria(c), prezzo(p), quantita(q) {}
    ~Oggetto() {}

    bool operator==(const Oggetto &o) const{
        return nome == o.nome;
    }

    void printOggetto(){
        std::cout << "  [Nome]: " << nome << "  [Categoria]: " << categoria << "  [Prezzo]: " << prezzo << " euro  [Quantita]: " << quantita << std::endl;
    }

private:

    std::string nome;
    std::string categoria;
    int prezzo;
    int quantita;

};

#endif
