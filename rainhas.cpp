// Copyright 2024 Daniel do Carmo Figueiredo

#include "rainhas.hpp"
// #include <bits/stdc++.h>
#include <cctype>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int rainhas(const std::string &filename)
{

  int valida_arquivo = valida_arquivo_entrada(filename);

  if (valida_arquivo == -1)
    return -1;

  if (valida_arquivo == -2)
    return -2;

  return 0;
}

int valida_arquivo_entrada(const std::string &filename)
{
  ifstream file(filename);
  if (!file)
    return -2;

  int numCaracteres = 0;
  char caractere;
  while (file.get(caractere))
  {
    if (isalpha(caractere))
      return -1;

    if (isdigit(caractere) && !(caractere == '0' || caractere == '1'))
      return -1;

    if (isdigit(caractere) && (caractere == '0' || caractere == '1'))
      numCaracteres++;

    if (numCaracteres != 64)
      return -1;
  }

  return 0;
}