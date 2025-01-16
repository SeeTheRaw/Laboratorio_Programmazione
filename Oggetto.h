#ifndef OGGETTO_H
#define OGGETTO_H
#include <iostream>
#include <string>

class Oggetto{

public:

    Oggetto(std::string n, std::string c, int q, bool a) : nome(n), categoria(c), quantita(q), acquistato(a) {
        if (q >= 99) {
            throw std::invalid_argument("La quantita' è troppo elevata!");
        }
    }
    ~Oggetto() {}


    bool operator==(const Oggetto &o) const{
        return nome == o.nome;
    }

    std::string getNome() const {
        return nome;
    }
    void setNome(const std::string& n) {
        nome = n;
    }
    std::string getCategoria() const {
        return categoria;
    }
    void setCategoria(const std::string& c) {
        categoria = c;
    }
    int getQuantita() const {
        return quantita;
    }
    void setQuantita(int q) {
        quantita = q;
    }
    void setAcquistato(bool stato) {
        acquistato = stato;
    }
    bool isAcquistato() const {
        return acquistato;
    }


    void printOggetto(){
        std::cout << "  [Nome]: " << nome << "  [Categoria]: " << categoria << "  [Quantita]: " << quantita << "  [Acquistato]: " << (acquistato ? "Si" : "No") << std::endl;
    }

private:

    std::string nome;
    std::string categoria;
    int quantita;
    bool acquistato;

};

#endif
