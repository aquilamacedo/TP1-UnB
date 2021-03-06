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
  char texto4[] = "3 - Acessar dados sobre excursões.";
  char texto5[] = "4 - Acessar dados sobre sessões.";
  char texto6[] = "5 - Acessar dados sobre avaliações.";
  char texto7[] = "6 - Encerrar execução do sistema.";

  // Mensagens a serem apresentadas na tela de sele��o de servi�o.

  char texto8[] = "Selecione um dos servicos : ";
  char texto9[] = "1 - Selecionar servicos de usuarios.";
  char texto10[] = "2 - Selecionar servicos relacionados a excursões.";
  char texto11[] = "3 - Selecionar servicos relacionados a sessões.";
  char texto12[] = "4 - Selecionar servicos relacionados a avaliações.";
  char texto13[] = "5 - Encerrar sessao.";

  char texto14[] = "Falha na autenticação. Digite algo para continuar."; // Mensagem a ser apresentada.

  int campo; // Campo de entrada.

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela inicial.

    clear();                                            // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Imprime nome do campo.

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

          clear();                                             // Limpa janela.
          mvprintw(linha / 4, coluna / 4, "%s", texto8);       // Imprime nome do campo.
          mvprintw(linha / 4 + 2, coluna / 4, "%s", texto9);   // Imprime nome do campo.
          mvprintw(linha / 4 + 4, coluna / 4, "%s", texto10);  // Imprime nome do campo.
          mvprintw(linha / 4 + 6, coluna / 4, "%s", texto11);  // Imprime nome do campo.
          mvprintw(linha / 4 + 8, coluna / 4, "%s", texto12);  // Imprime nome do campo.
          mvprintw(linha / 4 + 10, coluna / 4, "%s", texto13); // Imprime nome do campo.
          // Apresenta tela de sele��o de servi�o.
          noecho();
          campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
          echo();

          switch (campo)
          {
          case 1:
            cntrApresentacaoUsuario->executar(email);
            break;
          case 2:
            cntrApresentacaoExcursao->executar(email);
            break;
          case 3:
            cntrApresentacaoSessao->executar(email);
            break;
          case 4:
            cntrApresentacaoAvaliacao->executar(email);
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
        mvprintw(linha / 4, coluna / 4, "%s", texto14); // Imprime mensagem.
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
      cntrApresentacaoSessao->executar();
      break;
    case 5:
      cntrApresentacaoAvaliacao->executar();
      break;
    case 6:
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
  char texto2[] = "1 - Editar Dados.";
  char texto3[] = "2 - Excluir Cadastro.";
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
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      editarUsuario(email);
      break;
    case 2:
      descadastrar(email);
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

  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo2);                                    // L� valor do campo.
  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
  getstr(campo3);                                    // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    email.setEmail(string(campo2));
    senha.setSenha(string(campo3));
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Informa formato incorreto.
    noecho();                                          // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
    echo();                                            // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setEmail(email);
  usuario.setSenha(senha);

  if (cntrServicoUsuario->cadastrarUsuario(usuario))
  {
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto6); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto7); // Informa falha.
  noecho();
  getch();
  echo();

  return;
}

// //--------------------------------------------------------------------------------------------

