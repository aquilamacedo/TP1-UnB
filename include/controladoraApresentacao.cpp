#include "controladoraApresentacao.h"
#include "conio.h"
#include <string>

void CntrApresentacaoControle::encerrar()
{
  exit(0);
}
void CntrApresentacaoControle::executar()
{

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Acessar sistema.";
  char texto3[] = "2 - Cadastrar usuario.";
  char texto4[] = "3 - Acessar dados sobre excursões.";
  char texto5[] = "4 - Acessar dados sobre sessões.";
  char texto6[] = "5 - Acessar dados sobre avaliações.";
  char texto7[] = "6 - Encerrar execução do sistema.";

  char texto8[] = "Selecione um dos servicos : ";
  char texto9[] = "1 - Selecionar servicos de usuarios.";
  char texto10[] = "2 - Selecionar servicos relacionados a excursões.";
  char texto11[] = "3 - Selecionar servicos relacionados a sessões.";
  char texto12[] = "4 - Selecionar servicos relacionados a avaliações.";
  char texto13[] = "5 - Encerrar sessao.";

  char texto14[] = "Falha na autenticação. Digite algo para continuar.";

  int campo;
  bool apresentarAutenticacao = false;
  bool apresentar = true;

  while (apresentar)
  {
    if (apresentar == false)
    {
      return;
    }
    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    cout << texto7 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

    switch (campo)
    {
    case 1:
      apresentarAutenticacao = true;
      if (cntrApresentacaoAutenticacao->autenticar(&email))
      {
        while (apresentarAutenticacao)
        {
          CLR_SCR;                 // Limpa janela.
          cout << texto8 << endl;  // Imprime nome do campo.
          cout << texto9 << endl;  // Imprime nome do campo.
          cout << texto10 << endl; // Imprime nome do campo.
          cout << texto11 << endl; // Imprime nome do campo.
          cout << texto12 << endl; // Imprime nome do campo.
          cout << texto13 << endl; // Imprime nome do campo.

          campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

          switch (campo)
          {
          case 1:
            cntrApresentacaoUsuario->executar(email); // Solicita servi�o de pessoal.
            break;
          case 2:
            cntrApresentacaoExcursao->executar(email);
            break;
          case 3:
            cntrApresentacaoSessao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 4:
            cntrApresentacaoAvaliacao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 5:
            apresentarAutenticacao = false;
            break;
          }
        }
      }
      else
      {
        CLR_SCR;                 // Limpa janela.
        cout << texto14 << endl; // Imprime mensagem.
        campo = getch() - 48;    // Leitura de caracter digitado.
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
      CLR_SCR;
      apresentar = false;
      break;
    }
  }
  return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Email *email)
{

  char texto1[] = "Digite o email : ";
  char texto2[] = "Digite a senha : ";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "1 - Tentar novamente.";
  char texto5[] = "2 - Voltar para a tela inicial.";
  char texto6[] = "Autenticado com sucesso.";
  char texto7[] = "Falha na autenticação. Digite algo.";

  char campo1[80];
  char campo2[80];
  int campo;

  Senha senha;

  bool apresentar = true;
  while (apresentar)
  {

    CLR_SCR;
    cout << texto1;
    cin >> campo1;
    cout << texto2;
    cin >> campo2;

    try
    {
      email->setEmail(string(campo1));
      senha.setSenha(string(campo2));

      if (cntr->autenticar(*email, senha))
      {
        cout << texto6 << endl;
        campo = getch() - 48;
        return true;
      }
      else
      {
        CLR_SCR;                // Limpa janela.
        cout << texto7 << endl; // Informa formato incorreto.
        campo = getch() - 48;
      }
    }
    catch (invalid_argument &exp)
    {
      CLR_SCR;                // Limpa janela.
      cout << texto3 << endl; // Informa formato incorreto.
      campo = getch() - 48;   // L� caracter digitado.
    }

    // CLR_SCR;                                                                            // Limpa janela.

    cout << texto4 << endl;
    cout << texto5 << endl;

    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      continue;
    case 2:
      return false;
    }
  }
  return true;
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

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela de sela��o de servi�o.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cout << texto4 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

    switch (campo)
    {
    case 1:
      editarUsuario(email);
      break;
    case 2:
      excluirUsuario(email);
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
  int campo;
  char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Email email;
  Senha senha;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl; // Imprime nome do campo.
  cout << texto2;         // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1));
  cout << texto3;                      // Imprime nome do campo.
  cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
  cout << texto4;                      // Imprime nome do campo.
  cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    email.setEmail(string(campo2));
    senha.setSenha(string(campo3));
  }
  catch (invalid_argument &exp)
  {
    cout << texto5 << endl; // Informa formato incorreto.
    campo = getch() - 48;   // Leitura de caracter digitado.
    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setEmail(email);
  usuario.setSenha(senha);

  if (cntrServicoUsuario->cadastrarUsuario(usuario))
  {
    cout << texto6 << endl; // Informa sucesso.
    campo = getch() - 48;
    return;
  }
  cout << texto7 << endl; // Informa falha.
  campo = getch() - 48;
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::consultarDadosUsuario(Email)
{
  int campo;

  // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.

  char texto[] = "Servico consultar dados pessoais nao implementado. Digite algo."; // Mensagem a ser apresentada.
  CLR_SCR;                                                                          // Limpa janela.
  cout << texto << endl;                                                            // Imprime nome do campo.
  campo = getch() - 48;
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
  int campo;
  char campo1[80], campo2[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Senha senha;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
  cout << texto3;                      // Imprime nome do campo.
  cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    senha.setSenha(string(campo2));
  }
  catch (invalid_argument &exp)
  {
    cout << texto4 << endl; // Informa formato incorreto.

    campo = getch() - 48; // Leitura de caracter digitado.

    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setSenha(senha);
  usuario.setEmail(email);

  if (cntrServicoUsuario->editarUsuario(usuario))
  {
    cout << texto5 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto6 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoUsuario::excluirUsuario(Email email)
{
  CntrApresentacaoControle *cntrApresentacaoControle;

  char texto1[] = "Tem certeza que deseja excluir seu perfil do sistema?";
  char texto2[] = "1 - Sim, quero excluir.";
  char texto3[] = "2 - Não, entrei nessa opção por engano.";
  char texto4[] = "Excluido com sucesso. Você não faz mais parte desse sistema";

  int campo;

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    CLR_SCR;
    cout << texto1 << "\n"
         << endl;
    cout << texto2 << endl;
    cout << texto3 << endl;

    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      cntrServicoUsuario->descadastrarUsuario(email);
      cout << texto4;
      campo = getch() - 48;
      apresentar = false;
      cntrApresentacaoControle->encerrar();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}
//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Listar excursões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

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
  char texto2[] = "1 - Cadastrar Excursão.";
  char texto3[] = "2 - Listar Excursões";
  char texto4[] = "3 - Consultar Excursão.";
  char texto5[] = "4 - Editar Excursão.";
  char texto6[] = "5 - Excluir Excursão.";
  char texto7[] = "6 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    cout << texto7 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

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
  char texto2[] = "Código              : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperação. Digite algo.";
  char texto5[] = "Falha na recuperação. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  CLR_SCR; // Limpa janela.
  bool apresentar = true;
  while (apresentar)
  {

    cout << texto1 << endl;              // Imprime nome do campo.
    cout << texto2;                      // Imprime nome do campo.
    cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

    try
    {
      codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
      cout << texto3 << endl; // Informa formato incorreto.
      campo = getch() - 48;   // Leitura de caracter digitado.
    }

    try
    {

      Excursao excursao = cntrServicoExcursao->recuperarExcursao(codigo);

      cout << "\n"
           << "Código        : " << excursao.getCodigo().getCodigo() << endl;
      cout << "Título        : " << excursao.getTitulo().getTitulo() << endl;
      if (excursao.getNota().getNota() != -1)
        cout << "Nota          : " << excursao.getNota().getNota() << endl;
      else
        cout << "Nota          : Não há avaliações cadastradas para essa Excursão" << endl;
      cout << "Cidade        : " << excursao.getCidade().getCidade() << endl;
      cout << "Duração       : " << excursao.getDuracao().getDuracao() << endl;
      cout << "Endereço      : " << excursao.getEndereco().getEndereco() << endl;
      cout << "Email do Guia : " << excursao.getEmail().getEmail() << "\n"
           << endl;
    }
    catch (...)
    {
      cout << texto5 << endl; // Informa falha.
    }
    cout << "1 - Recuperar outra excursão" << endl;
    cout << "2 - Retornar" << endl;
    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      CLR_SCR;
      continue;
    case 2:
      apresentar = false;
      break;
    default:
      CLR_SCR;
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoExcursao::cadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código          : ";
  char texto3[] = "Título          : ";
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          : ";
  char texto6[] = "Duração         : ";
  char texto7[] = "Descrição       : ";
  char texto8[] = "Endereço        : ";
  char texto9[] = "Dados em formato incorreto. Digite algo.";
  char texto10[] = "Sucesso no cadastramento. Digite algo.";
  char texto11[] = "Falha no cadastramento. Digite algo.";
  int campo;
  char campo0[80], campo1[80], campo2[80], campo3[80], campo4[80], campo5[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  // Codigo codigo;
  Titulo titulo;
  // Nota nota;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl; // Imprime nome do campo.
  // cout << texto2 << endl; // Imprime nome do campo.
  // cin >> campo0;                                    // L� valor do campo.
  cout << texto3;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
  // cout << texto4 << endl; // Imprime nome do campo.
  // cin >> campo2;                                    // L� valor do campo.
  // int icampo2 = atoi(campo2);
  cout << texto5;
  cin.getline(campo2, sizeof(campo2));
  cout << texto6;                      // Imprime nome do campo.
  cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
  cout << texto7;                      // Imprime nome do campo.
  cin.getline(campo4, sizeof(campo4));
  cout << texto8; // Imprime nome do campo.
  cin.getline(campo5, sizeof(campo5));
  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    // codigo.setCodigo(campo0);
    titulo.setTitulo(campo1);
    // nota.setNota(icampo2);
    cidade.setCidade(campo2);
    duracao.setDuracao(campo3);
    descricao.setDescricao(campo4);
    endereco.setEndereco(campo5);
  }
  catch (invalid_argument &exp)
  {
    cout << texto9 << endl; // Informa formato incorreto.

    campo = getch() - 48; // Leitura de caracter digitado.

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
    cout << texto10 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto11 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoExcursao::editarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Código da Excursão que você deseja alterar?  : ";
  char texto3[] = "Título          : ";
  // char texto4[] = "Nota            : ";
  char texto5[] = "Cidade          : ";
  char texto6[] = "Duração         : ";
  char texto7[] = "Descrição       : ";
  char texto8[] = "Endereço        : ";
  char texto9[] = "Dados em formato incorreto. Digite algo.";
  char texto10[] = "Sucesso na alteração. Digite algo.";
  char texto11[] = "Falha na alteração. Digite algo.";
  int campo;
  char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Titulo titulo;
  // Nota nota;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2;                      // Imprime nome do campo.
  cin.getline(campo0, sizeof(campo0)); // L� valor do campo.
  cout << texto3;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
  // cout << texto4; // Imprime nome do campo.
  // cin >> campo2;                                    // L� valor do campo.
  // int icampo2 = atoi(campo2);
  cout << texto5;                      // Imprime nome do campo.
  cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
  cout << texto6;                      // Imprime nome do campo.
  cin.getline(campo4, sizeof(campo4)); // L� valor do campo.
  cout << texto7;                      // Imprime nome do campo.
  cin.getline(campo5, sizeof(campo5)); // L� valor do campo.
  cout << texto8;                      // Imprime nome do campo.
  cin.getline(campo6, sizeof(campo5)); // L� valor do campo.
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
    cout << texto9 << endl; // Informa formato incorreto.

    campo = getch() - 48; // Leitura de caracter digitado.

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
    cout << texto10 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto11 << endl; // Informa falha.

  campo = getch() - 48;

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

  int campo;
  char campo1[80];

  Codigo codigo;

  CLR_SCR;                             // Limpa janela.
  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    cout << texto3 << endl; // Informa falha.

    campo = getch() - 48; // Leitura de caracter digitado.

    return;
  }

  if (cntrServicoExcursao->descadastrarExcursao(codigo, email) && campo1 != "")
  {
    cout << texto4 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto5 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoExcursao::listarExcursoes()
{
  int campo;
  list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

  CLR_SCR;
  for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
  {
    cout << "\n"
         << "Código        : " << excursao->getCodigo().getCodigo() << endl;
    cout << "Título        : " << excursao->getTitulo().getTitulo() << endl;
    if (excursao->getNota().getNota() != -1)
      cout << "Nota          : " << excursao->getNota().getNota() << endl;
    else
      cout << "Nota          : Não há avaliações cadastradas para essa Excursão" << endl;
    cout << "Cidade        : " << excursao->getCidade().getCidade() << endl;
    cout << "Duração       : " << excursao->getDuracao().getDuracao() << endl;
    cout << "Endereço      : " << excursao->getEndereco().getEndereco() << endl;
    cout << "Email do Guia : " << excursao->getEmail().getEmail() << "\n"
         << endl;
    cout << "--------------------------------------------------------------" << endl;
  }
  campo = getch() - 48;
  return;
}
void CntrApresentacaoExcursao::listarExcursoes(Email email)
{
  int campo;
  list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

  CLR_SCR;
  for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
  {
    cout << "\n"
         << "Código        : " << excursao->getCodigo().getCodigo() << endl;
    cout << "Título        : " << excursao->getTitulo().getTitulo() << endl;
    if (excursao->getNota().getNota() != -1)
      cout << "Nota          : " << excursao->getNota().getNota() << endl;
    else
      cout << "Nota          : Não há avaliações cadastradas para essa Excursão" << endl;
    cout << "Cidade        : " << excursao->getCidade().getCidade() << endl;
    cout << "Duração       : " << excursao->getDuracao().getDuracao() << endl;
    cout << "Endereço      : " << excursao->getEndereco().getEndereco() << endl;
    cout << "Email do Guia : " << excursao->getEmail().getEmail() << "\n"
         << endl;
    cout << "--------------------------------------------------------------" << endl;
  }
  campo = getch() - 48;
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar()
{

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Listar sessões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

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
  char texto3[] = "2 - Listar sessões.";
  char texto4[] = "3 - Consultar sessão.";
  char texto5[] = "4 - Editar sessão.";
  char texto6[] = "5 - Excluir sessão.";
  char texto7[] = "6 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    cout << texto7 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

    switch (campo)
    {
    case 1:
      cadastrarSessao(email);
      break;
    case 2:
      listarSessoes(email);
      break;
    case 3:
      consultarSessao(email);
      break;
    case 4:
      editarSessao(email);
      break;
    case 5:
      descadastrarSessao(email);
      break;
    case 6:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::consultarSessao(Email email)
{

  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Código              : ";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperação. Digite algo.";
  char texto5[] = "Falha na recuperação. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  CLR_SCR; // Limpa janela.
  bool apresentar = true;
  while (apresentar)
  {

    cout << texto1 << endl;              // Imprime nome do campo.
    cout << texto2;                      // Imprime nome do campo.
    cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

    try
    {
      codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
      cout << texto3 << endl; // Informa formato incorreto.
      campo = getch() - 48;   // Leitura de caracter digitado.
    }

    try
    {

      Sessao sessao = cntrServicoExcursao->recuperarSessao(codigo);

      cout << "\n"
           << "Código             : " << sessao.getCodigo().getCodigo() << endl;
      cout << "Data               : " << sessao.getData().getData() << endl;
      cout << "Horário            : " << sessao.getHorario().getHorario() << endl;
      cout << "Idioma             : " << sessao.getIdioma().getIdioma() << endl;
      cout << "Código da Excursão : " << sessao.getCodigoExcursao().getCodigo() << "\n"
           << endl;
    }
    catch (...)
    {
      cout << texto5 << endl; // Informa falha.
    }
    cout << "1 - Recuperar outra sessão" << endl;
    cout << "2 - Retornar" << endl;
    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      CLR_SCR;
      continue;
    case 2:
      apresentar = false;
      break;
    default:
      CLR_SCR;
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoSessao::cadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Data                :";
  char texto3[] = "Horario             :";
  char texto4[] = "Idioma              :";
  char texto5[] = "Código da Excursão  :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";

  int campo;
  char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Data data;
  Horario horario;
  Idioma idioma;
  Codigo codigoExcursao;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
  cout << texto3;                      // Imprime nome do campo.
  cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
  cout << texto4;                      // Imprime nome do campo.
  cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
  cout << texto5;                      // Imprime nome do campo.
  cin.getline(campo4, sizeof(campo4)); // L� valor do campo.

  try
  {
    data.setData(campo1);
    horario.setHorario(campo2);
    idioma.setIdioma(campo3);
    codigoExcursao.setCodigo(campo4);
  }
  catch (invalid_argument &exp)
  {
    cout << texto6 << endl; // Informa formato incorreto.

    campo = getch() - 48; // Leitura de caracter digitado.

    return;
  }

  // Instancia e inicializa entidades.

  Sessao sessao;

  sessao.setData(data);
  sessao.setHorario(horario);
  sessao.setIdioma(idioma);
  sessao.setCodigoExcursao(codigoExcursao);

  if (cntrServicoExcursao->cadastrarSessao(sessao, email))
  {
    cout << texto7 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto8 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoSessao::editarSessao(Email email)
{
  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Código da Sessão que você deseja alterar?  : ";
  char texto3[] = "Data                                              : ";
  char texto4[] = "Horário                                           : ";
  char texto5[] = "Idioma                                            : ";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso na edição. Digite algo.";
  char texto8[] = "Falha na edição. Digite algo.";

  int campo;
  char campo1[80], campo2[80], campo3[80], campo4[80];

  Codigo codigo;
  Data data;
  Horario horario;
  Idioma idioma;

  CLR_SCR;

  cout << texto1 << endl;

  cout << texto2;
  cin.getline(campo1, sizeof(campo1));
  cout << texto3;
  cin.getline(campo2, sizeof(campo2));
  cout << texto4;
  cin.getline(campo3, sizeof(campo3));
  cout << texto5;
  cin.getline(campo4, sizeof(campo4));

  try
  {
    codigo.setCodigo(campo1);
    data.setData(campo2);
    horario.setHorario(campo3);
    idioma.setIdioma(campo4);
  }
  catch (invalid_argument &exp)
  {
    cout << texto6 << endl; // Informa formato incorreto.
    campo = getch() - 48;   // Leitura de caracter digitado.
    return;
  }

  Sessao sessao;
  sessao.setCodigo(codigo);
  sessao.setData(data);
  sessao.setHorario(horario);
  sessao.setIdioma(idioma);

  if (cntrServicoExcursao->editarSessao(sessao, email))
  {
    cout << texto7 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto8 << endl; // Informa falha.

  campo = getch() - 48;

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

  int campo;
  char campo1[80];

  Codigo codigo;

  CLR_SCR;                             // Limpa janela.
  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2 << endl;              // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    cout << texto3 << endl; // Informa falha.

    campo = getch() - 48; // Leitura de caracter digitado.

    return;
  }

  if (cntrServicoExcursao->descadastrarSessao(codigo, email) && campo1 != "")
  {
    cout << texto4 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto5 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoSessao::listarSessoes()
{
  int campo;
  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();

  CLR_SCR;
  for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
  {
    cout << "\n"
         << "Código              : " << sessao->getCodigo().getCodigo() << endl;
    cout << "Data                : " << sessao->getData().getData() << endl;
    cout << "Horário             : " << sessao->getHorario().getHorario() << endl;
    cout << "Idioma              : " << sessao->getIdioma().getIdioma() << endl;
    cout << "Código da Excursão  : " << sessao->getCodigoExcursao().getCodigo() << "\n"
         << endl;
    cout << "--------------------------------------------------------------" << endl;
  }
  campo = getch() - 48;
  return;
}

void CntrApresentacaoSessao::listarSessoes(Email email)
{
  int campo;
  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();

  CLR_SCR;
  for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
  {
    cout << "\n"
         << "Código              : " << sessao->getCodigo().getCodigo() << endl;
    cout << "Data                : " << sessao->getData().getData() << endl;
    cout << "Horário             : " << sessao->getHorario().getHorario() << endl;
    cout << "Idioma              : " << sessao->getIdioma().getIdioma() << endl;
    cout << "Código da Excursão  : " << sessao->getCodigoExcursao().getCodigo() << "\n"
         << endl;
    cout << "--------------------------------------------------------------" << endl;
  }
  campo = getch() - 48;
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Listar avaliações.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

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
  char texto2[] = "1 - Cadastrar Avaliação.";
  char texto3[] = "2 - Listar Avaliações";
  char texto4[] = "3 - Consultar Avaliação.";
  char texto5[] = "4 - Editar Avaliação.";
  char texto6[] = "5 - Excluir Avaliação.";
  char texto7[] = "6 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    CLR_SCR;                // Limpa janela.
    cout << texto1 << endl; // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cout << texto4 << endl; // Imprime nome do campo.
    cout << texto5 << endl; // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    cout << texto7 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

    switch (campo)
    {
    case 1:
      cadastrarAvaliacao(email);
      break;
    case 2:
      listarAvaliacoes(email);
      break;
    case 3:
      consultarAvaliacao(email);
      break;
    case 4:
      editarAvaliacao(email);
      break;
    case 5:
      descadastrarAvaliacao(email);
      break;
    case 6:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoAvaliacao::consultarAvaliacao(Email email)
{

  char texto1[] = "Informe o seguinte valor: ";
  char texto2[] = "Código              :";
  char texto3[] = "Dados em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso na recuperação. Digite algo.";
  char texto5[] = "Falha na recuperação. Digite algo.";

  char campo1[80];
  int campo;

  Codigo codigo;

  CLR_SCR; // Limpa janela.
  bool apresentar = true;
  while (apresentar)
  {

    cout << texto1 << endl;              // Imprime nome do campo.
    cout << texto2;                      // Imprime nome do campo.
    cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

    try
    {
      codigo.setCodigo(campo1);
    }
    catch (invalid_argument &exp)
    {
      cout << texto3 << endl; // Informa formato incorreto.
      campo = getch() - 48;   // Leitura de caracter digitado.
    }

    try
    {

      Avaliacao avaliacao = cntrServicoExcursao->recuperarAvaliacao(codigo);

      cout << "\n"
           << "Código             : " << avaliacao.getCodigo().getCodigo() << endl;
      cout << "Título             : " << avaliacao.getNota().getNota() << endl;
      cout << "Nota               : " << avaliacao.getNota().getNota() << endl;
      cout << "Descrição          : " << avaliacao.getDescricao().getDescricao() << endl;
      cout << "Email do Avaliador : " << avaliacao.getEmail().getEmail() << endl;
      cout << "Código da Excursão : " << avaliacao.getCodigoExcursao().getCodigo() << "\n"
           << endl;
    }
    catch (...)
    {
      cout << texto5 << endl; // Informa falha.
    }
    cout << "1 - Recuperar outra avaliação" << endl;
    cout << "2 - Retornar" << endl;
    campo = getch() - 48;

    switch (campo)
    {
    case 1:
      CLR_SCR;
      continue;
    case 2:
      apresentar = false;
      break;
    default:
      CLR_SCR;
      apresentar = false;
      break;
    }
  }
  return;
}

void CntrApresentacaoAvaliacao::cadastrarAvaliacao(Email email)
{
  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nota                :";
  char texto4[] = "Descricao           :";
  char texto5[] = "Código da Excursão  :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";

  int campo;
  char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.
  Nota nota;
  Descricao descricao;
  Codigo codigoExcursao;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
  int icampo2 = atoi(campo1);

  cout << texto4;                      // Imprime nome do campo.
  cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
  cout << texto5;                      // Imprime nome do campo.
  cin.getline(campo3, sizeof(campo3)); // L� valor do campo.

  try
  {
    nota.setNota(icampo2);
    descricao.setDescricao(campo2);
    codigoExcursao.setCodigo(campo3);
  }
  catch (invalid_argument &exp)
  {
    cout << texto6 << endl; // Informa formato incorreto.

    campo = getch() - 48; // Leitura de caracter digitado.

    return;
  }

  // Instancia e inicializa entidades.

  Avaliacao avaliacao;
  avaliacao.setNota(nota);
  avaliacao.setDescricao(descricao);

  if (cntrServicoExcursao->cadastrarAvaliacao(avaliacao, email, codigoExcursao))
  {
    cout << texto7 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto8 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoAvaliacao::editarAvaliacao(Email email)
{
  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Código da Avaliação que você deseja alterar?  : ";
  char texto3[] = "Nota               : ";
  char texto4[] = "Descricao          : ";
  char texto5[] = "Dados em formato incorreto. Digite algo.";
  char texto6[] = "Sucesso na edição. Digite algo.";
  char texto7[] = "Falha na edição. Digite algo.";

  int campo;
  char campo1[80], campo2[80], campo3[80];

  Codigo codigo;
  Nota nota;
  Descricao descricao;

  CLR_SCR;

  cout << texto1 << endl;

  cout << texto2;
  cin.getline(campo1, sizeof(campo1));
  cout << texto3;
  cin.getline(campo2, sizeof(campo2));
  cout << texto4;
  cin.getline(campo3, sizeof(campo3));

  try
  {
    codigo.setCodigo(campo1);
    nota.setNota(stoi(campo2));
    descricao.setDescricao(campo3);
  }
  catch (invalid_argument &exp)
  {
    cout << texto5 << endl; // Informa formato incorreto.
    campo = getch() - 48;   // Leitura de caracter digitado.
    return;
  }

  Avaliacao avaliacao;
  avaliacao.setCodigo(codigo);
  avaliacao.setNota(nota);
  avaliacao.setDescricao(descricao);

  if (cntrServicoExcursao->editarAvaliacao(avaliacao, email))
  {
    cout << texto6 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto7 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoAvaliacao::descadastrarAvaliacao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma avaliação: ";
  char texto2[] = "Código da avaliação : ";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso no descadastramento. Digite algo.";
  char texto5[] = "Falha no descadastramento. Digite algo.";

  int campo;
  char campo1[80];

  Codigo codigo;

  CLR_SCR;                             // Limpa janela.
  cout << texto1 << endl;              // Imprime nome do campo.
  cout << texto2;                      // Imprime nome do campo.
  cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    cout << texto3 << endl; // Informa falha.

    campo = getch() - 48; // Leitura de caracter digitado.

    return;
  }

  if (cntrServicoExcursao->descadastrarAvaliacao(codigo, email) && campo1 != "")
  {
    cout << texto4 << endl; // Informa sucesso.

    campo = getch() - 48;

    return;
  }

  cout << texto5 << endl; // Informa falha.

  campo = getch() - 48;

  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoes()
{
  int campo;
  list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes();

  CLR_SCR;
  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    cout << "\n"
         << "Código             : " << avaliacao->getCodigo().getCodigo() << endl;
    cout << "Nota               : " << avaliacao->getNota().getNota() << endl;
    cout << "Descricao          : " << avaliacao->getDescricao().getDescricao() << endl;
    cout << "Email do Avaliador : " << avaliacao->getEmail().getEmail() << endl;
    cout << "Código da Excursão : " << avaliacao->getCodigoExcursao().getCodigo() << "\n"
         << endl;
    cout << "--------------------------------------------------------------" << endl;
  }
  campo = getch() - 48;
  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoes(Email email)
{
  int campo;
  list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes();

  CLR_SCR;
  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    cout << "\n"
         << "Código             : " << avaliacao->getCodigo().getCodigo() << endl;
    cout << "Nota               : " << avaliacao->getNota().getNota() << endl;
    cout << "Descricao          : " << avaliacao->getDescricao().getDescricao() << endl;
    cout << "Email do Avaliador : " << avaliacao->getEmail().getEmail() << endl;
    cout << "Código da Excursão : " << avaliacao->getCodigoExcursao().getCodigo() << "\n"
         << endl;
    cout << "--------------------------------------------------------------" << endl;
  }
  campo = getch() - 48;
  return;
}