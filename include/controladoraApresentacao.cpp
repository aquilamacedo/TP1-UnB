#include "controladoraApresentacao.h"
#include <string>
//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes controladoras.

void CntrApresentacaoControle::executar()
{

  // Mensagens a serem apresentadas na tela inicial.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Acessar sistema.";
  char texto3[] = "2 - Cadastrar usuario.";
  char texto4[] = "3 - Acessar dados sobre excursoes.";
  char texto5[] = "4 - Encerrar execucao do sistema.";

  // Mensagens a serem apresentadas na tela de sele��o de servi�o.

  char texto6[] = "Selecione um dos servicos : ";
  char texto7[] = "1 - Selecionar servicos de usuarios.";
  char texto8[] = "2 - Selecionar servicos relacionados a excursoes.";
  char texto9[] = "3 - Selecionar servicos relacionados a sessoes.";
  char texto10[] = "4 - Selecionar servicos relacionados a avaliacoes.";
  char texto11[] = "5 - Encerrar sessao.";

  char texto12[] = "Falha na autenticacao. Digite algo para continuar."; // Mensagem a ser apresentada.

  int campo; // Campo de entrada.

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela inicial.

    clear();                                           // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Imprime nome do campo.

    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      if (cntrApresentacaoAutenticacao->autenticar(&email))
      {                         // Solicita autentica��o.
        bool apresentar = true; // Controle de la�o.
        while (apresentar)
        {

          // Apresenta tela de sele��o de servi�o.

          clear();                                            // Limpa janela.
          mvprintw(linha / 4, coluna / 4, "%s", texto6);      // Imprime nome do campo.
          mvprintw(linha / 4 + 2, coluna / 4, "%s", texto7);  // Imprime nome do campo.
          mvprintw(linha / 4 + 4, coluna / 4, "%s", texto8);  // Imprime nome do campo.
          mvprintw(linha / 4 + 6, coluna / 4, "%s", texto9);  // Imprime nome do campo.
          mvprintw(linha / 4 + 6, coluna / 4, "%s", texto10); // Imprime nome do campo.
          mvprintw(linha / 4 + 6, coluna / 4, "%s", texto11); // Imprime nome do campo.
          // Apresenta tela de sele��o de servi�o.
          noecho();
          campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
          echo();

          switch (campo)
          {
          case 1:
            cntrApresentacaoUsuario->executar(email); // Solicita servi�o de pessoal.
            break;
          case 2:
            cntrApresentacaoExcursao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 3:
            cntrApresentacaoSessao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 4:
            cntrApresentacaoAvaliacao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 5:
            apresentar = false;
            break;
          }
        }
      }
      else
      {
        clear();                                        // Limpa janela.
        mvprintw(linha / 4, coluna / 4, "%s", texto12); // Imprime mensagem.
        noecho();                                       // Desabilita eco.
        getch();                                        // Leitura de caracter digitado.
        echo();                                         // Habilita eco.
      }
      break;
    case 2:
      cntrApresentacaoUsuario->cadastrar();
      break;
    case 3:
      cntrApresentacaoExcursao->executar();
      break;
    case 4:
      apresentar = false;
      break;
    }
  }
  return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Email *email)
{

  // Mensagens a serem apresentadas na tela de autentica��o.

  char texto1[] = "Digite o email  : ";
  char texto2[] = "Digite a senha: ";
  char texto3[] = "Dado em formato incorreto. Digite algo.";

  // Campos de entrada.

  char campo1[80];
  char campo2[80];

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  Senha senha; // Instancia a classe Senha.

  echo(); // Habilita eco.

  while (true)
  {

    // Apresenta tela de autentica��o.

    clear();                                       // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1); // Imprime nome do campo.
    getstr(campo1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    getstr(campo2);                                    // L� valor do campo.

    try
    {
      email->setEmail(string(campo1)); // Atribui valor ao Email.
      senha.setSenha(string(campo2));  // Atribui Valor � senha.
      break;                           // Abandona la�o em caso de formatos corretos.
    }
    catch (invalid_argument &exp)
    {                                                // Captura exce��o devido a formato incorreto.
      clear();                                       // Limpa janela.
      mvprintw(linha / 4, coluna / 4, "%s", texto3); // Informa formato incorreto.
      noecho();
      getch(); // L� caracter digitado.
      echo();
    }
  }
  return (cntr->autenticar(*email, senha)); // Solicita servi�o de autentica��o.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::executar(Email email)
{

  // Mensagens a serem apresentadas na tela de sele��o de servi�o..

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar dados pessoais.";
  char texto3[] = "2 - Consultar dados pessoais.";
  char texto4[] = "3 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  bool apresentar = true; // Controle de la�o.

  echo(); // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela de sela��o de servi�o.

    clear();                                           // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3); // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto4); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      consultarDadosUsuario();
      break;
    case 2:
      // editarDadosUsuario();
      break;
    case 3:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::cadastrar()
{

  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nome            :";
  char texto3[] = "Email           :";
  char texto4[] = "Senha           :";
  char texto5[] = "Dados em formato incorreto. Digite algo.";
  char texto6[] = "Sucesso no cadastramento. Digite algo.";
  char texto7[] = "Falha no cadastramento. Digite algo.";

  char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Email email;
  Senha senha;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
  getstr(campo1);                                     // L� valor do campo.
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto3);  // Imprime nome do campo.
  getstr(campo2);                                     // L� valor do campo.
  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto4); // Imprime nome do campo.
  getstr(campo3);                                     // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    email.setEmail(string(campo2));
    senha.setSenha(string(campo3));
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 18, coluna / 4, "%s", texto5); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setEmail(email);
  usuario.setSenha(senha);

  if (cntrServicoUsuario->cadastrarUsuario(usuario))
  {
    mvprintw(linha / 4 + 18, coluna / 4, "%s", texto6); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 18, coluna / 4, "%s", texto7); // Informa falha.
  noecho();
  getch();
  echo();

  return;
}