bool CntrApresentacaoUsuario::descadastrar(Email email) {
  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  char texto1[]= "Sucesso. Usuario descadastrado.";
  char texto2[]= "Falha no descadastramento.";
  clear();

  if(cntrServicoUsuario->descadastrarUsuario(email)) {
    mvprintw(linha/4, coluna/4, "%s", texto1);
    noecho();
    getch();
    echo();

    return true;
  }

  mvprintw(linha/4, coluna/4, "%s", texto2);
  noecho();
  getch();
  echo();
  return false;
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

void CntrApresentacaoUsuario::editarUsuario(Email email)
{

  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nome            :";
  char texto3[] = "Senha           :";
  char texto4[] = "Dados em formato incorreto. Digite algo.";
  char texto5[] = "Sucesso na alteração. Digite algo.";
  char texto6[] = "Falha na alteração. Digite algo.";

  char campo1[80], campo2[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Senha senha;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo2);                                    // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    senha.setSenha(string(campo2));
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto4); // Informa formato incorreto.
    noecho();                                          // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
    echo();                                            // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setSenha(senha);
  usuario.setEmail(email);

  if (cntrServicoUsuario->editarUsuario(usuario))
  {
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto6); // Informa falha.
  noecho();
  getch();
  echo();

  return;
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
      // listarExcursoes();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar(Email email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Cadastrar Excursão.";
  char texto3[] = "2 - Consultar Excursão.";
  char texto4[] = "3 - Editar Excursão.";
  char texto5[] = "4 - Excluir Excursão.";
  char texto6[] = "5 - Retornar.";

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
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      cadastrarExcursao(email);
      break;
    case 2:
      consultarExcursao(email);
      break;
    case 3:
      editarExcursao(email);
      break;
    case 4:
      descadastrarExcursao(email);
      break;
    case 5:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoExcursao::consultarExcursao(Email email)
{
  return;
}

void CntrApresentacaoExcursao::cadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código          :";
  char texto3[] = "Título          :";
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          :";
  char texto5b[] = "Duração         :";
  char texto5c[] = "Descrição       :";
  char texto5d[] = "Endereço        :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";

  char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  // Codigo codigo;
  Titulo titulo;
  // Nota nota;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1); // Imprime nome do campo.
  // mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  // getstr(campo0);                                    // L� valor do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  // mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
  // getstr(campo2);                                    // L� valor do campo.
  // int icampo2 = atoi(campo2);
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);   // Imprime nome do campo.
  getstr(campo3);                                      // L� valor do campo.
  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto5b);  // Imprime nome do campo.
  getstr(campo4);                                      // L� valor do campo.
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5c);  // Imprime nome do campo.
  getstr(campo5);                                      // L� valor do campo.
  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto5d); // Imprime nome do campo.
  getstr(campo6);                                      // L� valor do campo.
  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    // codigo.setCodigo(campo0);
    titulo.setTitulo(campo1);
    // nota.setNota(icampo2);
    cidade.setCidade(campo3);
    duracao.setDuracao(campo4);
    descricao.setDescricao(campo5);
    endereco.setEndereco(campo6);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto6); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Excursao excursao;

  // excursao.setCodigo(codigo);
  excursao.setTitulo(titulo);
  // excursao.setNota(nota);
  excursao.setCidade(cidade);
  excursao.setDuracao(duracao);
  excursao.setDescricao(descricao);
  excursao.setEndereco(endereco);

  if (cntrServicoExcursao->cadastrarExcursao(excursao, email))
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto7); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 16, coluna / 4, "%s", texto8); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoExcursao::editarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Código da Excursão que você deseja alterar?  :";
  char texto3[] = "Título          :";
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          :";
  char texto6[] = "Duração         :";
  char texto7[] = "Descrição       :";
  char texto8[] = "Endereço        :";
  char texto9[] = "Dados em formato incorreto. Digite algo.";
  char texto10[] = "Sucesso na alteração. Digite algo.";
  char texto11[] = "Falha na alteração. Digite algo.";

  char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Titulo titulo;
  // Nota nota;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo0);                                    // L� valor do campo.
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  // mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
  // getstr(campo2);                                    // L� valor do campo.
  // int icampo2 = atoi(campo2);
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
  getstr(campo3);                                     // L� valor do campo.
  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
  getstr(campo4);                                     // L� valor do campo.
  mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Imprime nome do campo.
  getstr(campo5);                                     // L� valor do campo.
  mvprintw(linha / 4 + 14, coluna / 4, "%s", texto8); // Imprime nome do campo.
  getstr(campo6);                                     // L� valor do campo.
  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    codigo.setCodigo(campo0);
    titulo.setTitulo(campo1);
    // nota.setNota(icampo2);
    cidade.setCidade(campo3);
    duracao.setDuracao(campo4);
    descricao.setDescricao(campo5);
    endereco.setEndereco(campo6);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto9); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Excursao excursao;

  excursao.setCodigo(codigo);
  excursao.setTitulo(titulo);
  // excursao.setNota(nota);
  excursao.setCidade(cidade);
  excursao.setDuracao(duracao);
  excursao.setDescricao(descricao);
  excursao.setEndereco(endereco);

  if (cntrServicoExcursao->editarExcursao(excursao, email))
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto10); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 16, coluna / 4, "%s", texto11); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoExcursao::descadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma excursao: ";
  char texto2[] = "Código          :";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso no descadastramento. Digite algo.";
  char texto5[] = "Falha no descadastramento. Digite algo.";

  char campo1[80];

  Codigo codigo;

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  clear();                                           // Limpa janela.
  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Informa falha.
    noecho();                                          // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
    echo();                                            // Habilita eco.
    return;
  }

  if (cntrServicoExcursao->descadastrarExcursao(codigo, email) && campo1 != "")
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto4); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoExcursao::listarExcursoes(Email email)
{
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar sessões.";
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
      listarSessoes();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::executar(Email email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Cadastar sessão.";
  char texto3[] = "2 - Consultar sessão.";
  char texto4[] = "3 - Editar sessão.";
  char texto5[] = "4 - Excluir sessão.";
  char texto6[] = "5 - Retornar.";

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
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      cadastrarSessao(email);
      break;
    case 2:
      consultarSessao(email);
      break;
    case 3:
      editarSessao(email);
      break;
    case 4:
      descadastrarSessao(email);
      break;
    case 5:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::consultarSessao(Email email)
{
  return;
}

void CntrApresentacaoSessao::cadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código              :";
  char texto3[] = "Data                :";
  char texto4[] = "Horario             :";
  char texto5[] = "Idioma              :";
  char texto6[] = "Código da Excursão  :";
  char texto7[] = "Dados em formato incorreto. Digite algo.";
  char texto8[] = "Sucesso no cadastramento. Digite algo.";
  char texto9[] = "Falha no cadastramento. Digite algo.";

  char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Data data;
  Horario horario;
  Idioma idioma;
  Codigo codigoExcursao;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo2);                                    // L� valor do campo.
  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
  getstr(campo3);                                    // L� valor do campo.
  int icampo2 = atoi(campo3);
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
  getstr(campo4);                                     // L� valor do campo.
  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
  getstr(campo5);                                     // L� valor do campo.

  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    codigo.setCodigo(campo1);
    data.setData(campo2);
    horario.setHorario(campo3);
    idioma.setIdioma(campo4);
    codigoExcursao.setCodigo(campo5);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto7); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Sessao sessao;

  sessao.setCodigo(codigo);
  sessao.setData(data);
  sessao.setHorario(horario);
  sessao.setIdioma(idioma);
  // sessao.setCodigo(codigoExcursao);

  if (cntrServicoExcursao->cadastrarSessao(sessao, email, codigoExcursao))
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto8); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 16, coluna / 4, "%s", texto9); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoSessao::editarSessao(Email email)
{
  return;
}

