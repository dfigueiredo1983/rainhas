#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

// TEST_CASE("Arquivos de entrada validos", "[rainhas]")
// {
//     REQUIRE(rainhas("tabuleiros/teste_valido.txt") == 0);
//     REQUIRE(rainhas("tabuleiros/qtde_linhas_invalido_1.txt") == -1);
//     REQUIRE(rainhas("tabuleiros/qtde_linhas_invalido_2.txt") == -1);
//     REQUIRE(rainhas("tabuleiros/qtde_colunas_invalido_1.txt") == -1);
//     REQUIRE(rainhas("tabuleiros/teste_invalido.txt") == -1);
// }

// TEST_CASE("Arquivos de entrada tem caracteres validos", "[rainhas]")
// {
//     REQUIRE(rainhas("tabuleiros/caracter_valido.txt") == 0);
//     REQUIRE(rainhas("tabuleiros/caracter_invalido.txt") == -1);
// }

// TEST_CASE("Arquivos de entrada tem valores diferentes de 0 ou 1", "[rainhas]")
// {
//     REQUIRE(rainhas("tabuleiros/numero_invalido.txt") == -1);
// }

TEST_CASE("Arquivos de entrada tem rainhas na mesma linha", "[rainhas]")
{
    REQUIRE(rainhas("tabuleiros/rainhas_mesma_linha_1.txt") == -1);
    REQUIRE(rainhas("tabuleiros/rainhas_mesma_linha_2.txt") == -1);
}

// TEST_CASE("Arquivos de entrada tem rainhas na mesma coluna", "[rainhas]")
// {
//     REQUIRE(rainhas("tabuleiros/rainhas_mesma_coluna_1.txt") == 0);
// }
