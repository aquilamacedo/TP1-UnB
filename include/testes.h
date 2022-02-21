#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"

class TUEmail {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUData {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUDescricao {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUEndereco {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUIdioma {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

/// ------------------------------------------------------------------------------------------
/// Implementacao classes de teste de unidade de dominios(nome, senha, cidade, duracao).
/// Matricula: 202021767
/// ------------------------------------------------------------------------------------------

class TUNome {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUSenha {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUCidade {
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
    const static int FALHA = 1;
    int estado;
    int run();
};

class TUDuracao {
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
    const static int FALHA = 1;
    int estado;
    int run();
};
#endif // !TESTES_H_INCLUDED
