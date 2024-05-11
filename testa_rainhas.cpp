#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE("Arquivos de entrada validos", "[rainhas]")
{
    REQUIRE(rainhas("teste_valido.txt") == 0);
}
