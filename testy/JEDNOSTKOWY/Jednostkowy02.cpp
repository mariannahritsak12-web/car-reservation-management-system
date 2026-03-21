#include <gtest/gtest.h>
#include "src/Samochod.h"

TEST (SamochodJednostkowy03, czyDostepny) {
      Samochod s1(0, "Toyota", "Corolla", 2015, 4, "Dostepny", 5000);
      EXPECT_TRUE(s1.czyDostepny()) << "Samochod powinien byc dostepny zaraz po utworzeniu";
}
int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
}
