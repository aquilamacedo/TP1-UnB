#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dominios.h"

using namespace std;

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

const int Email::TAMANHO_MAX = 253;

void Email::validar(string email){
  // logica das regras e formatos do email
}

void Email::setEmail(string email){
  validar(email);
  this->email = email; // resolve as ambiguidades entre atributos 
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

const unsigned int Nome::TAMANHO_MIN = 5;
const unsigned int Nome::TAMANHO_MAX = 20;

void Nome::validar(string nome){
  //logica das regras e formatos do nome
}

void Nome::setNome(string nome){
  validar(nome);
  this->nome = nome;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

const unsigned int Senha::TAMANHO = 6;

void Senha::validar(string senha){
  //logica das regras e formatos da senha
}

void Senha::setSenha(string senha){
  validar(senha);
  this->senha = senha;
}
