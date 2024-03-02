#ifndef OGGETTO_H
#define OGGETTO_H
#include <iostream>
#include <string>
#include <list>

class Oggetto{

public:

Oggetto(std::string n, std::string c, int p, int q);
~Oggetto(){}
    
const std::string &getNome();
void setNome(const std::string &n);

const std::string &getCategoria();
void setCategoria(const std::string &c);

const int &getPrezzo();
void setPrezzo(const int &p);

const int &getQuantita();
void setQuantita(const int &q);

void printOggetto();

private:

std::string nome;
std::string categoria;
int prezzo;
int quantita;

};

#endif // OGGETTO_H