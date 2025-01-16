#include "ListaSpesa.h"
#include "Utente.h"


int main(){

    // Creazione di 10 oggetti
    Oggetto o0("Cavo USB", "Elettronica", 1, false );
    Oggetto o1("Pasta", "Alimentari", 3, false);
    Oggetto o2("Latte", "Alimentari", 2, true);
    Oggetto o3("Detersivo", "Casa", 1, false);
    Oggetto o4("Biscotti", "Alimentari", 2, false);
    Oggetto o5("Sapone", "Casa", 1, true);
    Oggetto o6("Tablet", "Elettronica", 1, false);
    Oggetto o7("Quaderno", "Cartoleria", 2, true);
    Oggetto o8("Penne", "Cartoleria", 5, true);
    Oggetto o9("Shampoo", "Casa", 1, true);
    Oggetto o10("Pianta di Basilico", "Giardinaggio", 1, false);

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
    std::cout << "\n" << std::endl;
    //stampo solo oggetti di una stessa categoria
    listaSettimanale.searchPrint("Alimentari");
    std::cout << "\n\n" << std::endl;

    listaRegali.printLista();
    std::cout << "\n\n" << std::endl;
    //ricerco e stampo un oggetto
    listaRegali.searchOggetto("Cavo USB")->printOggetto();
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