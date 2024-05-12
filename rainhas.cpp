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
    return -2;

  return 0;
}

int rainhas(const std::string &filename)
{

  int valida_arquivo = valida_arquivo_entrada(filename);

  if (valida_arquivo == -2)
    return -2;

  return 0;
}
