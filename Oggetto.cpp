#include "Oggetto.hpp"


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
    std::cout << "  [Nome]: " << nome << "  [Categoria]: " << categoria << "  [Prezzo]: " << prezzo << " euro  [Quantita]: " << quantita << std::endl;
}


