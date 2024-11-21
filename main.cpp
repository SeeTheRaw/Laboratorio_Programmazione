#include "ListaSpesa.h"
#include "Utente.h"


int main(){

    // Creazione di 10 oggetti
    Oggetto o0("Cavo USB", "Elettronica", 20, 1);
    Oggetto o1("Pasta", "Alimentari", 2, 3);
    Oggetto o2("Latte", "Alimentari", 1, 2);
    Oggetto o3("Detersivo", "Casa", 3, 1);
    Oggetto o4("Biscotti", "Alimentari", 2, 2);
    Oggetto o5("Sapone", "Casa", 1, 1);
    Oggetto o6("Tablet", "Elettronica", 200, 1);
    Oggetto o7("Quaderno", "Cartoleria", 3, 2);
    Oggetto o8("Penne", "Cartoleria", 1, 5);
    Oggetto o9("Shampoo", "Casa", 2, 1);
    Oggetto o10("Pianta di Basilico", "Giardinaggio", 5, 1);

    // Creazione di una lista della spesa settimanale e di una lista di futuri regali
    ListaSpesa listaSettimanale("Spesa Settimanale");
    ListaSpesa listaRegali("Regali Compleanno");

    // Aggiunta di oggetti alle liste
    listaSettimanale.addOggetto(o1);
    listaSettimanale.addOggetto(o2);
    listaSettimanale.addOggetto(o3);
    listaSettimanale.addOggetto(o4);
    listaSettimanale.addOggetto(o5);
    listaSettimanale.addOggetto(o10);

    listaRegali.addOggetto(o6);
    listaRegali.addOggetto(o0);
    listaRegali.addOggetto(o7);

    //stampo le liste
    listaSettimanale.printLista();
    std::cout << "\n\n" << std::endl;
    listaRegali.printLista();
    std::cout << "\n\n" << std::endl;


    // Creazione di un utente
    Utente u1("Mario Rossi", &listaSettimanale);
    Utente u2("Alice Verdi", &listaRegali);

    std::cout << "\n" << std::endl;

    // Aggiunta di oggetti alle liste
    listaSettimanale.addOggetto(o9);
    listaRegali.removeOggetto(o0);

    Utente u3("Luca Bianchi", &listaSettimanale);
    listaSettimanale.addOggetto(o8);

    return 0;
}