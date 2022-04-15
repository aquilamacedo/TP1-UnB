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
  char texto5[] = "4 - Acessar dados sobre sessoes.";
  char texto6[] = "5 - Acessar dados sobre avaliacoes.";
  char texto7[] = "6 - Encerrar execucao do sistema.";

  // Mensagens a serem apresentadas na tela de sele��o de servi�o.

  char texto8[] = "Selecione um dos servicos : ";
  char texto9[] = "1 - Selecionar servicos de usuarios.";
  char texto10[] = "2 - Selecionar servicos relacionados a excursoes.";
  char texto11[] = "3 - Selecionar servicos relacionados a sessoes.";
  char texto12[] = "4 - Selecionar servicos relacionados a avaliacoes.";
  char texto13[] = "5 - Encerrar sessao.";

  char texto14[] = "Falha na autenticacao. Digite algo para continuar."; // Mensagem a ser apresentada.

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
      {                                     // Solicita autentica��o.
        bool apresentarAutenticacao = true; // Controle de la�o.
        while (apresentarAutenticacao)
        {

          // Apresenta tela de sele��o de servi�o.

          clear();
          mvprintw(linha / 4, coluna / 4, "%s", texto8);
          mvprintw(linha / 4 + 2, coluna / 4, "%s", texto9);
          mvprintw(linha / 4 + 4, coluna / 4, "%s", texto10);
          mvprintw(linha / 4 + 6, coluna / 4, "%s", texto11);
          mvprintw(linha / 4 + 8, coluna / 4, "%s", texto12);
          mvprintw(linha / 4 + 10, coluna / 4, "%s", texto13);
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
            apresentarAutenticacao = false;
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
      cntrApresentacaoUsuario->cadastrarUsuario();
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

  char texto1[] = "Digite o email : ";
  char texto2[] = "Digite a senha : ";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "1 - Tentar novamente.";
  char texto5[] = "2 - Voltar para a tela inicial.";
  char texto6[] = "Autenticado com sucesso.";
  char texto7[] = "Falha na autenticacao. Digite algo.";

  // Campos de entrada.
  int campo;
  char campo1[80];
  char campo2[80];

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  Senha senha; // Instancia a classe Senha.

  echo(); // Habilita eco.
  bool apresentar = true;
  while (apresentar)
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
      senha.setSenha(string(campo2));  // Atribui Valor a senha.

      if (cntr->autenticar(*email, senha)) // Solicita servi�o de autentica��o.
      {
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto6);
        getch();
        return true;
      }
      else
      {
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto7);
        getch();
      }
    }
    catch (invalid_argument &exp) // Captura exce��o devido a formato incorreto.
    {
      mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Informa formato incorreto.
      noecho();
      getch(); // L� caracter digitado.
      echo();
    }
    clear(); // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto5);

    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      continue;
    case 2:
      return false;
    }
  }
  return false;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::executar(Email email)
{

  // Mensagens a serem apresentadas na tela de sele��o de servi�o..

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Editar Dados.";
  char texto3[] = "2 - Consultar Dados.";
  char texto4[] = "3 - Excluir Cadastro.";
  char texto5[] = "4 - Retornar.";

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
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {

    case 1:
      editarUsuario(email);
      break;
    case 2:
      consultarDadosUsuario(email);
      break;
    case 3:
      descadastrarUsuario(email);
      break;
    case 4:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::cadastrarUsuario()
{

  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nome            :";
  char texto3[] = "Email           :";
  char texto4[] = "Senha           :";
  char texto5[] = "Dados em formato incorreto. Digite algo.";
  char texto6[] = "Sucesso no cadastramento. Digite algo.";
  char texto7[] = "Falha no cadastramento. Digite algo.";
  char texto8[] = "1 - Tentar novamente";
  char texto9[] = "2 - Retornar";

  int campo;
  char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Email email;
  Senha senha;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  bool apresentar = true;
  while (apresentar)
  {

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
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto7); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto5); // Informa formato incorreto.
    }

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto8); // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto9); // Informa falha.
    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

