#include <gtest/gtest.h>
#include "src/Samochod.h"
#include "src/KatalogSamochodow.h"

TEST(PobranieSamocjodu, czyIstieje) {
    KatalogSamochodow katalog;
    Samochod s1(100, "Ford", "Focus", 2019, 5, "Dostepny", 12000);
    katalog.dodajSam(&s1);
  
    bool wynik = katalog.zmienStatusSamochodu(100, "w serwisie");
    EXPECT_TRUE(wynik);
  
    Samochod pobrany = katalog.pobierzSamochod(100);
    ASSERT_NE(pobrany->getStatus(), "Dostepny") << "Status samochodu powinien byc zmieniony";

    bool wynik = katalog.zmienStatusSamochodu(101, "w serwisie");
    EXPECT_FALSE(wynik);
}

int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}
