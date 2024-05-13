// Copyright 2024 Daniel do Carmo Figueiredo

#include "rainhas.hpp"
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int valida_arquivo_entrada(const std::string &filename)
{
  ifstream file(filename);
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
  vector<int> tabuleiro;

  ifstream file(filename);
  if (!file)
    return -1;

  char caractere;
  while (file.get(caractere)) // Converte as linhas do arquivo em um array de inteiros
  {
    if (caractere != '\n')
    {
      tabuleiro.push_back(caractere - '0');
    }
  }

  file.close();

  int numRainhasLinha = 0;
  for (size_t i = 0; i < tabuleiro.size(); i++)
  {

    cout << tabuleiro.at(i);
    if (tabuleiro.at(i) == 1)
      numRainhasLinha++;

    if (numRainhasLinha > 1)
    {
      cout << "Linha com mais de 1 rainha: " << numRainhasLinha << endl;
      return -1;
    }

    if (i % 7 == 0)
    {
      numRainhasLinha = 0;
      cout << endl;
    }
  }

  return 0;
}

int rainhas(const std::string &filename)
{
  int valida_arquivo = valida_arquivo_entrada(filename);
  if (valida_arquivo == -1)
    return -1;

  int valida_game = game(filename);
  if (valida_game == -1)
    return -1;

  return 0;
}
