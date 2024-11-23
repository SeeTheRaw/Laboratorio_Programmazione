#include "gtest/gtest.h"
#include "../Oggetto.h"

TEST(OggettoTest, OperatoreEqual){
    Oggetto obj1("Pane", "Alimentari", 1, 1);
    Oggetto obj2("Pane", "Alimentari", 1, 1);
    Oggetto obj3("Latte", "Alimentari", 2, 6);

    EXPECT_TRUE(obj1 == obj2);
    EXPECT_FALSE(obj1 == obj3);
}

TEST(OggettoTest, PrintOggetto){
    Oggetto obj("Pane", "Alimentari", 1, 2);
    testing::internal::CaptureStdout();
    obj.printOggetto();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "  [Nome]: Pane  [Categoria]: Alimentari  [Prezzo]: 1 euro  [Quantita]: 2\n");
}
