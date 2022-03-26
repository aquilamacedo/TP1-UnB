#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <string>
// #include <bits/stdc++.h>
#include "dominios.h"
#include "entidades.h"

using namespace std;

// --------------------------------------------------------------------------
// Declaração de classe para teste Código. matricula:200060295
// --------------------------------------------------------------------------

class TUCodigo
{
private:
  string VALOR_VALIDO = "0000026";
  string VALOR_INVALIDO = "0000020";
  Codigo *codigo;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

// --------------------------------------------------------------------------
// Declaração de classe para teste Titulo. matricula:200060295
// --------------------------------------------------------------------------

class TUTitulo
{
private:
  string VALOR_VALIDO = "Ex. de Titulo valido";
  string VALOR_INVALIDO = "Ex.. de Titulo invalido";
  Titulo *titulo;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

// --------------------------------------------------------------------------
// Declaração de classe para teste Horario. matricula:200060295
// --------------------------------------------------------------------------

class TUHorario
{
private:
  string VALOR_VALIDO = "04:58";
  string VALOR_INVALIDO = "04:65";
  Horario *horario;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

// --------------------------------------------------------------------------
// Declaração de classe da classe Nota. matricula:200060295
// --------------------------------------------------------------------------

class TUNota
{
private:
  int VALOR_VALIDO = 5;
  int VALOR_INVALIDO = 9;
  Nota *nota;
  int estado;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

/// --------------------------------------------------------------------------------------------------
/// Implementacao classes de teste de unidade de dominios (Email, Data, Descricao, Endereco, Idioma).
/// Matricula: 202021800
/// --------------------------------------------------------------------------------------------------

class TUEmail
{
private:
  const string EMAIL_VALIDO = "aquilamacedo@riseup.net";
  const string EMAIL_INVALIDO = "Aq$u1l4{m#ce$+=do.@r1sE-upnet";
  Email *email;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUData
{
private:
  const string DATA_VALIDA = "29-Fev-2020";
  const string DATA_INVALIDA = "29/Fev/2020";
  Data *data;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUDescricao
{
private:
  const string DESCRICAO_VALIDA = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  const string DESCRICAO_INVALIDA = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
  Descricao *descricao;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUEndereco
{
private:
  const string ENDERECO_VALIDO = "Toronto, Canada";
  const string ENDERECO_INVALIDO = "Cidade do Mexico, Mexico";
  Endereco *endereco;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUIdioma
{
private:
  const string IDIOMA_VALIDO = "Portugues";
  const string IDIOMA_INVALIDO = "Japones";
  Idioma *idioma;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

/// ------------------------------------------------------------------------------------------
/// Implementacao classes de teste de unidade de dominios (nome, senha, cidade, duracao).
/// Matricula: 202021767
/// ------------------------------------------------------------------------------------------

class TUNome
{
private:
  string NOME_VALIDO = "Felipe";
  string NOME_INVALIDO = ".fel";
  Nome *nome;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUSenha
{
private:
  string SENHA_VALIDA = "F3lipe";
  string SENHA_INVALIDA = "FELPPP";
  Senha *senha;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUCidade
{
private:
  string CIDADE_VALIDA = "Bangkok";
  string CIDADE_INVALIDA = "Asa Norte";
  Cidade *cidade;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

class TUDuracao
{
private:
  string DURACAO_VALIDA = "180";
  string DURACAO_INVALIDA = "200";
  Duracao *duracao;
  void setUp();
  void tearDown();
  void testarCenarioSucesso();
  void testarCenarioFalha();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int estado;
  int run();
};

/// ------------------------------------------------------------------------------------------------
/// Implementacao classes de teste de unidade de entidades (TUUsuario, TUAvaliacao).
/// Matricula: 200060295
/// ------------------------------------------------------------------------------------------------

class TUUsuario
{
private:
  string VALOR_VALIDO_NOME = "Felipe";
  string VALOR_INVALIDO_NOME = ".fel";
  string VALOR_VALIDO_EMAIL = "teste@unb.com.br";
  string VALOR_INVALIDO_EMAIL = "@teste@@.com.br";
  string VALOR_VALIDO_SENHA = "F3lipe";
  string VALOR_INVALIDO_SENHA = "FELPPP";
  Usuario *usuario;
  int estado;
  void setUp();
  void tearDown();
  void testar();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUAvaliacao
{
private:
  string VALOR_VALIDO_CODIGO = "0000026";
  string VALOR_INVALIDO_CODIGO = "0000020";
  const static int VALOR_VALIDO_NOTA = 2;
  const static int VALOR_INVALIDO_NOTA = 1000000;
  string VALOR_VALIDO_DESCRICAO = "Isso eh uma descricao";
  string VALOR_INVALIDO_DESCRICAO = "  @!#Nao eh  ..";
  Avaliacao *avaliacao;
  int estado;
  void setUp();
  void tearDown();
  void testar();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

/// ------------------------------------------------------------------------------------------------
/// Implementacao classes de teste de unidade de entidades (TUExcursao, TUSessao).
/// Matricula: 202021800
/// ------------------------------------------------------------------------------------------------

class TUExcursao
{
private:
  string VALOR_VALIDO_CODIGO = "0000026";
  string VALOR_INVALIDO_CODIGO = "0000020";
  string VALOR_VALIDO_TITULO = "Git Workflow";
  string VALOR_INVALIDO_TITULO = "InV!";
  const static int VALOR_VALIDO_NOTA = 3;
  const static int VALOR_INVALIDO_NOTA = 1337;
  string VALOR_VALIDO_CIDADE = "Macau";
  string VALOR_INVALIDO_CIDADE = "Toronto";
  string VALOR_VALIDO_DURACAO = "120";
  string VALOR_INVALIDO_DURACAO = "1999";
  string VALOR_VALIDO_DESCRICAO = "When see a good move";
  string VALOR_INVALIDO_DESCRICAO = "When you see a good move look for a better one";
  string VALOR_VALIDO_ENDERECO = "Toronto, Canada";
  string VALOR_INVALIDO_ENDERECO = "Toronto  Canada..";
  Excursao *excursao;
  int estado;
  void setUp();
  void tearDown();
  void testar();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

class TUSessao
{
private:
  string VALOR_VALIDO_CODIGO = "1929827";
  string VALOR_INVALIDO_CODIGO = "0000020";
  string VALOR_VALIDO_DATA = "29-Fev-2020";
  string VALOR_INVALIDO_DATA = "29/Fev/2222";
  string VALOR_VALIDO_HORARIO = "23:00";
  string VALOR_INVALIDO_HORARIO = "23h00";
  string VALOR_VALIDO_IDIOMA = "Portugues";
  string VALOR_INVALIDO_IDIOMA = "Alemao";
  Sessao *sessao;
  int estado;
  void setUp();
  void tearDown();
  void testar();

public:
  const static int SUCESSO = 0;
  const static int FALHA = -1;
  int run();
};

#endif