bool CntrApresentacaoUsuario::descadastrarUsuario(Email email)
{
  CntrApresentacaoControle *cntrApresentacaoControle;
  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  char texto1[] = "Tem certeza que deseja excluir seu perfil do sistema?";
  char texto2[] = "1 - Sim, quero excluir.";
  char texto3[] = "2 - Nao, entrei nessa opcao por engano.";
  char texto4[] = "Excluido com sucesso. Voce nao faz mais parte desse sistema";
  int campo;

  bool apresentar = true;
  while (apresentar)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.

    campo = getch() - 48;
    bool result;

    switch (campo)
    {
    case 1:
      if (cntrServicoUsuario->descadastrarUsuario(email))
      {
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);
        getch();
        apresentar = false;
        cntrApresentacaoControle->encerrar();
        return true;
      }
      else
      {
        return false;
      }
    case 2:
      apresentar = false;
      break;
    }
  }
  return false;
}

// //--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::consultarDadosUsuario(Email email)
{
  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  char texto1[] = "Email         : "; // Mensagem a ser apresentada.
  char texto2[] = "Nome          : "; // Mensagem a ser apresentada.
  char texto3[] = "Senha         : "; // Mensagem a ser apresentada.

  Usuario usuario = cntrServicoUsuario->recuperar(email);

  clear(); // Limpa janela.
  mvprintw(linha / 4, coluna / 4, "%s %s", texto1, usuario.getEmail().getEmail().c_str());
  mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, usuario.getNome().getNome().c_str());
  mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, usuario.getSenha().getSenha().c_str());

  //   cout << "" << usuario.getEmail().getEmail() << endl;
  //   cout << "Nome          : " << usuario.getNome().getNome() << endl;
  // cout << "Senha         : " << usuario.getSenha().getSenha() << endl;
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
  char texto5[] = "Sucesso na alteracao. Digite algo.";
  char texto6[] = "Falha na alteracao. Digite algo.";
  char texto7[] = "1 - Tentar novamente";
  char texto8[] = "2 - Retornar";
  int campo;
  char campo1[80], campo2[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Senha senha;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.
  bool apresentar = true;
  while (apresentar)
  {

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
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto6); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto4); // Informa formato incorreto.
    }
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto7); // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto8); // Informa falha.

    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Listar Excursoes.";
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
      listarExcursoes();
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
  char texto2[] = "1 - Cadastrar Excursao.";
  char texto3[] = "2 - Listar Excursoes";
  char texto4[] = "3 - Consultar Excursao.";
  char texto5[] = "4 - Editar Excursao.";
  char texto6[] = "5 - Excluir Excursao.";
  char texto7[] = "6 - Retornar.";

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
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      cadastrarExcursao(email);
      break;
    case 2:
      listarExcursoes(email);
      break;
    case 3:
      consultarExcursao(email);
      break;
    case 4:
      editarExcursao(email);
      break;
    case 5:
      descadastrarExcursao(email);
      break;
    case 6:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoExcursao::consultarExcursao(Email email)
{
  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Codigo              : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperacao. Digite algo.";
  char texto5[] = "Falha na recuperacao. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  int linha, coluna; // Dados sobre tamanho da tela.

  char texto6[] = "Codigo             : ";
  char texto7[] = "Titulo             : ";
  char texto8[] = "Nota               : ";
  char texto81[] = "Nao ha avaliacoes cadastradas para essa Excursao";
  char texto9[] = "Cidade             : ";
  char texto10[] = "Duracao            : ";
  char texto11[] = "Endereco           : ";
  char texto12[] = "Email do Guia      : ";

  clear();
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.
  echo();                          // Habilita eco.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
  getstr(campo1);

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Informa formato incorreto.
    campo = getch() - 48;                              // Leitura de caracter digitado.
  }

  try
  {
    clear();
    Excursao excursao = cntrServicoExcursao->recuperarExcursao(codigo);

    mvprintw(linha / 4, coluna / 4, "%s %s", texto6, excursao.getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto7, excursao.getTitulo().getTitulo().c_str());
    if (excursao.getNota().getNota() != -1)
      mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto8, to_string(excursao.getNota().getNota()).c_str());
    else
      mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto8, texto81);
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto9, excursao.getCidade().getCidade().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto10, excursao.getDuracao().getDuracao().c_str());
    mvprintw(linha / 4 + 10, coluna / 4, "%s %s", texto11, excursao.getEndereco().getEndereco().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s", texto12, excursao.getEmail().getEmail().c_str());
  }
  catch (...)
  {
    cout << texto5 << endl; // Informa falha.
  }
  getch();
  return;
}

