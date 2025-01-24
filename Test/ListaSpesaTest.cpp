#include "gtest/gtest.h"
#include "../ListaSpesa.h"

TEST(ListaSpesaTest, Costruttore){
    ListaSpesa lista("Spesa settimanale");
    EXPECT_EQ(lista.getNomeLista(), "Spesa settimanale");
}

TEST(ListaSpesaTest, SetAndGetNomeLista){
    ListaSpesa lista("Spesa vecchia");
    lista.setNomeLista("Spesa aggiornata");
    EXPECT_EQ(lista.getNomeLista(), "Spesa aggiornata");
}

TEST(ListaSpesaTest, AddAndRemoveOggetto){
    ListaSpesa lista("Spesa settimanale");

    Oggetto o1("Mela", "Frutta", 1, 1);
    Oggetto o2("Pane", "Panificio", 2, 0);

    EXPECT_THROW(Oggetto o3("Latte", "Latticini", -1, 0), std::invalid_argument);

    lista.addOggetto(o1);
    lista.addOggetto(o2);


    testing::internal::CaptureStdout();
    lista.printLista();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("[Nome]: Mela"), std::string::npos);
    EXPECT_NE(output.find("[Nome]: Pane"), std::string::npos);


    lista.removeOggetto(o1);
    testing::internal::CaptureStdout();
    lista.printLista();
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("[Nome]: Mela"), std::string::npos);
    EXPECT_NE(output.find("[Nome]: Pane"), std::string::npos);
}

TEST(ListaSpesaTest, PrintLista){
    ListaSpesa lista("Spesa settimanale");


    Oggetto o1("Latte", "Bevande", 3, 1);
    Oggetto o2("Uova", "Alimentari", 2, 0);

    lista.addOggetto(o1);
    lista.addOggetto(o2);


    testing::internal::CaptureStdout();
    lista.printLista();
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_NE(output.find("[Nome]: Latte"), std::string::npos);
    EXPECT_NE(output.find("[Categoria]: Bevande"), std::string::npos);
    EXPECT_NE(output.find("[Quantita]: 3"), std::string::npos);
    EXPECT_NE(output.find("[Acquistato]: Si"), std::string::npos);

    EXPECT_NE(output.find("[Nome]: Uova"), std::string::npos);
    EXPECT_NE(output.find("[Categoria]: Alimentari"), std::string::npos);
    EXPECT_NE(output.find("[Quantita]: 2"), std::string::npos);
    EXPECT_NE(output.find("[Acquistato]: No"), std::string::npos);
}

TEST(ListaSpesaTest, SearchOggetto){
    ListaSpesa lista("Spesa settimanale");

    Oggetto o1("Latte", "Bevande", 3, 1);
    Oggetto o2("Uova", "Alimentari", 2, 0);
    Oggetto o3("Pane", "Panificio", 5, 1);

    lista.addOggetto(o1);
    lista.addOggetto(o2);
    lista.addOggetto(o3);


    Oggetto* risultato = lista.searchOggetto("Latte");
    ASSERT_NE(risultato, nullptr);
    EXPECT_EQ(risultato->getNome(), "Latte");
    EXPECT_EQ(risultato->getCategoria(), "Bevande");
    EXPECT_EQ(risultato->getQuantita(), 3);


    risultato = lista.searchOggetto("Cioccolato");
    EXPECT_EQ(risultato, nullptr);
}

TEST(ListaSpesaTest, SearchPrint){
    ListaSpesa lista("Spesa settimanale");

    Oggetto o1("Latte", "Bevande", 3, 1);
    Oggetto o2("Uova", "Alimentari", 2, 0);
    Oggetto o3("Pane", "Bevande", 1, 1);

    lista.addOggetto(o1);
    lista.addOggetto(o2);
    lista.addOggetto(o3);


    testing::internal::CaptureStdout();
    lista.searchPrint("Bevande");
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_NE(output.find("[Nome]: Latte"), std::string::npos);
    EXPECT_NE(output.find("[Nome]: Pane"), std::string::npos);
    EXPECT_EQ(output.find("[Nome]: Uova"), std::string::npos);


    testing::internal::CaptureStdout();
    lista.searchPrint("Snacks");
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n[ Oggetti nella categoria: Snacks ] \n");
}

TEST(ListaSpesaTest, CountOggettiDaAcquistare){
    ListaSpesa lista("Spesa settimanale");

    // Aggiungiamo alcuni oggetti alla lista
    Oggetto o1("Latte", "Bevande", 3, 1);  // Già acquistato
    Oggetto o2("Uova", "Alimentari", 2, 0); // Non acquistato
    Oggetto o3("Pane", "Panificio", 1, 0);  // Non acquistato
    Oggetto o4("Formaggio", "Latticini", 1, 1); // Già acquistato

    lista.addOggetto(o1);
    lista.addOggetto(o2);
    lista.addOggetto(o3);
    lista.addOggetto(o4);

    // Eseguiamo il test per verificare il conteggio degli oggetti non acquistati
    EXPECT_EQ(lista.countOggettiDaAcquistare(), 2);

    // Rimuoviamo un oggetto non acquistato e verifichiamo il conteggio aggiornato
    lista.removeOggetto(o3);
    EXPECT_EQ(lista.countOggettiDaAcquistare(), 1);

    // Rimuoviamo tutti gli oggetti non acquistati e verifichiamo che il conteggio sia zero
    lista.removeOggetto(o2);
    EXPECT_EQ(lista.countOggettiDaAcquistare(), 0);
}


