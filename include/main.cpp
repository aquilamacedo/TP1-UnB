#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include "dominios.h"
#include "dominios.cpp"

using namespace std;

int main() {
  // Here we'll check the tests for now.

  cout << "Hi, There" << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string x;
  string emailEntrada ("aquilamacedo@riseup.net");

  Email email1;
  email1.setEmail(emailEntrada);
  x = email1.getEmail();

  cout << "Your email: " << x << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string y;
  string nomeEntrada ("Aquila Macedo");

  Nome nome1;
  nome1.setNome(nomeEntrada);
  y = nome1.getNome();

  cout << "Your name: " << y << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string z;
  string senhaEntrada("r4nD0m");

  Senha senha1;
  senha1.setSenha(senhaEntrada);
  z = senha1.getSenha();

  cout << "Your password: " << z << endl;

  return 0;
}

