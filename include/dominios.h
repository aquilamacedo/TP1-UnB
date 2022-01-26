/**
 * @file dominios.h
 *
 * file with the declaration of the program's domain classes
 */

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>

#define ll long long;

using namespace std;

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Email{
  
  private:
    string email;
    const static int TAMANHO_MAX;
    void validar(string);
  
  public:
    void setEmail(string);
    string getEmail() const {
      return email;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Nome{
  private:
    string nome;
    const static unsigned int TAMANHO_MAX;
    const static unsigned int TAMANHO_MIN;
    void validar(string);
  public:
    void setNome(string);
    string getNome() const {
      return nome;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Senha{
  private:
    string senha;
    const static unsigned int TAMANHO;
    void validar(string);
  public:
    void setSenha(string);
    string getSenha() const {
      return senha;
    }
};

#endif // DOMINIOS_H_INCLUDED