void CntrApresentacaoExcursao::cadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Codigo          :";
  char texto3[] = "Titulo          :";
  char texto5[] = "Cidade          :";
  char texto5b[] = "Duracao         :";
  char texto5c[] = "Descricao       :";
  char texto5d[] = "Endereco        :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";
  char texto9[] = "1 - Tentar novamente";
  char texto10[] = "2 - Retornar";

  int campo;
  char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80]; // Cria campos para entrada dos dados.

  // Instancia os domínios.
  Titulo titulo;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  bool apresentar = true;
  while (apresentar)
  {

    clear(); // Limpa janela.

    mvprintw(linha / 4, coluna / 4, "%s", texto1);       // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);   // Imprime nome do campo.
    getstr(campo1);                                      // L� valor do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);   // Imprime nome do campo.
    getstr(campo2);                                      // L� valor do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto5b);  // Imprime nome do campo.
    getstr(campo3);                                      // L� valor do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5c);  // Imprime nome do campo.
    getstr(campo4);                                      // L� valor do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto5d); // Imprime nome do campo.
    getstr(campo5);                                      // L� valor do campo.
    try
    {
      titulo.setTitulo(campo1);
      cidade.setCidade(campo2);
      duracao.setDuracao(campo3);
      descricao.setDescricao(campo4);
      endereco.setEndereco(campo5);

      // Instancia e inicializa entidades.

      Excursao excursao;

      excursao.setTitulo(titulo);
      excursao.setCidade(cidade);
      excursao.setDuracao(duracao);
      excursao.setDescricao(descricao);
      excursao.setEndereco(endereco);

      if (cntrServicoExcursao->cadastrarExcursao(excursao, email))
      {
        mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
      }
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto8); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto6); // Informa formato incorreto.
    }
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto9);  // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto10); // Informa falha.
    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoExcursao::editarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Codigo da Excursao que voce deseja alterar?  :";
  char texto3[] = "Titulo          :";
  char texto4[] = "Cidade          :";
  char texto5[] = "Duracao         :";
  char texto6[] = "Descricao       :";
  char texto7[] = "Endereco        :";
  char texto8[] = "Dados em formato incorreto. Digite algo.";
  char texto9[] = "Sucesso na alteracao. Digite algo.";
  char texto10[] = "Falha na alteracao. Digite algo.";
  char texto11[] = "1 - Tentar novamente";
  char texto12[] = "2 - Retornar";

  int campo;
  char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Titulo titulo;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  bool apresentar = true;
  while (apresentar)
  {

    clear(); // Limpa janela.

    mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
    getstr(campo1);                                     // L� valor do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
    getstr(campo2);                                     // L� valor do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.
    getstr(campo3);                                     // L� valor do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);  // Imprime nome do campo.
    getstr(campo4);                                     // L� valor do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Imprime nome do campo.
    getstr(campo5);                                     // L� valor do campo.
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Imprime nome do campo.
    getstr(campo6);                                     // L� valor do campo.
    try
    {
      // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
      codigo.setCodigo(campo1);
      titulo.setTitulo(campo2);
      cidade.setCidade(campo3);
      duracao.setDuracao(campo4);
      descricao.setDescricao(campo5);
      endereco.setEndereco(campo6);

      // Instancia e inicializa entidades.

      Excursao excursao;

      excursao.setCodigo(codigo);
      excursao.setTitulo(titulo);
      excursao.setCidade(cidade);
      excursao.setDuracao(duracao);
      excursao.setDescricao(descricao);
      excursao.setEndereco(endereco);

      if (cntrServicoExcursao->editarExcursao(excursao, email))
      {
        mvprintw(linha / 4 + 14, coluna / 4, "%s", texto9); // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
      }
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto10); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto8); // Informa formato incorreto.
    }
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto11);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto12);

    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoExcursao::descadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma excursao: ";
  char texto2[] = "Codigo da Excursao       :";
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