// //--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::consultarDadosUsuario()
{

  //--------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------
  // Substituir c�digo seguinte pela implementa��o do m�todo.
  //--------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------

  // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  char texto[] = "Servico consultar dados pessoais nao implementado. Digite algo."; // Mensagem a ser apresentada.
  clear();                                                                          // Limpa janela.
  mvprintw(linha / 4, coluna / 4, "%s", texto);                                     // Imprime nome do campo.
  noecho();
  getch();
  echo();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar excursões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  echo(); // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    clear();                                           // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarProdutoInvestimento();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar(Email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar conta corrente.";
  char texto3[] = "2 - Cadastrar produto de investimento.";
  char texto4[] = "3 - Descadastrar produto de investimento.";
  char texto5[] = "4 - Consultar produto de investimento.";
  char texto6[] = "5 - Realizar aplicacao em produto de investimento.";
  char texto7[] = "6 - Listar aplicacoes em produto de investimento.";
  char texto8[] = "7 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  echo(); // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  echo(); // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    clear();                                            // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Imprime nome do campo.
    mvprintw(linha / 4 + 14, coluna / 4, "%s", texto8); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarConta();
      break;
    case 2:
      // cadastrarProdutoInvestimento();
      break;
    case 3:
      // descadastrarProdutoInvestimento();
      break;
    case 4:
      // consultarProdutoInvestimento();
      break;
    case 5:
      // realizarAplicacao();
      break;
    case 6:
      // listarAplicacoes();
      break;
    case 7:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar excursões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  echo(); // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    clear();                                           // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarProdutoInvestimento();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar(Email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar conta corrente.";
  char texto3[] = "2 - Cadastrar produto de investimento.";
  char texto4[] = "3 - Descadastrar produto de investimento.";
  char texto5[] = "4 - Consultar produto de investimento.";
  char texto6[] = "5 - Realizar aplicacao em produto de investimento.";
  char texto7[] = "6 - Listar aplicacoes em produto de investimento.";
  char texto8[] = "7 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  echo(); // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  echo(); // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    clear();                                            // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Imprime nome do campo.
    mvprintw(linha / 4 + 14, coluna / 4, "%s", texto8); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarConta();
      break;
    case 2:
      // cadastrarProdutoInvestimento();
      break;
    case 3:
      // descadastrarProdutoInvestimento();
      break;
    case 4:
      // consultarProdutoInvestimento();
      break;
    case 5:
      // realizarAplicacao();
      break;
    case 6:
      // listarAplicacoes();
      break;
    case 7:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoAvaliacao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar excursões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  echo(); // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    clear();                                           // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarProdutoInvestimento();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar(Email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar conta corrente.";
  char texto3[] = "2 - Cadastrar produto de investimento.";
  char texto4[] = "3 - Descadastrar produto de investimento.";
  char texto5[] = "4 - Consultar produto de investimento.";
  char texto6[] = "5 - Realizar aplicacao em produto de investimento.";
  char texto7[] = "6 - Listar aplicacoes em produto de investimento.";
  char texto8[] = "7 - Retornar.";

  int campo; // Campo de entrada.

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  echo(); // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  echo(); // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    clear();                                            // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Imprime nome do campo.
    mvprintw(linha / 4 + 14, coluna / 4, "%s", texto8); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarConta();
      break;
    case 2:
      // cadastrarProdutoInvestimento();
      break;
    case 3:
      // descadastrarProdutoInvestimento();
      break;
    case 4:
      // consultarProdutoInvestimento();
      break;
    case 5:
      // realizarAplicacao();
      break;
    case 6:
      // listarAplicacoes();
      break;
    case 7:
      apresentar = false;
      break;
    }
  }
}

