#include "gtest/gtest.h"
#include "../Utente.h"


class UtenteTest : public ::testing::Test{
protected:
    void SetUp() override{
        lista = new ListaSpesa("Lista di Prova");
        utente = new Utente("Mario Rossi", lista);
        notificationCount = 0;
    }

    void TearDown() override{
        delete utente;
        delete lista;
    }

    ListaSpesa* lista;
    Utente* utente;
    int notificationCount;
};

TEST_F(UtenteTest, CreazioneUtente){
    EXPECT_NO_THROW({Utente utenteTest("Luigi Bianchi", lista);});
}


TEST_F(UtenteTest, AttachObserver) {
    ListaSpesa nuovaLista("Nuova Lista");
    Utente nuovoUtente("Giulia Verdi", &nuovaLista);

    Oggetto oggetto("Latte", "Alimentari", 2, false);
    testing::internal::CaptureStdout();
    nuovaLista.addOggetto(oggetto);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Nuova Notifica"), std::string::npos);
    EXPECT_NE(output.find("Giulia Verdi"), std::string::npos);
    EXPECT_NE(output.find("Latte"), std::string::npos);
}

TEST_F(UtenteTest, DetachObserver){
    utente->detach();

    Oggetto oggetto("Pane", "Alimentari", 1, false);
    testing::internal::CaptureStdout();
    lista->addOggetto(oggetto);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("Nuova Notifica"), std::string::npos);
}

TEST_F(UtenteTest, UpdateNotification){
    Oggetto oggetto1("Mela", "Frutta", 5, false);
    Oggetto oggetto2("Acqua", "Bevande", 6, true);

    lista->addOggetto(oggetto1);
    notificationCount++;
    lista->addOggetto(oggetto2);
    notificationCount++;

    testing::internal::CaptureStdout();
    lista->Notify();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Mela"), std::string::npos);
    EXPECT_NE(output.find("Acqua"), std::string::npos);
    EXPECT_NE(output.find("Nuova Notifica"), std::string::npos);

    EXPECT_EQ(notificationCount, 2);

}

TEST_F(UtenteTest, DistruzioneUtente){
    testing::internal::CaptureStdout();
    delete utente;
    utente = nullptr;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Ha smesso di gestire la lista"), std::string::npos);
}
