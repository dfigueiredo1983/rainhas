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
  while (file.get(caractere))
  {
    if (isalpha(caractere))
      return -1;

    if (isdigit(caractere) && !(caractere == '0' || caractere == '1'))
      return -1;
  }

  return 0;
}

int valida_linhas(const std::string &filename)
{
  ifstream file(filename);
  string line;
  int nLine = 0;
  while (getline(file, line))
  {
    nLine++;
  }

  if (nLine != 8)
    return -1;

  return 0;
}

int valida_colunas(const std::string &filename)
{
  ifstream file(filename);
  string line;
  int nColumn = 0;
  while (getline(file, line))
  {
    cout << line.length() << endl;
  }

  return 0;
}

int rainhas(const std::string &filename)
{
  int valida_arquivo = valida_arquivo_entrada(filename);
  if (valida_arquivo == -1)
    return -1;

  int linhas = valida_linhas(filename);
  if (linhas == -1)
    return -1;

  return 0;
}
