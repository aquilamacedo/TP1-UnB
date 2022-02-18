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
#endif // !TESTES_H_INCLUDED
