/**
 * @file dominios.cpp
 *
 * @brief This file contains validation methods and defines domain classes.
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dominios.h"

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Email::Email() { }

Email::Email(string email) {
  this->email=email;
}

void Email::validar(string email) throw (invalid_argument) {
  if(email.size() > TAMANHO_MAX) {
    throw invalid_argument("O tamanho limite maximo do email foi excedido.");
    }
}

void Email::setEmail(string email) {
  validar(email);
  this->email=email;
}
// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Nome::Nome() { }

Nome::Nome(string nome) {
  this->nome=nome;
}

void Nome::validar(string nome) throw (invalid_argument) {
  if(nome.size() > TAMANHO_MAX) {
    throw invalid_argument("Nome Invalido. O tamanho limite maximo do nome foi excedido.");
    }
  else if(nome.size() < TAMANHO_MIN) {
    throw invalid_argument("Nome Invalido. O Tamanho limite minimo do nome nao foi satisfeito.");
  }

  for (int i = 0; i < nome.size(); i++) {
    if(!(isalpha(nome[i])) && nome[i] != '.' && nome[i] != ' ') {
      throw invalid_argument("Nome Invalido. Apenas os caracteres (A-Z ou a-z), ponto(.) ou espaço em branco devem ser utilizados");
    }
    if(nome[0] == '.') {
      throw invalid_argument("Nome Invalido. O primeiro caractere nao pode ser um ponto");
    }
    if(nome[i] == '.' && !(isalpha(nome[i-1]))) {
      throw invalid_argument("Nome Invalido. O Caractere precedente ao ponto nao pertence ao alfabeto(A-Z ou a-z)");
    }
    if(nome[i] == ' ' && (i != nome.size() - 1) && nome[i+1] == ' ') {
      throw invalid_argument("Nome Invalido. Nao pode ter espaco consecutivo");
    }
    if(!(isupper(nome[0])) && isalpha(nome[0]) || nome[i] == ' ' && !(isupper(nome[i+1])) && isalpha(nome[i+1])){
      throw invalid_argument("Nome Invalido. Todos os caracteres de um termo devem iniciar com letra maiscula");
    }
  }
}

void Nome::setNome(string nome) {
  validar(nome);
  this->nome=nome;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Senha::Senha() { }

Senha::Senha(string senha) {
  this->senha=senha;
}

void Senha::validar(string senha) throw (invalid_argument) {
  if(senha.size() > TAMANHO_MAX) {
    throw invalid_argument("O tamanho limite maximo da senha foi excedido.");
    }
}

void Senha::setSenha(string senha) {
  validar(senha);
  this->senha=senha;
}

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------