/*
//--------------------------------------------------------------------------------------------

// void CntrApresentacaoProdutosFinanceiros::consultarConta()
// {

//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------
//   // Substituir c�digo seguinte pela implementa��o do m�todo.
//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------

//   // Mensagens a serem apresentadas.

//   int linha, coluna;               // Dados sobre tamanho da tela.
//   getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

//   char texto[] = "Servico consultar conta nao implementado. Digite algo."; // Mensagem a ser apresentada.
//   clear();                                                                 // Limpa janela.
//   mvprintw(linha / 4, coluna / 4, "%s", texto);                            // Imprime nome do campo.
//   noecho();
//   getch();
//   echo();
// }

//--------------------------------------------------------------------------------------------

// void CntrApresentacaoProdutosFinanceiros::cadastrarProdutoInvestimento()
// {

//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------
//   // Substituir c�digo seguinte pela implementa��o do m�todo.
//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------

//   // Mensagens a serem apresentadas.

//   int linha, coluna;               // Dados sobre tamanho da tela.
//   getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

//   char texto[] = "Servico cadastrar produto investimento nao implementado. Digite algo."; // Mensagem a ser apresentada.
//   clear();                                                                                // Limpa janela.
//   mvprintw(linha / 4, coluna / 4, "%s", texto);                                           // Imprime nome do campo.
//   noecho();
//   getch();
//   echo();
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoProdutosFinanceiros::descadastrarProdutoInvestimento()
// {

//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------
//   // Substituir c�digo seguinte pela implementa��o do m�todo.
//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------

//   // Mensagens a serem apresentadas.

//   int linha, coluna;               // Dados sobre tamanho da tela.
//   getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

//   char texto[] = "Servico descadastrar produto investimento nao implementado. Digite algo."; // Mensagem a ser apresentada.
//   clear();                                                                                   // Limpa janela.
//   mvprintw(linha / 4, coluna / 4, "%s", texto);                                              // Imprime nome do campo.
//   noecho();
//   getch();
//   echo();
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoProdutosFinanceiros::consultarProdutoInvestimento()
// {

//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------
//   // Substituir c�digo seguinte pela implementa��o do m�todo.
//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------

//   // Mensagens a serem apresentadas.

//   int linha, coluna;               // Dados sobre tamanho da tela.
//   getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

//   char texto[] = "Servico consultar produto investimento nao implementado. Digite algo."; // Mensagem a ser apresentada.
//   clear();                                                                                // Limpa janela.
//   mvprintw(linha / 4, coluna / 4, "%s", texto);                                           // Imprime nome do campo.
//   noecho();
//   getch();
//   echo();
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoProdutosFinanceiros::realizarAplicacao()
// {

//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------
//   // Substituir c�digo seguinte pela implementa��o do m�todo.
//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------

//   // Mensagens a serem apresentadas.

//   int linha, coluna;               // Dados sobre tamanho da tela.
//   getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

//   char texto[] = "Servico realizar aplicacao nao implementado. Digite algo."; // Mensagem a ser apresentada.
//   clear();                                                                    // Limpa janela.
//   mvprintw(linha / 4, coluna / 4, "%s", texto);                               // Imprime nome do campo.
//   noecho();
//   getch();
//   echo();
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoProdutosFinanceiros::listarAplicacoes()
// {

//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------
//   // Substituir c�digo seguinte pela implementa��o do m�todo.
//   //--------------------------------------------------------------------------------------------
//   //--------------------------------------------------------------------------------------------

//   // Mensagens a serem apresentadas.

//   int linha, coluna;               // Dados sobre tamanho da tela.
//   getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

//   char texto[] = "Servico listar aplicacoes nao implementado. Digite algo."; // Mensagem a ser apresentada.
//   clear();                                                                   // Limpa janela.
//   mvprintw(linha / 4, coluna / 4, "%s", texto);                              // Imprime nome do campo.
//   noecho();
//   getch();
//   echo();
// }
*/