void CntrApresentacaoExcursao::listarExcursoes()
{
  char texto1[] = "Codigo             : ";
  char texto2[] = "Titulo             : ";
  char texto3[] = "Nota               : ";
  char texto31[] = "Nao ha avaliacoes cadastradas para essa Excursao";
  char texto4[] = "Cidade             : ";
  char texto5[] = "Duracao            : ";
  char texto6[] = "Endereco           : ";
  char texto7[] = "Email do Guia      : ";
  char texto8[] = "Pagina ";
  char texto9[] = " de ";
  char texto10[] = " -----------------------------------------------------";

  int campo;
  list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  int i = 1;
  for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, excursao->getCodigo().getCodigo().c_str());

    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, excursao->getTitulo().getTitulo().c_str());
    if (excursao->getNota().getNota() != -1)
      mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, to_string(excursao->getNota().getNota()).c_str());
    else
      mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, texto31);
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, excursao->getCidade().getCidade().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, excursao->getDuracao().getDuracao().c_str());
    mvprintw(linha / 4 + 10, coluna / 4, "%s %s", texto6, excursao->getEndereco().getEndereco().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s", texto7, excursao->getEmail().getEmail().c_str());
    mvprintw(linha / 4 + 16, coluna / 4, "%s %s %s %s %s", texto8, to_string(i).c_str(), texto9, to_string(excursoes.size()).c_str(), texto10);
    getch();
    i++;
  }
  return;
}

void CntrApresentacaoExcursao::listarExcursoes(Email email)
{
  char texto1[] = "Codigo             : ";
  char texto2[] = "Titulo             : ";
  char texto3[] = "Nota               : ";
  char texto31[] = "Nao ha avaliacoes cadastradas para essa Excursao";
  char texto4[] = "Cidade             : ";
  char texto5[] = "Duracao            : ";
  char texto6[] = "Endereco           : ";
  char texto7[] = "Email do Guia      : ";
  char texto8[] = "Pagina ";
  char texto9[] = " de ";
  char texto10[] = " -----------------------------------------------------";

  int campo;
  list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  int i = 1;
  for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, excursao->getCodigo().getCodigo().c_str());

    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, excursao->getTitulo().getTitulo().c_str());
    if (excursao->getNota().getNota() != -1)
      mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, to_string(excursao->getNota().getNota()).c_str());
    else
      mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, texto31);
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, excursao->getCidade().getCidade().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, excursao->getDuracao().getDuracao().c_str());
    mvprintw(linha / 4 + 10, coluna / 4, "%s %s", texto6, excursao->getEndereco().getEndereco().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s", texto7, excursao->getEmail().getEmail().c_str());
    mvprintw(linha / 4 + 16, coluna / 4, "%s %s %s %s %s", texto8, to_string(i).c_str(), texto9, to_string(excursoes.size()).c_str(), texto10);
    getch();
    i++;
  }
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Listar sessoes.";
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
  char texto2[] = "1 - Cadastar sessao.";
  char texto3[] = "2 - Listar sessoes.";
  char texto4[] = "3 - Listar sessoes por excursao.";
  char texto5[] = "4 - Consultar sessao.";
  char texto6[] = "5 - Editar sessao.";
  char texto7[] = "6 - Excluir sessao.";
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
      cadastrarSessao(email);
      break;
    case 2:
      listarSessoes(email);
      break;
    case 3:
      listarSessoesExcursao(email);
      break;
    case 4:
      consultarSessao(email);
      break;
    case 5:
      editarSessao(email);
      break;
    case 6:
      descadastrarSessao(email);
      break;
    case 7:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::consultarSessao(Email email)
{
  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Codigo              : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperacao. Digite algo.";
  char texto5[] = "Falha na recuperacao. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  int linha, coluna; // Dados sobre tamanho da tela.
  clear();
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.
  echo();                          // Habilita eco.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
  getstr(campo1);

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Informa formato incorreto.
    campo = getch() - 48;                              // Leitura de caracter digitado.
  }

  char texto7[] = "Codigo             : ";
  char texto8[] = "Data               : ";
  char texto9[] = "Horario            : ";
  char texto10[] = "Idioma             : ";
  char texto11[] = "Codigo da Excursao : ";

  try
  {
    clear();
    Sessao sessao = cntrServicoExcursao->recuperarSessao(codigo);

    mvprintw(linha / 4, coluna / 4, "%s %s", texto7, sessao.getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto8, sessao.getData().getData().c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto9, sessao.getHorario().getHorario().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto10, sessao.getIdioma().getIdioma().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto11, sessao.getCodigoExcursao().getCodigo().c_str());
  }
  catch (...)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
  }
  getch();
  return;
}

