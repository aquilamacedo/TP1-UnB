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

  // Here we'll check the tests for now.

  cout << "Hi, There" << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string x;
  string emailEntrada ("Aq$u1l4{m#ce$+=do@r1sE-upnet");

  Email email1;
  email1.setEmail(emailEntrada);
  x = email1.getEmail();

  cout << "Your email: " << x << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string y;
  string nomeEntrada ("Aquila Macedo");

  Nome nome1;
  nome1.setNome(nomeEntrada);
  y = nome1.getNome();

  cout << "Your name: " << y << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string z;
  string senhaEntrada("r4213M");

  Senha senha1;
  senha1.setSenha(senhaEntrada);
  z = senha1.getSenha();

  cout << "Your password: " << z << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string p;
  string dataEntrada ("29-Fev-2020");

  Data data1;
  data1.setData(dataEntrada);
  p = data1.getData();

  cout << "Date: " << p << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string q;
  string horarioEntrada ("23:00");

  Horario horario1;
  horario1.setHorario(horarioEntrada);
  q = horario1.getHorario();

  cout << "Time: " << q << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string r;
  string idiomaEntrada ("Portugues");

  Idioma idioma1;
  idioma1.setIdioma(idiomaEntrada);
  r = idioma1.getIdioma();

  cout << "Language: " << r << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string s;
  string tituloEntrada ("Git Workflow");

  Titulo titulo1;
  titulo1.setTitulo(tituloEntrada);
  s = titulo1.getTitulo();

  cout << "Title: " << s << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  int t;
  int notaEntrada (4);

  Nota nota1;
  nota1.setNota(notaEntrada);
  t = nota1.getNota();

  cout << "Note: " << t << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string u;
  string cidadeEntrada ("Macau");

  Cidade cidade1;
  cidade1.setCidade(cidadeEntrada);
  u = cidade1.getCidade();

  cout << "City: " << u << endl;

  // ------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string v;
  string duracaoEntrada ("120");

  Duracao duracao1;
  duracao1.setDuracao(duracaoEntrada);
  v = duracao1.getDuracao();

  cout << "Duracao: " << v << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string w;
  string descricaoEntrada ("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");

  Descricao descricao1;
  descricao1.setDescricao(descricaoEntrada);
  w = descricao1.getDescricao();

  cout << "Description: " << w << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string g;
  string enderecoEntrada ("Toronto, Canada");

  Endereco endereco1;
  endereco1.setEndereco(enderecoEntrada);
  g = endereco1.getEndereco();

  cout << "Address: " << g << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  string h;
  string codigoEntrada ("123111");

  Codigo codigo1;
  codigo1.setCodigo(codigoEntrada);
  h = codigo1.getCodigo();

  cout << "Code: " << h << endl;

  // -------------------------------------------------------------------------------
  //
  // -------------------------------------------------------------------------------

  return 0;
}

