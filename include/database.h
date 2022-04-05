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
  list<int> valoresColunas;

public:
  void setNomeColuna(const string &);
  string getNomeColuna() const;
  void setValorColuna(const string &);
  string getValorColuna() const;
  list<int> getValoresColuna() const;
};

inline string ElementoResultado::getNomeColuna() const
{
  return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const
{
  return valorColuna;
}

inline list<int> ElementoResultado::getValoresColuna() const
{
  return valoresColunas;
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
class ListarExcursoes : public ComandoSQL
{
  ListarExcursoes();
};

class ComandoCadastrarExcursao : public ComandoSQL
{
public:
  ComandoCadastrarExcursao(Excursao, Email, int);
};

class ComandoDescadastrarExcursao : public ComandoSQL
{
public:
  ComandoDescadastrarExcursao(Codigo, Email);
};

class ComandoEditarExcursao : public ComandoSQL
{
public:
  ComandoEditarExcursao(Excursao, Email);
};

class ComandoListarExcursoes : public ComandoSQL
{
public:
  ComandoListarExcursoes();
};

//--------------------------------------------------------------------------------------
//|                                   Sessão                                           |
//--------------------------------------------------------------------------------------

class NextIdSessao : public ComandoSQL
{
public:
  NextIdSessao();
  int getResultado();
};

class ComandoCadastrarSessao : public ComandoSQL
{
public:
  ComandoCadastrarSessao(Sessao, Email, Codigo, int);
};

class ComandoDescadastrarSessao : public ComandoSQL
{
public:
  ComandoDescadastrarSessao(Codigo, Email);
};

class ComandoEditarSessao : public ComandoSQL
{
public:
  ComandoEditarSessao(Sessao, Email);
};

class ComandoRecuperarSessao : public ComandoSQL
{
public:
  ComandoRecuperarSessao(Codigo);
  Sessao getResultado();
};
class ComandoListarSessoes : public ComandoSQL
{
public:
  ComandoListarSessoes();
  ComandoListarSessoes(Excursao);
  list<Sessao> getResultado();
};
//--------------------------------------------------------------------------------------
//|                                 Avaliação                                          |
//--------------------------------------------------------------------------------------
class NextIdAvaliacao : public ComandoSQL
{
public:
  NextIdAvaliacao();
  int getResultado();
};

class GetNotasAvaliacao : public ComandoSQL
{
public:
  GetNotasAvaliacao();
  list<int> getResultado();
};

class ComandoCadastrarAvaliacao : public ComandoSQL
{
public:
  ComandoCadastrarAvaliacao(Avaliacao, Email, Codigo);
};

class ComandoDescadastrarAvaliacao : public ComandoSQL
{
public:
  ComandoDescadastrarAvaliacao(Codigo, Email);
};

class ComandoEditarAvaliacao : public ComandoSQL
{
public:
  ComandoEditarAvaliacao(Avaliacao, Email);
};

class ComandoListarAvaliacoes : public ComandoSQL
{
public:
  ComandoListarAvaliacoes(Email);
};
#endif // DATABASE_H
