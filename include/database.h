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

class ComandoChecarUsuario : public ComandoSQL
{
public:
  ComandoChecarUsuario();
  list<string> getResultado();
};

class ComandoRecuperarUsuario : public ComandoSQL
{
public:
  ComandoRecuperarUsuario(Usuario);
  Usuario getResultado();
};

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

class ComandoRecuperarExcursao : public ComandoSQL
{
public:
  ComandoRecuperarExcursao(Codigo);
  Excursao getResultado();
};

class ComandoListarExcursoes : public ComandoSQL
{
public:
  ComandoListarExcursoes();
  list<Excursao> getResultado();
};

class ComandoChecarExcursao : public ComandoSQL
{
public:
  ComandoChecarExcursao(Email);
  list<string> getResultado();
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

class ComandoChecarSessao : public ComandoSQL
{
public:
  ComandoChecarSessao(Codigo, Email);
  bool getResultado();
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

class GetNotasMediaAvaliacao : public ComandoSQL
{
private:
  int codigo;

public:
  GetNotasMediaAvaliacao(int);
  float getResultado();
};

class GetNotasAvaliacao : public ComandoSQL
{
public:
  GetNotasAvaliacao(int);
  bool getResultado();
};

class ComandoCadastrarAvaliacao : public ComandoSQL
{
public:
  ComandoCadastrarAvaliacao(Avaliacao, Email, Codigo, int);
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

class ComandoAtualizarNotaExcursao : public ComandoSQL
{
public:
  ComandoAtualizarNotaExcursao(float, Email, Codigo);
};

class ComandoChecarAvaliacao : public ComandoSQL
{
public:
  ComandoChecarAvaliacao(Email);
  list<string> getResultado();
};

class ComandoRecuperarAvaliacao : public ComandoSQL
{
public:
  ComandoRecuperarAvaliacao(Codigo);
  Avaliacao getResultado();
};

class ComandoListarAvaliacoes : public ComandoSQL
{
public:
  ComandoListarAvaliacoes();
  list<Avaliacao> getResultado();
};
class ComandoListarAvaliacoesUsuario : public ComandoSQL
{
public:
  ComandoListarAvaliacoesUsuario(Usuario);
  list<Avaliacao> getResultado();
};
class ComandoListarAvaliacoesExcursao : public ComandoSQL
{
public:
  ComandoListarAvaliacoesExcursao(Excursao);
  list<Avaliacao> getResultado();
};

#endif // DATABASE_H
