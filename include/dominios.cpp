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

Codigo::Codigo() { };

Codigo::Codigo(string codigo) {
  this->codigo=codigo;
};

void Codigo::setCodigo(string codigo) {
    validarCodigo(codigo);
    this->codigo=codigo + "X";
};

void Codigo::validarCodigo(string codigo) throw (invalid_argument) {
  if (codigo == "0000000"){
  throw invalid_argument("Não existe esse codigo.");
  }
  if (codigo.size() != TAMANHO_MAX) {
    throw invalid_argument("O codigo tem que estar no padrão DDDDDD.");
    }else{
          for (int i = 0; i < codigo.size(); i++) {
            if (!isdigit(codigo[i])){
                throw invalid_argument("O codigo tem que possuir apenas numeros.");
            }
        }
    }
    };

// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------


Nota::Nota(int nota) {
  this->nota=nota;
};

void Nota::setNota(int nota) {
    validarNota(nota);
    this->nota=nota;
};

void Nota::validarNota(int nota) throw (invalid_argument) {
  if (!isdigit(nota)){
  throw invalid_argument("Nota não é número.");
  }
  if (nota != 0 || nota != 1 ||nota != 2 ||nota != 3 ||nota != 4 ||nota != 5) {
    throw invalid_argument("O codigo tem que estar no intervalo de 0-5.");
    }
};
// -------------------------------------------------------------------------------
// 
// -------------------------------------------------------------------------------

Descricao::Descricao() { };

Descricao::Descricao(string descricao) {
  this->descricao=descricao;
};

void Descricao::setDescricao(string nota) {
    validarDescricao(descricao);
    this->descricao=descricao;
};

void Descricao::validarDescricao(string descricao) throw (invalid_argument) {
  if(descricao.size() > TAMANHO_MAX) {
    throw invalid_argument("Descricao Invalido. O tamanho limite maximo do nome foi excedido.");
    };
  if(descricao.size() < TAMANHO_MIN) {
    throw invalid_argument("Descricao Invalido. O Tamanho limite minimo do nome nao foi satisfeito.");
  };
  for (int i = 0; i < descricao.size(); i++) {
    if(descricao[i] == ' ' && (i != descricao.size() - 1) && descricao[i+1] == ' '){
     throw invalid_argument("Há espaços em branco em sequência");
    };
    if(descricao[i] == '.' && (i != descricao.size() - 1) && descricao[i+1] == '.'){
     throw invalid_argument("Há pontos em sequência");
    };
  }
};

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------