void CntrApresentacaoSessao::cadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  // char texto2[] = "Codigo              :";
  char texto3[] = "Data                :";
  char texto4[] = "Horario             :";
  char texto5[] = "Idioma              :";
  char texto6[] = "Codigo da Excursao  :";
  char texto7[] = "Dados em formato incorreto. Digite algo.";
  char texto8[] = "Sucesso no cadastramento. Digite algo.";
  char texto9[] = "Falha no cadastramento. Digite algo.";
  char texto10[] = "1 - Tentar novamente";
  char texto11[] = "2 - Retornar";

  int campo;
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

  bool apresentar = true;
  while (apresentar)
  {

    clear(); // Limpa janela.

    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3); // Imprime nome do campo.
    getstr(campo2);                                    // L� valor do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto4); // Imprime nome do campo.
    getstr(campo3);                                    // L� valor do campo.
    int icampo2 = atoi(campo3);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto5); // Imprime nome do campo.
    getstr(campo4);                                    // L� valor do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto6); // Imprime nome do campo.
    getstr(campo5);                                    // L� valor do campo.

    try
    {
      data.setData(campo2);
      horario.setHorario(campo3);
      idioma.setIdioma(campo4);
      codigoExcursao.setCodigo(campo5);

      // Instancia e inicializa entidades.

      Sessao sessao;

      sessao.setData(data);
      sessao.setHorario(horario);
      sessao.setIdioma(idioma);
      sessao.setCodigoExcursao(codigoExcursao);

      if (cntrServicoExcursao->cadastrarSessao(sessao, email))
      {
        mvprintw(linha / 4 + 10, coluna / 4, "%s", texto8); // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
      }
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto9); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto7); // Informa formato incorreto.
    }
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto10); // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto11); // Informa falha.
    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoSessao::editarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Codigo da Sessao que voce deseja alterar?  :";
  char texto3[] = "Data            :";
  char texto4[] = "Horario         :";
  char texto5[] = "Idioma          :";
  char texto8[] = "Dados em formato incorreto. Digite algo.";
  char texto9[] = "Sucesso na alteracao. Digite algo.";
  char texto10[] = "Falha na alteracao. Digite algo.";
  char texto11[] = "1 - Tentar novamente";
  char texto12[] = "2 - Retornar";
  int campo;
  char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Data data;
  Horario horario;
  Idioma idioma;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.
  bool apresentar = true;
  while (apresentar)
  {
    clear(); // Limpa janela.

    mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
    getstr(campo1);                                    // L� valor do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
    getstr(campo2);                                    // L� valor do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
    getstr(campo3);                                    // L� valor do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Imprime nome do campo.
    getstr(campo4);                                    // L� valor do campo.

    try
    {
      codigo.setCodigo(campo1);
      data.setData(campo2);
      horario.setHorario(campo3);
      idioma.setIdioma(campo4);

      // Instancia e inicializa entidades.
      Sessao sessao;
      sessao.setCodigo(codigo);
      sessao.setData(data);
      sessao.setHorario(horario);
      sessao.setIdioma(idioma);

      if (cntrServicoExcursao->editarSessao(sessao, email))
      {
        mvprintw(linha / 4 + 10, coluna / 4, "%s", texto9); // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
      }
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto10); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto8); // Informa formato incorreto.
    }

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto11); // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto12); // Informa falha.
    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoSessao::descadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma sessao: ";
  char texto2[] = "Codigo da sessao       : ";
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

  if (cntrServicoExcursao->descadastrarSessao(codigo, email) && campo1 != "")
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
  char texto1[] = "Codigo             : ";
  char texto2[] = "Data               : ";
  char texto3[] = "Horario            : ";
  char texto4[] = "Idioma             : ";
  char texto5[] = "Codigo da Excursao : ";
  char texto6[] = "Pagina ";
  char texto7[] = " de ";
  char texto8[] = " -----------------------------------------------------";

  int linha, coluna;
  getmaxyx(stdscr, linha, coluna);

  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();
  int i = 1;

  for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, sessao->getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, sessao->getData().getData().c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, sessao->getHorario().getHorario().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, sessao->getIdioma().getIdioma().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, sessao->getCodigoExcursao().getCodigo().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(sessoes.size()).c_str(), texto8);
    i++;

    noecho();
    getch();
    echo();
  }

  return;
}

