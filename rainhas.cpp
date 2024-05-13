// Copyright 2024 Daniel do Carmo Figueiredo

#include "rainhas.hpp"
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>

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

int rainhas(const std::string &filename)
{
  int valida_arquivo = valida_arquivo_entrada(filename);
  if (valida_arquivo == -1)
    return -1;

  return 0;
}
