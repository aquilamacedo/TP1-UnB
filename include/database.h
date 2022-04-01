#ifndef DATABASE_H
#define DATABASE_H

#include <list>

// Posteriomente remover.

#include <stdio.h>
#include <iostream>
#include <ncurses.h>
#include <string>

#include "sqlite3.h"
#include "entidades.h"

using namespace std;

//---------------------------------------------------------------------------
//Classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//---------------------------------------------------------------------------
//Classe ElementoResultado.

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

//---------------------------------------------------------------------------
//Classe ComandoSQL.

class ComandoSQL {
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
    ComandoSQL() {
      nomeBancoDados = "database.db";                             //Informa o nome do banco de dados.
    }
    void executar();
};
/*
class ComandoSenha:public ComandoSQL {
  public:
    ComandoSenha(Email);
    string getResultado();
};
*/

class ComandoCadastrarUsuario:public ComandoSQL {
  public:
    ComandoCadastrarUsuario(Usuario);
};

class ComandoDescadastrarUsuario:public ComandoSQL {
  public:
    ComandoDescadastrarUsuario(Email);
};

#endif // DATABASE_H