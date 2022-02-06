#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>

#include "dominios.h"

using namespace std;

// Class Declaration

class Usuario {
  private:
    Nome nome;
    Email email;
    Senha senha;

  public:
    void setUsuario(string novoNome, string novoEmail, string novaSenha);

    void getUsuario(Nome *_Nome, Email *_Email, Senha *_Senha);
};

class Avaliacao {
    private:
    Codigo codigo;
    Nota nota;
    Descricao descricao;

    public:
    void setAvaliacao(string novoCodigo, int novaNota, string novaDescricao);
    void getAvaliacao(Codigo *_Codigo, Nota *_Nota, Descricao *_Descricao);
};

#endif // ENTIDADES_H_INCLUDED

