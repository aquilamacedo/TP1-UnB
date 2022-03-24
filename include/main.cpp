#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include "dominios.h"
#include "testes.h"
#include <regex>

using namespace std;

int main() {

  TUEmail testeEmail;
  TUData testeData;
  TUDescricao testeDescricao;
  TUEndereco testeEndereco; 
  TUIdioma testeIdioma;
  TUNome testeNome;
  TUSenha testeSenha;
  TUCidade testeCidade;
  TUDuracao testeDuracao;
  TUCodigo testeCodigo;
  TUTitulo testeTitulo;
  TUHorario testeHorario;
  TUNota testeNota;
  TUUsuario testeUsuario;
  TUAvaliacao testeAvaliacao;
  TUExcursao testeExcursao;
  TUSessao testeSessao;

  /// -------------------------------------------------------------------------------------------------------------
  /// Invocacao dos testes de unidade de Email, Data, Descricao, Endereco, Idioma, Codigo, Titulo, Horario e Nota. 
  /// Matricula: 202021800
  /// -------------------------------------------------------------------------------------------------------------

  switch(testeEmail.run()) {
    case TUEmail::SUCESSO:
      cout << "[*] SUCESSO - EMAIL" << endl;
      break;

    case TUEmail::FALHA:
      cout << "[*] FALHA - EMAIL" << endl;
      break;
  }

  switch(testeData.run()) {
    case TUData::SUCESSO:
      cout << "[*] SUCESSO - DATA" << endl;
      break;

    case TUData::FALHA:
      cout << "[*] FALHA - DATA" << endl;
      break;
  }

  switch(testeDescricao.run()) {
    case TUDescricao::SUCESSO:
      cout << "[*] SUCESSO - DESCRICAO" << endl;
      break;

    case TUDescricao::FALHA:
      cout << "[*] FALHA - DESCRICAO" << endl;
      break;
  }

  switch(testeEndereco.run()) {
    case TUEndereco::SUCESSO:
      cout << "[*] SUCESSO - ENDERECO" << endl;
      break;

    case TUEndereco::FALHA:
      cout << "[*] FALHA - ENDERECO" << endl;
      break;
  }

  switch(testeIdioma.run()) {
    case TUIdioma::SUCESSO:
      cout << "[*] SUCESSO - IDIOMA" << endl;
      break;

    case TUIdioma::FALHA:
      cout << "[*] FALHA - IDIOMA" << endl;
      break;
  }

  switch(testeCodigo.run()) {
    case TUCodigo::SUCESSO:
      cout << "[*] SUCESSO - CODIGO" << endl;
      break;

    case TUCodigo::FALHA:
      cout << "[*] FALHA - CODIGO" << endl;
      break;
  }

  switch(testeTitulo.run()) {
    case TUTitulo::SUCESSO:
      cout << "[*] SUCESSO - TITULO" << endl;
      break;

    case TUTitulo::FALHA:
      cout << "[*] FALHA - TITULO" << endl;
      break;
  }

  switch(testeHorario.run()) {
    case TUHorario::SUCESSO:
      cout << "[*] SUCESSO - HORARIO" << endl;
      break;

    case TUHorario::FALHA:
      cout << "[*] FALHA - HORARIO" << endl;
      break;
  }

  switch(testeDuracao.run()) {
    case TUDuracao::SUCESSO:
      cout << "[*] SUCESSO - DURACAO" << endl;
      break;

    case TUDuracao::FALHA:
      cout << "[*] FALHA - DURACAO" << endl;
      break;
  }

  /// -------------------------------------------------------------------------------
  /// Invocacao dos testes de unidade de nome, senha, cidade e duracao
  /// Matricula: 202021767
  /// -------------------------------------------------------------------------------

  switch(testeNome.run()) {
    case TUNome::SUCESSO: 
      cout << "[*] SUCESSO - NOME" << endl;
      break;
      
    case TUNome::FALHA: 
      cout << "[*] FALHA - NOME" << endl;
      break;
  }

  switch(testeSenha.run()) {
    case TUSenha::SUCESSO: 
      cout << "[*] SUCESSO - SENHA" << endl;
      break;

    case TUSenha::FALHA: 
      cout << "[*] FALHA - SENHA" << endl;
      break;
  }

  switch(testeCidade.run()) {
    case TUCidade::SUCESSO:
      cout << "[*] SUCESSO - CIDADE" << endl;
      break;

    case TUCidade::FALHA:
      cout << "[*] FALHA - CIDADE" << endl;
      break;
  }

  switch(testeDuracao.run()) {
    case TUDuracao::SUCESSO: 
      cout << "[*] SUCESSO - DURACAO" << endl;
      break;
      
    case TUDuracao::FALHA: 
      cout << "[*] FALHA - DURACAO" << endl;
      break;
  }
  
  /// -------------------------------------------------------------------------------------
  /// Invocacao dos testes de unidade das entidades Usuario, Avaliacao, Excursao e Sessao.
  /// Matricula: 202021800
  /// -------------------------------------------------------------------------------------

  switch(testeUsuario.run()) {
    case TUUsuario::SUCESSO:
      cout << "[*] SUCESSO - USUARIO" << endl;
      break;

    case TUUsuario::FALHA:
      cout << "[*] FALHA - USUARIO" << endl;
      break;
  }

  switch(testeAvaliacao.run()) {
    case TUAvaliacao::SUCESSO:
      cout << "[*] SUCESSO - AVALIACAO" << endl;
      break;

    case TUAvaliacao::FALHA:
      cout << "[*] FALHA - AVALIACAO" << endl;
      break;
  }

  switch(testeExcursao.run()) {
    case TUExcursao::SUCESSO:
      cout << "[*] SUCESSO - EXCURSAO" << endl;
      break;

    case TUExcursao::FALHA:
      cout << "[*] FALHA - EXCURSAO" << endl;
      break;
  }

  switch(testeSessao.run()) {
    case TUSessao::SUCESSO:
      cout << "[*] SUCESSO - SESSAO" << endl;
      break;

    case TUSessao::FALHA:
      cout << "[*] FALHA - SESSAO" << endl;
      break;
  }
  return 0;
}