void CntrApresentacaoSessao::listarSessoes(Email email)
{
  char texto1[] = "Codigo             : ";
  char texto2[] = "Data               : ";
  char texto3[] = "Horario            : ";
  char texto4[] = "Idioma             : ";
  char texto5[] = "Codigo da Excursao : ";
  char texto6[] = "Pagina ";
  char texto7[] = " de ";
  char texto8[] = " -----------------------------------------------------";

  int linha, coluna;
  getmaxyx(stdscr, linha, coluna);

  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();
  int i = 1;

  for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, sessao->getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, sessao->getData().getData().c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, sessao->getHorario().getHorario().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, sessao->getIdioma().getIdioma().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, sessao->getCodigoExcursao().getCodigo().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(sessoes.size()).c_str(), texto8);
    i++;

    noecho();
    getch();
    echo();
  }

  return;
}

void CntrApresentacaoSessao::listarSessoesExcursao(Email email)
{
  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Codigo da Excursao      : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperacao. Digite algo.";
  char texto5[] = "Falha na recuperacao. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  clear(); // Limpa janela.
  bool apresentar = true;

  int linha, coluna;
  getmaxyx(stdscr, linha, coluna);

  while (apresentar)
  {
    mvprintw(linha / 4, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    getstr(campo1);

    try
    {
      codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
      mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
      campo = getch() - 48;
    }
    Excursao excursao;
    excursao.setCodigo(codigo);

    try
    {
      int campo;
      list<Sessao> sessoes = cntrServicoExcursao->listarSessoesExcursao(excursao);
      int j = 0;
      char texto1[] = "Codigo             : ";
      char texto2[] = "Data               : ";
      char texto3[] = "Horario            : ";
      char texto4[] = "Idioma             : ";
      char texto5[] = "Codigo da Excursao : ";
      char texto6[] = "Pagina ";
      char texto7[] = " de ";
      char texto8[] = " -----------------------------------------------------";

      int linha, coluna;               // Dados sobre tamanho da tela.
      getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.
      int i = 1;

      for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s %s", texto1, sessao->getCodigo().getCodigo().c_str());
        mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, sessao->getData().getData().c_str());
        mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, sessao->getHorario().getHorario().c_str());
        mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, sessao->getIdioma().getIdioma().c_str());
        mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, sessao->getCodigoExcursao().getCodigo().c_str());
        mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(sessoes.size()).c_str(), texto8);
        i++;

        noecho();
        getch();
        echo();
      }
    }
    catch (...)
    {
      mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    }
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", "1 - Listar sessoes de outra excursao");
    mvprintw(linha / 4 + 2, coluna / 4, "%s", "2 - Retornar");

    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      clear();
      continue;
    case 2:
      apresentar = false;
      break;
    default:
      clear();
      apresentar = false;
      break;
    }
  }
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Listar avaliacoes.";
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
      listarAvaliacoes();
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
  char texto2[] = "1 - Cadastrar Avaliacao.";
  char texto3[] = "2 - Listar Avaliacoes.";
  char texto4[] = "3 - Listar Avaliacoes do Usuario.";
  char texto5[] = "4 - Listar Avaliacoes por Excursao.";
  char texto6[] = "5 - Consultar Avaliacao.";
  char texto7[] = "6 - Editar Avaliacao.";
  char texto8[] = "7 - Excluir Avaliacao.";
  char texto9[] = "8 - Retornar.";

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
    mvprintw(linha / 4 + 16, coluna / 4, "%s", texto9); // Imprime nome do campo.
    noecho();
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    echo();

    switch (campo)
    {
    case 1:
      cadastrarAvaliacao(email);
      break;
    case 2:
      listarAvaliacoes(email);
      break;
    case 3:
      listarAvaliacoesUsuario(email);
      break;
    case 4:
      listarAvaliacoesExcursao(email);
      break;
    case 5:
      consultarAvaliacao(email);
      break;
    case 6:
      editarAvaliacao(email);
      break;
    case 7:
      descadastrarAvaliacao(email);
      break;
    case 8:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoAvaliacao::consultarAvaliacao(Email email)
{
  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Codigo              : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperacao. Digite algo.";
  char texto5[] = "Falha na recuperacao. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  int linha, coluna; // Dados sobre tamanho da tela.
  clear();
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.
  echo();                          // Habilita eco.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
  getstr(campo1);

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Informa formato incorreto.
    campo = getch() - 48;                              // Leitura de caracter digitado.
  }

  char texto7[] = "Codigo             : ";
  char texto8[] = "Nota               : ";
  char texto9[] = "Descricao          : ";
  char texto10[] = "Email do Avaliador : ";
  char texto11[] = "Codigo da Excursao : ";

  try
  {
    clear();
    Avaliacao avaliacao = cntrServicoExcursao->recuperarAvaliacao(codigo);

    mvprintw(linha / 4, coluna / 4, "%s %s", texto7, avaliacao.getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto8, to_string((int)avaliacao.getNota().getNota()).c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto9, avaliacao.getDescricao().getDescricao().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto10, avaliacao.getEmail().getEmail().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto11, avaliacao.getCodigoExcursao().getCodigo().c_str());
  }
  catch (...)
  {
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
  }
  getch();
  return;
}

