#include <gtest/gtest.h>
#include "src/Samochod.h"

TEST(SamochodJednostkowy01, ZaktualizujPrzebieg) {
     Samochod auto1(0, "Toyota", "Corolla", 2015, 4, "Dostepny", 5000);
     auto1.zaktualizujPrzebieg(1000);
     EXPECT_EQ(auto1.getAktualnyPrzebieg(), 5000) << "Przebieg nie powinien zostac zaktualizowany na mniejszy!";

     Samochod auto2(2, "Ford", "Focus", 2010, 4, "Serwis", 1000);
     auto2.zaktualizujPrzebieg(2000);
     EXPECT_EQ(auto2getAktualnyPrzebieg(), 2000) << "Przebieg powinien zostac zaktualizowany!";
}

int main(int argc, char **argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
