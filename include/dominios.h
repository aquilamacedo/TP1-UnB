/**
 * @file dominios.h
 *
 * @brief file with the declaration of the program's domain classes
 *
 * @author Aquila Macedo - 202021800
 *
 */

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <string>

#define ll long long;

using namespace std;

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Email {
  private:
    string email;
    const static int TAMANHO_MAX = 253;
    void validar(string) throw (invalid_argument);
  
  public:
    Email(); // default
    Email(string);

    void setEmail(string);

    string getEmail() const {
      return email;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Nome {
  private:
    string nome;
    const static unsigned int TAMANHO_MIN = 5;
    const static unsigned int TAMANHO_MAX = 20;
    void validar(string) throw (invalid_argument);

  public:
    Nome(); // default
    Nome(string);

    void setNome(string);

    string getNome() const {
      return nome;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Senha {
  private:
    string senha;
    const static unsigned int TAMANHO_MAX = 6;
    void validar(string) throw (invalid_argument);

  public:
    Senha(); // default
    Senha(string);

    void setSenha(string);

    string getSenha() const {
      return senha;
    }
};

// ------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------



#endif // DOMINIOS_H_INCLUDED

