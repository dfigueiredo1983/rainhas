// Copyright 2024 Daniel do Carmo Figueiredo

#include "rainhas.hpp"
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cerrno>
#include <string.h>

/**
 * @brief Esta é uma breve descrição do projeto das 8 Rainhas.
 *
 * O projeto consiste em verificar um tabuleiro com 8 linhas, 8 colunas e 8 Rainhas.
 * As rainhas devem ser dispostas no tabuleiro de forma que ela não seja atacada por outras rainhas já presentes no tabuleiro
 * Os movimentos que uma rainha pode fazer são:
 *     movimento para as laterais, tanto para a direita quanto para a esquerda
 *     movimento para cima e para baixo
 *     movimento nas diagonais a direita ou a esquerda, tanto de baixo para cima, quanto de cima para baixo
 * Caso uma rainha seja coloca em uma posição onde outra rainha já disposta no tabuleiro possa atacá-la, então
 * devemos salvar o movimento de ataque e eliminar a rainha atacada do tabuleiro
 */

int valida_arquivo_entrada(const std::string &filename)
{
  std::ifstream file(filename);
  if (!file)
    return -1;

  char caractere;
  int numColunas = 0;
  int numLinhas = 0;
  while (file.get(caractere))
  {
    if (isalpha(caractere))
      return -1;

    if (isdigit(caractere) && !(caractere == '0' || caractere == '1'))
      return -1;

    if (caractere == '\n')
    {
      if (numColunas != 8)
        return -1;

      numColunas = 0;
      numLinhas++;
    }
    else
    {
      ++numColunas;
    }
  }

  if (numLinhas != 7)
    return -1;

  file.close();

  return 0;
}

int game(const std::string &filename)
{
  if (valida_arquivo_entrada(filename) == -1)
    return -1;

  std::ifstream file(filename);
  std::string linha;
  int tabuleiro[8][8];
  int j = 0;
  while (getline(file, linha))
  {
    for (int i = 0; i < 8; i++)
    {
      tabuleiro[j][i] = linha[i] - '0';
    }
    j++;
  }
  file.close();

  std::ostringstream oss;

  int nao_solucao = 1;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (tabuleiro[i][j] == 1)
      {
        int numRainhasLinha = 0; // Verifica rainhas na mesma linha
        for (int m = j + 1; m < 8; m++)
        {
          if (tabuleiro[i][m] == 1)
            numRainhasLinha++;

          if (numRainhasLinha > 0)
          {
            oss << "Linha " << i << ", " << j << " - " << i << ", " << m << '\n';
            tabuleiro[i][j] = 0;
            nao_solucao = 0;
            break;
          }
        }
        numRainhasLinha = 0;
      }
    }
  }

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (tabuleiro[i][j] == 1)
      {
        int numRainhasColuna = 0; // verifica rainha na mesma coluna
        for (int n = i + 1; n < 8; n++)
        {
          if (tabuleiro[n][j] == 1)
            numRainhasColuna++;

          if (numRainhasColuna > 0)
          {
            oss << i << ", " << j << " - " << n << ", " << j << '\n';
            tabuleiro[i][j] = 0;
            nao_solucao = 0;
            break;
          }
        }
        numRainhasColuna = 0;
      }
    }
  }

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (tabuleiro[i][j] == 1)
      {
        for (int n = i + 1, m = j + 1; n < 8 && m < 8; n++, m++) // (0,1), (1,2), (3,2), ... (6,7) -  Diagonal principal
        {
          if (tabuleiro[n][m] == 1)
          {
            oss << i << ", " << j << " - " << n << ", " << m << '\n';
            tabuleiro[i][j] = 0;
            nao_solucao = 0;
            break;
          }
        }
        for (int n = i + 1, m = j - 1; m >= 0 && n < 8; n++, m--) // (0,5), (1,4), (2,3), ... (5,0) - Diagonal secundária
        {
          if (tabuleiro[n][m] == 1)
          {
            oss << i << ", " << j << " - " << n << ", " << m << '\n';
            tabuleiro[i][j] = 0;
            nao_solucao = 0;
            break;
          }
        }
      }
    }
  }

  std::string result = oss.str();
  std::string fileNameString(filename);

  std::string arquivoTeste = "ataques/ataques - " + fileNameString.erase(0, 11);
  const char *nameFile = arquivoTeste.c_str();

  if (nao_solucao == 1)
  {
    return 1;
  }
  else
  {
    std::ofstream ataques;
    ataques.open(nameFile, std::ios::out);
    std::string result = oss.str();
    ataques << result;
    ataques.close();

    return 0;
  }
}

/**
 * @brief Função principal.
 *
 * Esta função recebe um parâmetro do tipo string, que é o nome do arquivo com o
 * tabuleiro a ser analisado
 *
 * Ele irá retornar:
 *      1 - caso o arquivo seja solução para o problema
 *      0 - caso o arquivo não seja solução para o problema e nesse caso
 *          um arquivo contendo os ataques das rainhas
 *     -1 - caso não seja solução, por exemplo um tabuleiro que não é 8x8,
 *          com caracteres inválidos, com mais ou menos de 8 rainhas
 *
 * @param filename - nome do arquivo a ser analisado
 *
 * @return valida_game
 */

int rainhas(const std::string &filename)
{
  int valida_game = game(filename);

  return valida_game;
}
