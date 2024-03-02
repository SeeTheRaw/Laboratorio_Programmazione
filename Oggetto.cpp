#include "Oggetto.hpp"

Oggetto::Oggetto(std::string n, std::string c, int p, int q) : nome(n), categoria(c), prezzo(p), quantita(q) {}


const std::string &Oggetto::getNome(){
    return nome;
}

void Oggetto::setNome(const std::string &n){
    nome = n;
}


const std::string &Oggetto::getCategoria(){
    return categoria;
}

void Oggetto::setCategoria(const std::string &c){
    categoria = c;
}


const int &Oggetto::getPrezzo(){
    return prezzo;
}

void Oggetto::setPrezzo(const int &p){
    prezzo = p;
}


const int &Oggetto::getQuantita(){
    return quantita;
}

void Oggetto::setQuantita(const int &q){
    quantita = q;
}



void Oggetto::printOggetto(){
    std::cout << "\nNome: " << nome << std::endl;
    std::cout << "\nCategoria: " << categoria << std::endl;
    std::cout << "\nPrezzo: " << prezzo << std::endl;
    std::cout << "\nQuantita: " << quantita << std::endl;
}