void CntrApresentacaoSessao::descadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma sessão: ";
  char texto2[] = "Código da sessão :";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso no descadastramento. Digite algo.";
  char texto5[] = "Falha no descadastramento. Digite algo.";

  char campo1[80];

  Codigo codigo;

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  clear();                                           // Limpa janela.
  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Informa falha.
    noecho();                                          // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
    echo();                                            // Habilita eco.
    return;
  }

  if (cntrServicoExcursao->descadastrarExcursao(codigo, email) && campo1 != "")
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto4); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoSessao::listarSessoes()
{
  char texto1[] = "Código         :";
  char texto2[] = "Data            :";
  char texto3[] = "Horario         :";
  char texto4[] = "Idioma          :";

  clear();

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();
  int count = 0;

  while(!sessoes.empty()) {
    Sessao sessao = sessoes.back();
    sessoes.pop_back();

    mvprintw(linha/4 + count, coluna/4,"%s %s", texto1, sessao.getCodigo().getCodigo().c_str());
    mvprintw(linha/4 + count + 2,coluna/4,"%s %s", texto2, sessao.getData().getData().c_str());
    mvprintw(linha/4 + count + 4,coluna/4,"%s %s", texto3, sessao.getHorario().getHorario().c_str());
    mvprintw(linha/4 + count + 6,coluna/4,"%s %s", texto4,  sessao.getIdioma().getIdioma().c_str());

    count+=1;
  }

  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoSessao::listarSessoes(Email email)
{
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar avaliações.";
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

void CntrApresentacaoAvaliacao::executar(Email email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Cadastrar Avaliação.";
  char texto3[] = "2 - Consultar Avaliação.";
  char texto4[] = "3 - Editar Avaliação.";
  char texto5[] = "4 - Excluir Avaliação.";
  char texto6[] = "5 - Retornar.";

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
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      // consultarConta(email);
      break;
    case 2:
      // cadastrarProdutoInvestimento(email);
      break;
    case 3:
      // descadastrarProdutoInvestimento(email);
      break;
    case 4:
      // consultarProdutoInvestimento(email);
      break;
    case 5:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoAvaliacao::consultarAvaliacao(Email email)
{
  return;
}

void CntrApresentacaoAvaliacao::cadastrarAvaliacao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código              :";
  char texto3[] = "Nota                :";
  char texto4[] = "Descricao             :";
  char texto5[] = "Código da Excursão  :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";

  char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Nota nota;
  Descricao descricao;
  Codigo codigoExcursao;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo2);                                    // L� valor do campo.
  int icampo2 = atoi(campo2);

  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
  getstr(campo3);                                    // L� valor do campo.
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Imprime nome do campo.
  getstr(campo4);                                    // L� valor do campo.

  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    codigo.setCodigo(campo1);
    nota.setNota(icampo2);
    descricao.setDescricao(campo3);
    codigoExcursao.setCodigo(campo4);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto6); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Avaliacao avaliacao;

  avaliacao.setCodigo(codigo);
  avaliacao.setNota(nota);
  avaliacao.setDescricao(descricao);
  // avaliacao.setIdioma(idioma);
  // sessao.setCodigo(codigoExcursao);

  if (cntrServicoExcursao->cadastrarAvaliacao(avaliacao, email, codigoExcursao))
  {
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto7); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 16, coluna / 4, "%s", texto8); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoAvaliacao::editarAvaliacao(Email email)
{
  return;
}

void CntrApresentacaoAvaliacao::descadastrarAvaliacao(Email email)
{
  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoes(Email email)
{
  return;
}
