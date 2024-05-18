// Copyright 2024 Daniel do Carmo Figueiredo

#include "rainhas.hpp"
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

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
      tabuleiro[i][j] = linha[i] - '0';
    }
    j++;
  }

  file.close();

  int nao_solucao = 1;
  int numRainhasLinha = 0; // Verifica rainhas na mesma linha
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      std::cout << tabuleiro[i][j];
      if (tabuleiro[i][j] == 1)
        numRainhasLinha++;

      if (numRainhasLinha > 1)
        nao_solucao = 0;
    }
    numRainhasLinha = 0;
  }

  std::cout << std::endl;

  int numRainhasColuna = 0; // verifica rainha na mesma coluna
  for (int i = 0; i < 8; i++)
  {
    for (int j = i; j <= i + 7 * 8;)
    {
      if (tabuleiro[i][j] == 1)
        numRainhasColuna++;

      if (numRainhasColuna > 1)
        nao_solucao = 0;

      j += 8;
    }
    numRainhasColuna = 0;
  }

  return nao_solucao;
}

int rainhas(const std::string &filename)
{
  int valida_game = game(filename);

  return valida_game;
}
