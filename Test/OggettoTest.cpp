#include "gtest/gtest.h"
#include "../Oggetto.h"


TEST(OggettoTest, Costruttore){
    Oggetto oggetto("Libro", "Cultura", 10, true);
    EXPECT_EQ(oggetto.getNome(), "Libro");
    EXPECT_EQ(oggetto.getCategoria(), "Cultura");
    EXPECT_EQ(oggetto.getQuantita(), 10);
    EXPECT_TRUE(oggetto.isAcquistato());
}

TEST(OggettoTest, CostruttoreQuantitaNegativa){
    EXPECT_THROW(Oggetto("Libro", "Cultura", -1, true), std::invalid_argument);
}

TEST(OggettoTest, OperatoreEqual){
    Oggetto obj1("Pane", "Alimentari", 1, 1);
    Oggetto obj2("Pane", "Alimentari", 1, 1);
    Oggetto obj3("Latte", "Alimentari", 2, 6);

    EXPECT_TRUE(obj1 == obj2);
    EXPECT_FALSE(obj1 == obj3);
}

TEST(OggettoTest, OggettoString){
    Oggetto oggetto("Libro", "Cultura", 10, true);
    std::string expected = "  [Nome]: Libro  [Categoria]: Cultura  [Quantita]: 10  [Acquistato]: Si";
    EXPECT_EQ(oggetto.Oggetto_String(), expected);
}

TEST(OggettoTest, PrintOggetto){
    Oggetto obj("Pane", "Alimentari", 1, 1);
    testing::internal::CaptureStdout();
    obj.printOggetto();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "  [Nome]: Pane  [Categoria]: Alimentari  [Quantita]: 1  [Acquistato]: Si\n");
}
