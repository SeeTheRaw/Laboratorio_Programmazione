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

    Oggetto o1("Mela", "Frutta", 1, 5);
    Oggetto o2("Pane", "Panificio", 2, 1);

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


    Oggetto o1("Latte", "Bevande", 3, 2);
    Oggetto o2("Uova", "Alimentari", 2, 12);

    lista.addOggetto(o1);
    lista.addOggetto(o2);


    testing::internal::CaptureStdout();
    lista.printLista();
    std::string output = testing::internal::GetCapturedStdout();


    EXPECT_NE(output.find("[Nome]: Latte"), std::string::npos);
    EXPECT_NE(output.find("[Categoria]: Bevande"), std::string::npos);
    EXPECT_NE(output.find("[Prezzo]: 3 euro"), std::string::npos);
    EXPECT_NE(output.find("[Quantita]: 2"), std::string::npos);

    EXPECT_NE(output.find("[Nome]: Uova"), std::string::npos);
    EXPECT_NE(output.find("[Categoria]: Alimentari"), std::string::npos);
    EXPECT_NE(output.find("[Prezzo]: 2 euro"), std::string::npos);
    EXPECT_NE(output.find("[Quantita]: 12"), std::string::npos);
}