void CntrApresentacaoAvaliacao::cadastrarAvaliacao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nota                : ";
  char texto3[] = "Descricao           : ";
  char texto4[] = "Codigo da Excursao  : ";
  char texto5[] = "Dados em formato incorreto. Digite algo.";
  char texto6[] = "Sucesso no cadastramento. Digite algo.";
  char texto7[] = "Falha no cadastramento. Digite algo.";
  char texto8[] = "1 - Tentar novamente";
  char texto9[] = "2 - Retornar";

  int campo;
  char campo1[80], campo2[80], campo3[80];

  Nota nota;
  Descricao descricao;
  Codigo codigoExcursao;

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);

  bool apresentar = true;
  while (apresentar)
  {
    clear();

    mvprintw(linha / 4, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    getstr(campo1);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    getstr(campo2);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);
    getstr(campo3);

    try
    {
      int icampo2 = stoi(campo1);
      nota.setNota(icampo2);
      descricao.setDescricao(campo2);
      codigoExcursao.setCodigo(campo3);

      // Instancia e inicializa entidades.

      Avaliacao avaliacao;

      avaliacao.setNota(nota);
      avaliacao.setDescricao(descricao);

      if (cntrServicoExcursao->cadastrarAvaliacao(avaliacao, email, codigoExcursao))
      {
        mvprintw(linha / 4 + 8, coluna / 4, "%s", texto6); // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
      }
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto7); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto5); // Informa formato incorreto.
    }
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto8); // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto9); // Informa falha.
    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoAvaliacao::editarAvaliacao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Codigo da Avaliacao que voce deseja alterar?  :";
  char texto3[] = "Nota            :";
  char texto4[] = "Descricao       :";
  char texto5[] = "Dados em formato incorreto. Digite algo.";
  char texto6[] = "Sucesso na alteracao. Digite algo.";
  char texto7[] = "Falha na alteracao. Digite algo.";
  char texto8[] = "1 - Tentar novamente";
  char texto9[] = "2 - Retornar";

  int campo;
  char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Nota nota;
  Descricao descricao;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.
  bool apresentar = true;
  while (apresentar)
  {
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
      codigo.setCodigo(campo1);
      int icampo2 = stoi(campo2);
      nota.setNota(icampo2);
      descricao.setDescricao(campo3);

      // Instancia e inicializa entidades.

      Avaliacao avaliacao;

      avaliacao.setCodigo(codigo);
      avaliacao.setNota(nota);
      avaliacao.setDescricao(descricao);

      if (cntrServicoExcursao->editarAvaliacao(avaliacao, email))
      {
        mvprintw(linha / 4 + 8, coluna / 4, "%s", texto6); // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
      }
      else
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", texto7); // Informa falha.
      }
    }
    catch (invalid_argument &exp)
    {
      clear();
      mvprintw(linha / 4, coluna / 4, "%s", texto5); // Informa formato incorreto.
    }

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto8); // Informa falha.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto9); // Informa falha.
    noecho();
    campo = getch() - 48;
    echo();
    switch (campo)
    {
    case 1:
      continue;
    case 2:
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoAvaliacao::descadastrarAvaliacao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma sessao: ";
  char texto2[] = "Codigo da Avaliacao : ";
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

  if (cntrServicoExcursao->descadastrarAvaliacao(codigo, email) && campo1 != "")
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

void CntrApresentacaoAvaliacao::listarAvaliacoes()
{
  list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes();

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);
  int i = 1;

  char texto1[] = "Codigo             : ";
  char texto2[] = "Nota               : ";
  char texto3[] = "Descricao          : ";
  char texto4[] = "Email do Avaliador : ";
  char texto5[] = "Codigo da Excursao : ";
  char texto6[] = "Pagina ";
  char texto7[] = " de ";
  char texto8[] = " -----------------------------------------------------";

  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {

    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, avaliacao->getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, to_string((int)avaliacao->getNota().getNota()).c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, avaliacao->getDescricao().getDescricao().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, avaliacao->getEmail().getEmail().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, avaliacao->getCodigoExcursao().getCodigo().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(avaliacoes.size()).c_str(), texto8);
    i++;
    getch();
  }
  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoes(Email email)
{
  list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes();

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);
  int i = 1;

  char texto1[] = "Codigo             : ";
  char texto2[] = "Nota               : ";
  char texto3[] = "Descricao          : ";
  char texto4[] = "Email do Avaliador : ";
  char texto5[] = "Codigo da Excursao : ";
  char texto6[] = "Pagina ";
  char texto7[] = " de ";
  char texto8[] = " -----------------------------------------------------";

  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, avaliacao->getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, to_string((int)avaliacao->getNota().getNota()).c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, avaliacao->getDescricao().getDescricao().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, avaliacao->getEmail().getEmail().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, avaliacao->getCodigoExcursao().getCodigo().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(avaliacoes.size()).c_str(), texto8);
    i++;
    getch();
  }
  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoesUsuario(Email email)
{
  Usuario usuario;
  usuario.setEmail(email);
  list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoesUsuario(usuario);

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);

  if (avaliacoes.empty())
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", "Nao ha avaliacoes cadastradas por esse usuario");
    getch();
  }
  char texto1[] = "Codigo             : ";
  char texto2[] = "Nota               : ";
  char texto3[] = "Descricao          : ";
  char texto4[] = "Email do Avaliador : ";
  char texto5[] = "Codigo da Excursao : ";
  char texto6[] = "Pagina ";
  char texto7[] = " de ";
  char texto8[] = " -----------------------------------------------------";
  int i = 1;
  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, avaliacao->getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, to_string((int)avaliacao->getNota().getNota()).c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, avaliacao->getDescricao().getDescricao().c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, avaliacao->getEmail().getEmail().c_str());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, avaliacao->getCodigoExcursao().getCodigo().c_str());
    mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(avaliacoes.size()).c_str(), texto8);
    i++;
    getch();
  }
  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoesExcursao(Email email)
{
  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Codigo da Excursao      : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Falha na listagem. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);
  clear(); // Limpa janela.
  bool apresentar = true;
  while (apresentar)
  {

    mvprintw(linha / 4, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    getstr(campo1);

    try
    {
      codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
      mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
      getch();
    }
    Excursao excursao;
    excursao.setCodigo(codigo);

    try
    {
      list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoesExcursao(excursao);

      clear();

      int i = 1;

      char texto1[] = "Codigo             : ";
      char texto2[] = "Nota               : ";
      char texto3[] = "Descricao          : ";
      char texto4[] = "Email do Avaliador : ";
      char texto5[] = "Codigo da Excursao : ";
      char texto6[] = "Pagina ";
      char texto7[] = " de ";
      char texto8[] = " -----------------------------------------------------";

      for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s %s", texto1, avaliacao->getCodigo().getCodigo().c_str());
        mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, to_string((int)avaliacao->getNota().getNota()).c_str());
        mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3, avaliacao->getDescricao().getDescricao().c_str());
        mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4, avaliacao->getEmail().getEmail().c_str());
        mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto5, avaliacao->getCodigoExcursao().getCodigo().c_str());
        mvprintw(linha / 4 + 12, coluna / 4, "%s %s %s %s %s", texto6, to_string(i).c_str(), texto7, to_string(avaliacoes.size()).c_str(), texto8);
        i++;
        getch();
      }
    }
    catch (...)
    {
      mvprintw(linha / 4 + 4, coluna / 4, "%s", texto4);
    }
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", "1 - Listar avaliacoes de outra excursao");
    mvprintw(linha / 4 + 2, coluna / 4, "%s", "2 - Retornar");
    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      clear();
      continue;
    case 2:
      apresentar = false;
      break;
    default:
      clear();
      apresentar = false;
      break;
    }
  }
  return;
}
