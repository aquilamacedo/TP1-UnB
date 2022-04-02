#ifndef DATABASE_H
#define DATABASE_H

#include <list>

#include <stdio.h>
#include <iostream>
#include <string>

#include "sqlite3.h"
#include "entidades.h"

using namespace std;

//---------------------------------------------------------------------------
//Classe EErroPersistencia.

class EErroPersistencia
{
private:
  string mensagem;

public:
  EErroPersistencia(string);
  string what();
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

class ElementoResultado
{
private:
  string nomeColuna;
  string valorColuna;

public:
  void setNomeColuna(const string &);
  string getNomeColuna() const;
  void setValorColuna(const string &);
  string getValorColuna() const;
};

inline string ElementoResultado::getNomeColuna() const
{
  return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const
{
  return valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL
{
private:
  const char *nomeBancoDados;
  sqlite3 *bd;
  char *mensagem;
  int rc;
  void conectar();
  void desconectar();
  static int callback(void *, int, char **, char **);

protected:
  static list<ElementoResultado> listaResultado;
  string comandoSQL;

public:
  ComandoSQL()
  {
    nomeBancoDados = "database.db"; //Informa o nome do banco de dados.
  }
  void executar();
};

class ComandoSenha : public ComandoSQL
{
public:
  ComandoSenha(Email);
  string getResultado();
};

class ComandoCadastrarUsuario : public ComandoSQL
{
public:
  ComandoCadastrarUsuario(Usuario);
};

class ComandoDescadastrarUsuario : public ComandoSQL
{
public:
  ComandoDescadastrarUsuario(Email);
};

class ComandoEditarUsuario : public ComandoSQL
{
public:
  ComandoEditarUsuario(Usuario);
};

//class ComandoPesquisarUsuario:public ComandoSQL {
//  public:
//    ComandoPesquisarUsuario(Email);
//    Usuario getResultado();
//};

//--------------------------------------------------------------------------------------
//|                                 Excursão                                           |
//--------------------------------------------------------------------------------------

class NextIdExcursao : public ComandoSQL
{
public:
  NextIdExcursao();
  int getResultado();
};

class ComandoCadastrarExcursao : public ComandoSQL
{
public:
  ComandoCadastrarExcursao(Excursao);
};

class ComandoDescadastrarExcursao : public ComandoSQL
{
public:
  ComandoDescadastrarExcursao(Codigo);
};

class ComandoEditarExcursao : public ComandoSQL
{
public:
  ComandoEditarExcursao(Excursao);
};

class ComandoListarExcursoes : public ComandoSQL
{
public:
  ComandoListarExcursoes();
};
#endif // DATABASE_H
