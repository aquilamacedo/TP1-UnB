#include "entidades.h"
#include "dominios.h"
#include "sqlite3.h"
#include "database.h"
#include <string>
#include <sstream>

//Atributo estatico container List.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
//Classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}


//---------------------------------------------------------------------------
//Classe ComandoSQL.

void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);

        if(rc != SQLITE_OK){
          sqlite3_free(mensagem);
          desconectar();
          throw EErroPersistencia("Erro na execucao do comando SQL");
        }

        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

ComandoSenha::ComandoSenha(Email email){
  comandoSQL = "SELECT senha FROM usuario WHERE email = '";
  // senha da tabela usuario onde email eh o getemail
  comandoSQL += email.getEmail();
  comandoSQL += "'";
}

string ComandoSenha::getResultado() {
  ElementoResultado resultado;
  string senha;

  if (listaResultado.empty()) {
    throw EErroPersistencia("Lista Vazia.");
  }

  resultado = listaResultado.back();
  listaResultado.pop_back(); // dado que a gente vai excluir

  senha = resultado.getValorColuna();

  return senha;
}

// ---------------------------------------------
// Implementação do comando Cadastrar Usuario
// ---------------------------------------------
ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario) {
        comandoSQL = "INSERT INTO usuario VALUES (";
        comandoSQL += "'" + usuario.getEmail().getEmail() + "', ";
        comandoSQL += "'" + usuario.getNome().getNome() + "', ";
        comandoSQL += "'" + usuario.getSenha().getSenha() + "')";
}


// ---------------------------------------------
// Implementação do comando Descadastrar Usuario
// ---------------------------------------------
ComandoDescadastrarUsuario::ComandoDescadastrarUsuario(Email email){
    comandoSQL = "DELETE FROM usuario WHERE email = '";
    comandoSQL += email.getEmail();
    comandoSQL += "'";
}

// ---------------------------------------------
// Implementação do comando Editar Usuário
// ---------------------------------------------

ComandoEditarUsuario::ComandoEditarUsuario(Usuario usuario) {
        comandoSQL = "UPDATE usuarios ";
        comandoSQL += "SET nome = '" + usuario.getNome().getNome();
        comandoSQL += "', senha = '" + usuario.getSenha().getSenha();
        comandoSQL += "' WHERE email = " + usuario.getEmail().getEmail();
}

//ComandoPesquisarUsuario::ComandoPesquisarUsuario(Email email) {}