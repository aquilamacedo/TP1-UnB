#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include "dominios.h"
#include "testes.h"

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

  switch(testeEmail.run()) {
    case TUEmail::SUCESSO:
      cout << "SUCESSO - EMAIL" << endl;
      break;

    case TUEmail::FALHA:
      cout << "FALHA - EMAIL" << endl;
      break;
  }

  switch(testeData.run()) {
    case TUData::SUCESSO:
      cout << "SUCESSO - DATA" << endl;
      break;

    case TUData::FALHA:
      cout << "FALHA - DATA" << endl;
      break;
  }

  switch(testeDescricao.run()) {
    case TUDescricao::SUCESSO:
      cout << "SUCESSO - DESCRICAO" << endl;
      break;

    case TUDescricao::FALHA:
      cout << "FALHA - DESCRICAO" << endl;
      break;
  }

  switch(testeEndereco.run()) {
    case TUEndereco::SUCESSO:
      cout << "SUCESSO - ENDERECO" << endl;
      break;

    case TUEndereco::FALHA:
      cout << "FALHA - ENDERECO" << endl;
      break;
  }

  switch(testeIdioma.run()) {
    case TUIdioma::SUCESSO:
      cout << "SUCESSO - IDIOMA" << endl;
      break;

    case TUIdioma::FALHA:
      cout << "FALHA - IDIOMA" << endl;
      break;
  }

/// -------------------------------------------------------------------------------
/// Invocação dos testes de unidade de nome, senha, cidade e duracao
/// Matricula: 202021767
/// -------------------------------------------------------------------------------

  switch(testeNome.run()){
      case TUNome::SUCESSO: 
        cout << "SUCESSO - NOME" << endl;
        break;
        
      case TUNome::FALHA: 
        cout << "FALHA - NOME" << endl;
        break;
    }

    switch(testeSenha.run()){
        case TUSenha::SUCESSO: 
          cout << "SUCESSO - SENHA" << endl;
          break;

        case TUSenha::FALHA: 
          cout << "FALHA - SENHA" << endl;
          break;
    }

    switch(testeCidade.run()){
        case TUCidade::SUCESSO: 
          cout << "SUCESSO - CIDADE" << endl;
          break;

        case TUCidade::FALHA: 
          cout << "FALHA - CIDADE" << endl;
          break;
    }

    switch(testeDuracao.run()){
        case TUDuracao::SUCESSO: 
          cout << "SUCESSO - DURACAO" << endl;
          break;
          
        case TUDuracao::FALHA: 
          cout << "FALHA - DURACAO" << endl;
          break;
    }

  return 0;
}

