// #include "controladoraApresentacao.h"
// #include <conio.h>
// #include <string>

// void CntrApresentacaoControle::encerrar()
// {
//   exit(0);
// }
// void CntrApresentacaoControle::executar()
// {

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Acessar sistema.";
//   char texto3[] = "2 - Cadastrar usuario.";
//   char texto4[] = "3 - Acessar dados sobre excurs�es.";
//   char texto5[] = "4 - Acessar dados sobre sess�es.";
//   char texto6[] = "5 - Acessar dados sobre avalia��es.";
//   char texto7[] = "6 - Encerrar execu��o do sistema.";

//   char texto8[] = "Selecione um dos servicos : ";
//   char texto9[] = "1 - Selecionar servicos de usuarios.";
//   char texto10[] = "2 - Selecionar servicos relacionados a excurs�es.";
//   char texto11[] = "3 - Selecionar servicos relacionados a sess�es.";
//   char texto12[] = "4 - Selecionar servicos relacionados a avalia��es.";
//   char texto13[] = "5 - Encerrar sessao.";

//   char texto14[] = "Falha na autentica��o. Digite algo para continuar.";

//   int campo;
//   bool apresentarAutenticacao = false;
//   bool apresentar = true;

//   while (apresentar)
//   {
//     if (apresentar == false)
//     {
//       return;
//     }
//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.
//     cout << texto4 << endl; // Imprime nome do campo.
//     cout << texto5 << endl; // Imprime nome do campo.
//     cout << texto6 << endl; // Imprime nome do campo.
//     cout << texto7 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e conversao de ASCII.

//     switch (campo)
//     {
//     case 1:
//       apresentarAutenticacao = true;
//       if (cntrApresentacaoAutenticacao->autenticar(&email))
//       {
//         while (apresentarAutenticacao)
//         {
//           CLR_SCR;                 // Limpa janela.
//           cout << texto8 << endl;  // Imprime nome do campo.
//           cout << texto9 << endl;  // Imprime nome do campo.
//           cout << texto10 << endl; // Imprime nome do campo.
//           cout << texto11 << endl; // Imprime nome do campo.
//           cout << texto12 << endl; // Imprime nome do campo.
//           cout << texto13 << endl; // Imprime nome do campo.

//           campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//           switch (campo)
//           {
//           case 1:
//             cntrApresentacaoUsuario->executar(email); // Solicita servi�o de pessoal.
//             break;
//           case 2:
//             cntrApresentacaoExcursao->executar(email);
//             break;
//           case 3:
//             cntrApresentacaoSessao->executar(email); // Solicita servi�o de produto financeiro.
//             break;
//           case 4:
//             cntrApresentacaoAvaliacao->executar(email); // Solicita servi�o de produto financeiro.
//             break;
//           case 5:
//             apresentarAutenticacao = false;
//             break;
//           }
//         }
//       }
//       else
//       {
//         CLR_SCR;                 // Limpa janela.
//         cout << texto14 << endl; // Imprime mensagem.
//         campo = getch() - 48;    // Leitura de caracter digitado.
//       }
//       break;
//     case 2:

//       cntrApresentacaoUsuario->cadastrar();
//       break;
//     case 3:

//       cntrApresentacaoExcursao->executar();
//       break;
//     case 4:

//       cntrApresentacaoSessao->executar();
//       break;
//     case 5:

//       cntrApresentacaoAvaliacao->executar();
//       break;
//     case 6:
//       CLR_SCR;
//       apresentar = false;
//       break;
//     }
//   }
//   return;
// }

// //--------------------------------------------------------------------------------------------

// bool CntrApresentacaoAutenticacao::autenticar(Email *email)
// {

//   char texto1[] = "Digite o email : ";
//   char texto2[] = "Digite a senha : ";
//   char texto3[] = "Dado em formato incorreto. Digite algo.";
//   char texto4[] = "1 - Tentar novamente.";
//   char texto5[] = "2 - Voltar para a tela inicial.";
//   char texto6[] = "Autenticado com sucesso.";
//   char texto7[] = "Falha na autentica��o. Digite algo.";

//   char campo1[80];
//   char campo2[80];
//   int campo;

//   Senha senha;

//   bool apresentar = true;
//   while (apresentar)
//   {

//     CLR_SCR;
//     cout << texto1;
//     cin >> campo1;
//     cout << texto2;
//     cin >> campo2;

//     try
//     {
//       email->setEmail(string(campo1));
//       senha.setSenha(string(campo2));

//       if (cntr->autenticar(*email, senha))
//       {
//         cout << texto6 << endl;
//         campo = getch() - 48;
//         return true;
//       }
//       else
//       {
//         CLR_SCR;                // Limpa janela.
//         cout << texto7 << endl; // Informa formato incorreto.
//         campo = getch() - 48;
//       }
//     }
//     catch (invalid_argument &exp)
//     {
//       CLR_SCR;                // Limpa janela.
//       cout << texto3 << endl; // Informa formato incorreto.
//       campo = getch() - 48;   // L� caracter digitado.
//     }

//     // CLR_SCR;                                                                            // Limpa janela.

//     cout << texto4 << endl;
//     cout << texto5 << endl;

//     campo = getch() - 48;

//     switch (campo)
//     {
//     case 1:
//       continue;
//     case 2:
//       return false;
//     }
//   }
//   return true;
// }
// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoUsuario::executar(Email email)
// {

//   // Mensagens a serem apresentadas na tela de sele��o de servi�o..

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Editar Dados.";
//   char texto3[] = "2 - Consultar Dados.";
//   char texto4[] = "3 - Excluir Cadastro.";
//   char texto5[] = "4 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela de sela��o de servi�o.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.
//     cout << texto4 << endl; // Imprime nome do campo.
//     cout << texto5 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       editarUsuario(email);
//       break;
//     case 2:
//       consultarDadosUsuario(email);
//       break;
//     case 3:
//       excluirUsuario(email);
//       break;
//     case 4:
//       apresentar = false;
//       break;
//     }
//   }
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoUsuario::cadastrar()
// {

//   // Mensagens a serem apresentadas na tela de cadastramento.

//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Nome            :";
//   char texto3[] = "Email           :";
//   char texto4[] = "Senha           :";
//   char texto5[] = "Dados em formato incorreto. Digite algo.";
//   char texto6[] = "Sucesso no cadastramento. Digite algo.";
//   char texto7[] = "Falha no cadastramento. Digite algo.";
//   int campo;
//   char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

//   // Instancia os dom�nios.

//   Nome nome;
//   Email email;
//   Senha senha;

//   // Apresenta tela de cadastramento.

//   CLR_SCR; // Limpa janela.

//   cout << texto1 << endl; // Imprime nome do campo.
//   cout << texto2;         // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1));
//   cout << texto3;                      // Imprime nome do campo.
//   cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
//   cout << texto4;                      // Imprime nome do campo.
//   cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
//   try
//   {
//     nome.setNome(string(campo1));
//     email.setEmail(string(campo2));
//     senha.setSenha(string(campo3));
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto5 << endl; // Informa formato incorreto.
//     campo = getch() - 48;   // Leitura de caracter digitado.
//     return;
//   }

//   // Instancia e inicializa entidades.

//   Usuario usuario;

//   usuario.setNome(nome);
//   usuario.setEmail(email);
//   usuario.setSenha(senha);

//   if (cntrServicoUsuario->cadastrarUsuario(usuario))
//   {
//     cout << texto6 << endl; // Informa sucesso.
//     campo = getch() - 48;
//     return;
//   }
//   cout << texto7 << endl; // Informa falha.
//   campo = getch() - 48;
//   return;
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoUsuario::consultarDadosUsuario(Email email)
// {
//   int campo;
//   Usuario usuario = cntrServicoUsuario->recuperar(email);

//   cout << "Email         : " << usuario.getEmail().getEmail() << endl;
//   cout << "Nome          : " << usuario.getNome().getNome() << endl;
//   cout << "Senha         : " << usuario.getSenha().getSenha() << endl;
// }

// void CntrApresentacaoUsuario::editarUsuario(Email email)
// {

//   // Mensagens a serem apresentadas na tela de cadastramento.

//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Nome            :";
//   char texto3[] = "Senha           :";
//   char texto4[] = "Dados em formato incorreto. Digite algo.";
//   char texto5[] = "Sucesso na altera��o. Digite algo.";
//   char texto6[] = "Falha na altera��o. Digite algo.";
//   int campo;
//   char campo1[80], campo2[80]; // Cria campos para entrada dos dados.

//   // Instancia os dom�nios.

//   Nome nome;
//   Senha senha;

//   // Apresenta tela de cadastramento.

//   CLR_SCR; // Limpa janela.

//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
//   cout << texto3;                      // Imprime nome do campo.
//   cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
//   try
//   {
//     nome.setNome(string(campo1));
//     senha.setSenha(string(campo2));
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto4 << endl; // Informa formato incorreto.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   // Instancia e inicializa entidades.

//   Usuario usuario;

//   usuario.setNome(nome);
//   usuario.setSenha(senha);
//   usuario.setEmail(email);

//   if (cntrServicoUsuario->editarUsuario(usuario))
//   {
//     cout << texto5 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto6 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoUsuario::excluirUsuario(Email email)
// {
//   CntrApresentacaoControle *cntrApresentacaoControle;

//   char texto1[] = "Tem certeza que deseja excluir seu perfil do sistema?";
//   char texto2[] = "1 - Sim, quero excluir.";
//   char texto3[] = "2 - N�o, entrei nessa op��o por engano.";
//   char texto4[] = "Excluido com sucesso. VoCo n�o faz mais parte desse sistema";

//   int campo;

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     CLR_SCR;
//     cout << texto1 << "\n"
//          << endl;
//     cout << texto2 << endl;
//     cout << texto3 << endl;

//     campo = getch() - 48;

//     switch (campo)
//     {
//     case 1:
//       cntrServicoUsuario->descadastrarUsuario(email);
//       cout << texto4;
//       campo = getch() - 48;
//       apresentar = false;
//       cntrApresentacaoControle->encerrar();
//       break;
//     case 2:
//       apresentar = false;
//       break;
//     }
//   }
// }
// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoExcursao::executar()
// {

//   // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Listar excurs�es.";
//   char texto3[] = "2 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela simplificada de produtos financeiros.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       listarExcursoes();
//       break;
//     case 2:
//       apresentar = false;
//       break;
//     }
//   }
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoExcursao::executar(Email email)
// {

//   // Mensagens a serem apresentadas tela completa de produtos financeiros.

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Cadastrar Excurs�o.";
//   char texto3[] = "2 - Listar Excurs�es";
//   char texto4[] = "3 - Consultar Excurs�o.";
//   char texto5[] = "4 - Editar Excurs�o.";
//   char texto6[] = "5 - Excluir Excurs�o.";
//   char texto7[] = "6 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela completa de produtos financeiros.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.
//     cout << texto4 << endl; // Imprime nome do campo.
//     cout << texto5 << endl; // Imprime nome do campo.
//     cout << texto6 << endl; // Imprime nome do campo.
//     cout << texto7 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       cadastrarExcursao(email);
//       break;
//     case 2:
//       listarExcursoes(email);
//       break;
//     case 3:
//       consultarExcursao(email);
//       break;
//     case 4:
//       editarExcursao(email);
//       break;
//     case 5:
//       descadastrarExcursao(email);
//       break;
//     case 6:
//       apresentar = false;
//       break;
//     }
//   }
// }

// void CntrApresentacaoExcursao::consultarExcursao(Email email)
// {

//   char texto1[] = "Informe o seguinte valor: ";
//   char texto2[] = "C�digo              : ";
//   char texto3[] = "Dados em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso na recupera��o. Digite algo.";
//   char texto5[] = "Falha na recupera��o. Digite algo.";

//   char campo1[80];
//   int campo;

//   Codigo codigo;

//   CLR_SCR; // Limpa janela.
//   bool apresentar = true;
//   while (apresentar)
//   {

//     cout << texto1 << endl;              // Imprime nome do campo.
//     cout << texto2;                      // Imprime nome do campo.
//     cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//     try
//     {
//       codigo.setCodigo(campo1);
//     }
//     catch (invalid_argument &exp)
//     {
//       cout << texto3 << endl; // Informa formato incorreto.
//       campo = getch() - 48;   // Leitura de caracter digitado.
//     }

//     try
//     {

//       Excursao excursao = cntrServicoExcursao->recuperarExcursao(codigo);

//       cout << "\n"
//            << "C�digo        : " << excursao.getCodigo().getCodigo() << endl;
//       cout << "T�tulo        : " << excursao.getTitulo().getTitulo() << endl;
//       if (excursao.getNota().getNota() != -1)
//         cout << "Nota          : " << excursao.getNota().getNota() << endl;
//       else
//         cout << "Nota          : N�o h� avalia��es cadastradas para essa Excurs�o" << endl;
//       cout << "Cidade        : " << excursao.getCidade().getCidade() << endl;
//       cout << "Dura��o       : " << excursao.getDuracao().getDuracao() << endl;
//       cout << "Endere�o      : " << excursao.getEndereco().getEndereco() << endl;
//       cout << "Email do Guia : " << excursao.getEmail().getEmail() << "\n"
//            << endl;
//     }
//     catch (...)
//     {
//       cout << texto5 << endl; // Informa falha.
//     }
//     cout << "1 - Recuperar outra excurs�o" << endl;
//     cout << "2 - Retornar" << endl;
//     campo = getch() - 48;

//     switch (campo)
//     {
//     case 1:
//       CLR_SCR;
//       continue;
//     case 2:
//       apresentar = false;
//       break;
//     default:
//       CLR_SCR;
//       apresentar = false;
//       break;
//     }
//   }
//   return;
// }

// void CntrApresentacaoExcursao::cadastrarExcursao(Email email)
// {
//   // Mensagens a serem apresentadas na tela de cadastramento.

//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "C�digo          : ";
//   char texto3[] = "T�tulo          : ";
//   // char texto4[] = "Nota            :";
//   char texto5[] = "Cidade          : ";
//   char texto6[] = "Dura��o         : ";
//   char texto7[] = "Descri��o       : ";
//   char texto8[] = "Endere�o        : ";
//   char texto9[] = "Dados em formato incorreto. Digite algo.";
//   char texto10[] = "Sucesso no cadastramento. Digite algo.";
//   char texto11[] = "Falha no cadastramento. Digite algo.";
//   int campo;
//   char campo0[80], campo1[80], campo2[80], campo3[80], campo4[80], campo5[80]; // Cria campos para entrada dos dados.

//   // Instancia os dom�nios.
//   // Codigo codigo;
//   Titulo titulo;
//   // Nota nota;
//   Cidade cidade;
//   Duracao duracao;
//   Descricao descricao;
//   Endereco endereco;

//   // Apresenta tela de cadastramento.

//   CLR_SCR; // Limpa janela.

//   cout << texto1 << endl; // Imprime nome do campo.
//   // cout << texto2 << endl; // Imprime nome do campo.
//   // cin >> campo0;                                    // L� valor do campo.
//   cout << texto3;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
//   // cout << texto4 << endl; // Imprime nome do campo.
//   // cin >> campo2;                                    // L� valor do campo.
//   // int icampo2 = atoi(campo2);
//   cout << texto5;
//   cin.getline(campo2, sizeof(campo2));
//   cout << texto6;                      // Imprime nome do campo.
//   cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
//   cout << texto7;                      // Imprime nome do campo.
//   cin.getline(campo4, sizeof(campo4));
//   cout << texto8; // Imprime nome do campo.
//   cin.getline(campo5, sizeof(campo5));
//   try
//   {
//     // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
//     // codigo.setCodigo(campo0);
//     titulo.setTitulo(campo1);
//     // nota.setNota(icampo2);
//     cidade.setCidade(campo2);
//     duracao.setDuracao(campo3);
//     descricao.setDescricao(campo4);
//     endereco.setEndereco(campo5);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto9 << endl; // Informa formato incorreto.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   // Instancia e inicializa entidades.

//   Excursao excursao;

//   // excursao.setCodigo(codigo);
//   excursao.setTitulo(titulo);
//   // excursao.setNota(nota);
//   excursao.setCidade(cidade);
//   excursao.setDuracao(duracao);
//   excursao.setDescricao(descricao);
//   excursao.setEndereco(endereco);

//   if (cntrServicoExcursao->cadastrarExcursao(excursao, email))
//   {
//     cout << texto10 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto11 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoExcursao::editarExcursao(Email email)
// {
//   // Mensagens a serem apresentadas na tela de cadastramento.

//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Qual o C�digo da Excurs�o que voc� deseja alterar?  : ";
//   char texto3[] = "T�tulo          : ";
//   // char texto4[] = "Nota            : ";
//   char texto5[] = "Cidade          : ";
//   char texto6[] = "Dura��o         : ";
//   char texto7[] = "Descri��o       : ";
//   char texto8[] = "Endere�o        : ";
//   char texto9[] = "Dados em formato incorreto. Digite algo.";
//   char texto10[] = "Sucesso na altera��o. Digite algo.";
//   char texto11[] = "Falha na altera��o. Digite algo.";
//   int campo;
//   char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

//   // Instancia os dom�nios.
//   Codigo codigo;
//   Titulo titulo;
//   // Nota nota;
//   Cidade cidade;
//   Duracao duracao;
//   Descricao descricao;
//   Endereco endereco;

//   // Apresenta tela de cadastramento.

//   CLR_SCR; // Limpa janela.

//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo0, sizeof(campo0)); // L� valor do campo.
//   cout << texto3;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
//   // cout << texto4; // Imprime nome do campo.
//   // cin >> campo2;                                    // L� valor do campo.
//   // int icampo2 = atoi(campo2);
//   cout << texto5;                      // Imprime nome do campo.
//   cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
//   cout << texto6;                      // Imprime nome do campo.
//   cin.getline(campo4, sizeof(campo4)); // L� valor do campo.
//   cout << texto7;                      // Imprime nome do campo.
//   cin.getline(campo5, sizeof(campo5)); // L� valor do campo.
//   cout << texto8;                      // Imprime nome do campo.
//   cin.getline(campo6, sizeof(campo5)); // L� valor do campo.
//   try
//   {
//     // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
//     codigo.setCodigo(campo0);
//     titulo.setTitulo(campo1);
//     // nota.setNota(icampo2);
//     cidade.setCidade(campo3);
//     duracao.setDuracao(campo4);
//     descricao.setDescricao(campo5);
//     endereco.setEndereco(campo6);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto9 << endl; // Informa formato incorreto.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   // Instancia e inicializa entidades.

//   Excursao excursao;

//   excursao.setCodigo(codigo);
//   excursao.setTitulo(titulo);
//   // excursao.setNota(nota);
//   excursao.setCidade(cidade);
//   excursao.setDuracao(duracao);
//   excursao.setDescricao(descricao);
//   excursao.setEndereco(endereco);

//   if (cntrServicoExcursao->editarExcursao(excursao, email))
//   {
//     cout << texto10 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto11 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoExcursao::descadastrarExcursao(Email email)
// {
//   // Mensagens a serem apresentadas na tela de cadastramento.
//   char texto1[] = "Descadastrar uma excursao: ";
//   char texto2[] = "C�digo          :";
//   char texto3[] = "Dado em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso no descadastramento. Digite algo.";
//   char texto5[] = "Falha no descadastramento. Digite algo.";

//   int campo;
//   char campo1[80];

//   Codigo codigo;

//   CLR_SCR;                             // Limpa janela.
//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//   try
//   {
//     codigo.setCodigo(campo1);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto3 << endl; // Informa falha.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   if (cntrServicoExcursao->descadastrarExcursao(codigo, email) && campo1 != "")
//   {
//     cout << texto4 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto5 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoExcursao::listarExcursoes()
// {
//   int campo;
//   list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

//   CLR_SCR;
//   for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
//   {
//     cout << "\n"
//          << "C�digo        : " << excursao->getCodigo().getCodigo() << endl;
//     cout << "T�tulo        : " << excursao->getTitulo().getTitulo() << endl;
//     if (excursao->getNota().getNota() != -1)
//       cout << "Nota          : " << excursao->getNota().getNota() << endl;
//     else
//       cout << "Nota          : N�o h� avalia��es cadastradas para essa Excurs�o" << endl;
//     cout << "Cidade        : " << excursao->getCidade().getCidade() << endl;
//     cout << "Dura��o       : " << excursao->getDuracao().getDuracao() << endl;
//     cout << "Endere�o      : " << excursao->getEndereco().getEndereco() << endl;
//     cout << "Email do Guia : " << excursao->getEmail().getEmail() << "\n"
//          << endl;
//     cout << "--------------------------------------------------------------" << endl;
//   }
//   campo = getch() - 48;
//   return;
// }
// void CntrApresentacaoExcursao::listarExcursoes(Email email)
// {
//   int campo;
//   list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

//   CLR_SCR;
//   for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
//   {
//     cout << "\n"
//          << "C�digo        : " << excursao->getCodigo().getCodigo() << endl;
//     cout << "T�tulo        : " << excursao->getTitulo().getTitulo() << endl;
//     if (excursao->getNota().getNota() != -1)
//       cout << "Nota          : " << excursao->getNota().getNota() << endl;
//     else
//       cout << "Nota          : N�o h� avalia��es cadastradas para essa Excurs�o" << endl;
//     cout << "Cidade        : " << excursao->getCidade().getCidade() << endl;
//     cout << "Dura��o       : " << excursao->getDuracao().getDuracao() << endl;
//     cout << "Endere�o      : " << excursao->getEndereco().getEndereco() << endl;
//     cout << "Email do Guia : " << excursao->getEmail().getEmail() << "\n"
//          << endl;
//     cout << "--------------------------------------------------------------" << endl;
//   }
//   campo = getch() - 48;
//   return;
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoSessao::executar()
// {

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Listar sess�es.";
//   char texto3[] = "2 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela simplificada de produtos financeiros.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       listarSessoes();
//       break;
//     case 2:
//       apresentar = false;
//       break;
//     }
//   }
// }

// void CntrApresentacaoSessao::executar(Email email)
// {

//   // Mensagens a serem apresentadas tela completa de produtos financeiros.

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Cadastar sess�o.";
//   char texto3[] = "2 - Listar sess�es.";
//   ch3 - Listar sess�es por excurs�o.ar texto4[] = "";
//   char texto5[] = "4 - Consultar sess�o.";
//   char texto6[] = "5 - Editar sess�o.";
//   char texto7[] = "6 - Excluir sess�o.";
//   char texto8[] = "7 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela completa de produtos financeiros.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.
//     cout << texto4 << endl; // Imprime nome do campo.
//     cout << texto5 << endl; // Imprime nome do campo.
//     cout << texto6 << endl; // Imprime nome do campo.
//     cout << texto7 << endl; // Imprime nome do campo.
//     cout << texto8 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       cadastrarSessao(email);
//       break;
//     case 2:
//       listarSessoes(email);
//       break;
//     case 3:
//       listarSessoesExcursao(email);
//       break;
//     case 4:
//       consultarSessao(email);
//       break;
//     case 5:
//       editarSessao(email);
//       break;
//     case 6:
//       descadastrarSessao(email);
//       break;
//     case 7:
//       apresentar = false;
//       break;
//     }
//   }
// }

// void CntrApresentacaoSessao::consultarSessao(Email email)
// {

//   char texto1[] = "Informe o seguinte valor: ";
//   char texto2[] = "C�digo              : ";
//   char texto3[] = "Dados em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso na recupera��o. Digite algo.";
//   char texto5[] = "Falha na recupera��o. Digite algo.";

//   char campo1[80];
//   int campo;

//   Codigo codigo;

//   CLR_SCR; // Limpa janela.
//   bool apresentar = true;
//   while (apresentar)
//   {

//     cout << texto1 << endl;              // Imprime nome do campo.
//     cout << texto2;                      // Imprime nome do campo.
//     cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//     try
//     {
//       codigo.setCodigo(campo1);
//     }
//     catch (invalid_argument &exp)
//     {
//       cout << texto3 << endl; // Informa formato incorreto.
//       campo = getch() - 48;   // Leitura de caracter digitado.
//     }

//     try
//     {

//       Sessao sessao = cntrServicoExcursao->recuperarSessao(codigo);

//       cout << "\n"
//            << "C�digo             : " << sessao.getCodigo().getCodigo() << endl;
//       cout << "Data               : " << sessao.getData().getData() << endl;
//       cout << "Hor�rio            : " << sessao.getHorario().getHorario() << endl;
//       cout << "Idioma             : " << sessao.getIdioma().getIdioma() << endl;
//       cout << "C�digo da Excurs�o : " << sessao.getCodigoExcursao().getCodigo() << "\n"
//            << endl;
//     }
//     catch (...)
//     {
//       cout << texto5 << endl; // Informa falha.
//     }
//     cout << "1 - Recuperar outra sess�o" << endl;
//     cout << "2 - Retornar" << endl;
//     campo = getch() - 48;

//     switch (campo)
//     {
//     case 1:
//       CLR_SCR;
//       continue;
//     case 2:
//       apresentar = false;
//       break;
//     default:
//       CLR_SCR;
//       apresentar = false;
//       break;
//     }
//   }
//   return;
// }

// void CntrApresentacaoSessao::cadastrarSessao(Email email)
// {
//   // Mensagens a serem apresentadas na tela de cadastramento.

//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Data                :";
//   char texto3[] = "Horario             :";
//   char texto4[] = "Idioma              :";
//   char texto5[] = "C�digo da Excurs�o  :";
//   char texto6[] = "Dados em formato incorreto. Digite algo.";
//   char texto7[] = "Sucesso no cadastramento. Digite algo.";
//   char texto8[] = "Falha no cadastramento. Digite algo.";

//   int campo;
//   char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

//   // Instancia os dom�nios.
//   Data data;
//   Horario horario;
//   Idioma idioma;
//   Codigo codigoExcursao;

//   // Apresenta tela de cadastramento.

//   CLR_SCR; // Limpa janela.

//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
//   cout << texto3;                      // Imprime nome do campo.
//   cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
//   cout << texto4;                      // Imprime nome do campo.
//   cin.getline(campo3, sizeof(campo3)); // L� valor do campo.
//   cout << texto5;                      // Imprime nome do campo.
//   cin.getline(campo4, sizeof(campo4)); // L� valor do campo.

//   try
//   {
//     data.setData(campo1);
//     horario.setHorario(campo2);
//     idioma.setIdioma(campo3);
//     codigoExcursao.setCodigo(campo4);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto6 << endl; // Informa formato incorreto.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   // Instancia e inicializa entidades.

//   Sessao sessao;

//   sessao.setData(data);
//   sessao.setHorario(horario);
//   sessao.setIdioma(idioma);
//   sessao.setCodigoExcursao(codigoExcursao);

//   if (cntrServicoExcursao->cadastrarSessao(sessao, email))
//   {
//     cout << texto7 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto8 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoSessao::editarSessao(Email email)
// {
//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Qual o C�digo da Sess�o que voc� deseja alterar?  : ";
//   char texto3[] = "Data                                              : ";
//   char texto4[] = "Hor�rio                                           : ";
//   char texto5[] = "Idioma                                            : ";
//   char texto6[] = "Dados em formato incorreto. Digite algo.";
//   char texto7[] = "Sucesso na edi��o. Digite algo.";
//   char texto8[] = "Falha na edi��o. Digite algo.";

//   int campo;
//   char campo1[80], campo2[80], campo3[80], campo4[80];

//   Codigo codigo;
//   Data data;
//   Horario horario;
//   Idioma idioma;

//   CLR_SCR;

//   cout << texto1 << endl;

//   cout << texto2;
//   cin.getline(campo1, sizeof(campo1));
//   cout << texto3;
//   cin.getline(campo2, sizeof(campo2));
//   cout << texto4;
//   cin.getline(campo3, sizeof(campo3));
//   cout << texto5;
//   cin.getline(campo4, sizeof(campo4));

//   try
//   {
//     codigo.setCodigo(campo1);
//     data.setData(campo2);
//     horario.setHorario(campo3);
//     idioma.setIdioma(campo4);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto6 << endl; // Informa formato incorreto.
//     campo = getch() - 48;   // Leitura de caracter digitado.
//     return;
//   }

//   Sessao sessao;
//   sessao.setCodigo(codigo);
//   sessao.setData(data);
//   sessao.setHorario(horario);
//   sessao.setIdioma(idioma);

//   if (cntrServicoExcursao->editarSessao(sessao, email))
//   {
//     cout << texto7 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto8 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoSessao::descadastrarSessao(Email email)
// {
//   // Mensagens a serem apresentadas na tela de cadastramento.
//   char texto1[] = "Descadastrar uma sess�o: ";
//   char texto2[] = "C�digo da sess�o :";
//   char texto3[] = "Dado em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso no descadastramento. Digite algo.";
//   char texto5[] = "Falha no descadastramento. Digite algo.";

//   int campo;
//   char campo1[80];

//   Codigo codigo;

//   CLR_SCR;                             // Limpa janela.
//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//   try
//   {
//     codigo.setCodigo(campo1);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto3 << endl; // Informa falha.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   if (cntrServicoExcursao->descadastrarSessao(codigo, email) && campo1 != "")
//   {
//     cout << texto4 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto5 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoSessao::listarSessoes()
// {
//   int campo;
//   list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();

//   CLR_SCR;
//   for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
//   {
//     cout << "\n"
//          << "C�digo              : " << sessao->getCodigo().getCodigo() << endl;
//     cout << "Data                : " << sessao->getData().getData() << endl;
//     cout << "Hor�rio             : " << sessao->getHorario().getHorario() << endl;
//     cout << "Idioma              : " << sessao->getIdioma().getIdioma() << endl;
//     cout << "C�digo da Excurs�o  : " << sessao->getCodigoExcursao().getCodigo() << "\n"
//          << endl;
//     cout << "--------------------------------------------------------------" << endl;
//   }
//   campo = getch() - 48;
//   return;
// }

// void CntrApresentacaoSessao::listarSessoes(Email email)
// {
//   int campo;
//   list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();

//   CLR_SCR;
//   for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
//   {
//     cout << "\n"
//          << "C�digo              : " << sessao->getCodigo().getCodigo() << endl;
//     cout << "Data                : " << sessao->getData().getData() << endl;
//     cout << "Hor�rio             : " << sessao->getHorario().getHorario() << endl;
//     cout << "Idioma              : " << sessao->getIdioma().getIdioma() << endl;
//     cout << "C�digo da Excurs�o  : " << sessao->getCodigoExcursao().getCodigo() << "\n"
//          << endl;
//     cout << "--------------------------------------------------------------" << endl;
//   }
//   campo = getch() - 48;
//   return;
// }
// void CntrApresentacaoSessao::listarSessoesExcursao(Email email)
// {
//   char texto1[] = "Informe o seguinte valor: ";
//   char texto2[] = "C�digo da Excurs�o      : ";
//   char texto3[] = "Dados em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso na recupera��o. Digite algo.";
//   char texto5[] = "Falha na recupera��o. Digite algo.";

//   char campo1[80];
//   int campo;

//   Codigo codigo;

//   CLR_SCR; // Limpa janela.
//   bool apresentar = true;
//   while (apresentar)
//   {

//     cout << texto1 << endl;              // Imprime nome do campo.
//     cout << texto2;                      // Imprime nome do campo.
//     cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//     try
//     {
//       codigo.setCodigo(campo1);
//     }
//     catch (invalid_argument &exp)
//     {
//       cout << texto3 << endl; // Informa formato incorreto.
//       campo = getch() - 48;   // Leitura de caracter digitado.
//     }
//     Excursao excursao;
//     excursao.setCodigo(codigo);

//     try
//     {
//       int campo;
//       list<Sessao> sessoes = cntrServicoExcursao->listarSessoesExcursao(excursao);

//       CLR_SCR;
//       for (auto avaliacao = begin(sessoes); avaliacao != end(sessoes); ++avaliacao)
//       {
//         cout << "\n"
//              << "C�digo             : " << avaliacao->getCodigo().getCodigo() << endl;
//         cout << "Data               : " << avaliacao->getData().getData() << endl;
//         cout << "HOr�rio            : " << avaliacao->getHorario().getHorario() << endl;
//         cout << "Idiomar            : " << avaliacao->getIdioma().getIdioma() << endl;
//         cout << "C�digo da Excurs�o : " << avaliacao->getCodigoExcursao().getCodigo() << "\n"
//              << endl;
//         cout << "--------------------------------------------------------------" << endl;
//       }
//       campo = getch() - 48;
//       return;
//     }
//     catch (...)
//     {
//       cout << texto5 << endl; // Informa falha.
//     }
//     cout << "1 - Listar avalia��es de outra excurs�o" << endl;
//     cout << "2 - Retornar" << endl;
//     campo = getch() - 48;

//     switch (campo)
//     {
//     case 1:
//       CLR_SCR;
//       continue;
//     case 2:
//       apresentar = false;
//       break;
//     default:
//       CLR_SCR;
//       apresentar = false;
//       break;
//     }
//   }
//   return;
// }

// //--------------------------------------------------------------------------------------------

// void CntrApresentacaoAvaliacao::executar()
// {

//   // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Listar avalia��es.";
//   char texto3[] = "2 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela simplificada de produtos financeiros.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       listarAvaliacoes();
//       break;
//     case 2:
//       apresentar = false;
//       break;
//     }
//   }
// }

// void CntrApresentacaoAvaliacao::executar(Email email)
// {

//   // Mensagens a serem apresentadas tela completa de produtos financeiros.

//   char texto1[] = "Selecione um dos servicos : ";
//   char texto2[] = "1 - Cadastrar Avalia��o.";
//   char texto3[] = "2 - Listar Avalia��es";
//   char texto4[] = "3 - Listar Avalia��es do Usuario";
//   char texto5[] = "4 - Listar Avalia��es por Excurs�o";
//   char texto6[] = "5 - Consultar Avalia��o.";
//   char texto7[] = "6 - Editar Avalia��o.";
//   char texto8[] = "7 - Excluir Avalia��o.";
//   char texto9[] = "8 - Retornar.";

//   int campo; // Campo de entrada.

//   bool apresentar = true; // Controle de la�o.

//   while (apresentar)
//   {

//     // Apresenta tela completa de produtos financeiros.

//     CLR_SCR;                // Limpa janela.
//     cout << texto1 << endl; // Imprime nome do campo.
//     cout << texto2 << endl; // Imprime nome do campo.
//     cout << texto3 << endl; // Imprime nome do campo.
//     cout << texto4 << endl; // Imprime nome do campo.
//     cout << texto5 << endl; // Imprime nome do campo.
//     cout << texto6 << endl; // Imprime nome do campo.
//     cout << texto7 << endl; // Imprime nome do campo.
//     cout << texto8 << endl; // Imprime nome do campo.
//     cout << texto9 << endl; // Imprime nome do campo.

//     campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

//     switch (campo)
//     {
//     case 1:
//       cadastrarAvaliacao(email);
//       break;
//     case 2:
//       listarAvaliacoes(email);
//       break;
//     case 3:
//       listarAvaliacoesUsuario(email);
//       break;
//     case 4:
//       listarAvaliacoesExcursao(email);
//       break;
//     case 5:
//       consultarAvaliacao(email);
//       break;
//     case 6:
//       editarAvaliacao(email);
//       break;
//     case 7:
//       descadastrarAvaliacao(email);
//       break;
//     case 8:
//       apresentar = false;
//       break;
//     }
//   }
// }

// void CntrApresentacaoAvaliacao::consultarAvaliacao(Email email)
// {

//   char texto1[] = "Informe o seguinte valor: ";
//   char texto2[] = "C�digo              :";
//   char texto3[] = "Dados em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso na recupera��o. Digite algo.";
//   char texto5[] = "Falha na recupera��o. Digite algo.";

//   char campo1[80];
//   int campo;

//   Codigo codigo;

//   CLR_SCR; // Limpa janela.
//   bool apresentar = true;
//   while (apresentar)
//   {

//     cout << texto1 << endl;              // Imprime nome do campo.
//     cout << texto2;                      // Imprime nome do campo.
//     cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//     try
//     {
//       codigo.setCodigo(campo1);
//     }
//     catch (invalid_argument &exp)
//     {
//       cout << texto3 << endl; // Informa formato incorreto.
//       campo = getch() - 48;   // Leitura de caracter digitado.
//     }

//     try
//     {

//       Avaliacao avaliacao = cntrServicoExcursao->recuperarAvaliacao(codigo);

//       cout << "\n"
//            << "C�digo             : " << avaliacao.getCodigo().getCodigo() << endl;
//       cout << "T�tulo             : " << avaliacao.getNota().getNota() << endl;
//       cout << "Nota               : " << avaliacao.getNota().getNota() << endl;
//       cout << "Descri��o          : " << avaliacao.getDescricao().getDescricao() << endl;
//       cout << "Email do Avaliador : " << avaliacao.getEmail().getEmail() << endl;
//       cout << "C�digo da Excurs�o : " << avaliacao.getCodigoExcursao().getCodigo() << "\n"
//            << endl;
//     }
//     catch (...)
//     {
//       cout << texto5 << endl; // Informa falha.
//     }
//     cout << "1 - Recuperar outra avalia��o" << endl;
//     cout << "2 - Retornar" << endl;
//     campo = getch() - 48;

//     switch (campo)
//     {
//     case 1:
//       CLR_SCR;
//       continue;
//     case 2:
//       apresentar = false;
//       break;
//     default:
//       CLR_SCR;
//       apresentar = false;
//       break;
//     }
//   }
//   return;
// }

// void CntrApresentacaoAvaliacao::cadastrarAvaliacao(Email email)
// {
//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Nota                :";
//   char texto4[] = "Descricao           :";
//   char texto5[] = "C�digo da Excurs�o  :";
//   char texto6[] = "Dados em formato incorreto. Digite algo.";
//   char texto7[] = "Sucesso no cadastramento. Digite algo.";
//   char texto8[] = "Falha no cadastramento. Digite algo.";

//   int campo;
//   char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.
//   Nota nota;
//   Descricao descricao;
//   Codigo codigoExcursao;

//   // Apresenta tela de cadastramento.

//   CLR_SCR; // Limpa janela.

//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.
//   int icampo2 = atoi(campo1);

//   cout << texto4;                      // Imprime nome do campo.
//   cin.getline(campo2, sizeof(campo2)); // L� valor do campo.
//   cout << texto5;                      // Imprime nome do campo.
//   cin.getline(campo3, sizeof(campo3)); // L� valor do campo.

//   try
//   {
//     nota.setNota(icampo2);
//     descricao.setDescricao(campo2);
//     codigoExcursao.setCodigo(campo3);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto6 << endl; // Informa formato incorreto.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   // Instancia e inicializa entidades.

//   Avaliacao avaliacao;
//   avaliacao.setNota(nota);
//   avaliacao.setDescricao(descricao);

//   if (cntrServicoExcursao->cadastrarAvaliacao(avaliacao, email, codigoExcursao))
//   {
//     cout << texto7 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto8 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoAvaliacao::editarAvaliacao(Email email)
// {
//   char texto1[] = "Preencha os seguintes campos: ";
//   char texto2[] = "Qual o C�digo da Avalia��o que voc� deseja alterar?  : ";
//   char texto3[] = "Nota               : ";
//   char texto4[] = "Descricao          : ";
//   char texto5[] = "Dados em formato incorreto. Digite algo.";
//   char texto6[] = "Sucesso na edi��o. Digite algo.";
//   char texto7[] = "Falha na edi��o. Digite algo.";

//   int campo;
//   char campo1[80], campo2[80], campo3[80];

//   Codigo codigo;
//   Nota nota;
//   Descricao descricao;

//   CLR_SCR;

//   cout << texto1 << endl;

//   cout << texto2;
//   cin.getline(campo1, sizeof(campo1));
//   cout << texto3;
//   cin.getline(campo2, sizeof(campo2));
//   cout << texto4;
//   cin.getline(campo3, sizeof(campo3));

//   try
//   {
//     codigo.setCodigo(campo1);
//     nota.setNota(stoi(campo2));
//     descricao.setDescricao(campo3);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto5 << endl; // Informa formato incorreto.
//     campo = getch() - 48;   // Leitura de caracter digitado.
//     return;
//   }

//   Avaliacao avaliacao;
//   avaliacao.setCodigo(codigo);
//   avaliacao.setNota(nota);
//   avaliacao.setDescricao(descricao);

//   if (cntrServicoExcursao->editarAvaliacao(avaliacao, email))
//   {
//     cout << texto6 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto7 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

// void CntrApresentacaoAvaliacao::descadastrarAvaliacao(Email email)
// {
//   // Mensagens a serem apresentadas na tela de cadastramento.
//   char texto1[] = "Descadastrar uma avalia��o: ";
//   char texto2[] = "C�digo da avalia��o : ";
//   char texto3[] = "Dado em formato incorreto. Digite algo.";
//   char texto4[] = "Sucesso no descadastramento. Digite algo.";
//   char texto5[] = "Falha no descadastramento. Digite algo.";

//   int campo;
//   char campo1[80];

//   Codigo codigo;

//   CLR_SCR;                             // Limpa janela.
//   cout << texto1 << endl;              // Imprime nome do campo.
//   cout << texto2;                      // Imprime nome do campo.
//   cin.getline(campo1, sizeof(campo1)); // L� valor do campo.

//   try
//   {
//     codigo.setCodigo(campo1);
//   }
//   catch (invalid_argument &exp)
//   {
//     cout << texto3 << endl; // Informa falha.

//     campo = getch() - 48; // Leitura de caracter digitado.

//     return;
//   }

//   if (cntrServicoExcursao->descadastrarAvaliacao(codigo, email) && campo1 != "")
//   {
//     cout << texto4 << endl; // Informa sucesso.

//     campo = getch() - 48;

//     return;
//   }

//   cout << texto5 << endl; // Informa falha.

//   campo = getch() - 48;

//   return;
// }

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
      {                         // Solicita autentica��o.
        bool apresentar = true; // Controle de la�o.
        while (apresentar)
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

bool CntrApresentacaoUsuario::descadastrar(Email email)
{
  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  char texto1[] = "Sucesso. Usuario descadastrado.";
  char texto2[] = "Falha no descadastramento.";
  clear();

  if (cntrServicoUsuario->descadastrarUsuario(email))
  {
    mvprintw(linha / 4, coluna / 4, "%s", texto1);
    noecho();
    getch();
    echo();

    return true;
  }

  mvprintw(linha / 4, coluna / 4, "%s", texto2);
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
  char texto5[] = "Sucesso na altera��o. Digite algo.";
  char texto6[] = "Falha na altera��o. Digite algo.";

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
  char texto2[] = "1 - Consultar excurs�es.";
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

    mvprintw(linha / 4, coluna / 4, "%s", "Codigo        : " + excursao.getCodigo().getCodigo());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", "Titulo        : " + excursao.getTitulo().getTitulo());
    if (excursao.getNota().getNota() != -1)
      mvprintw(linha / 4 + 4, coluna / 4, "%s", "Nota          : " + to_string(excursao.getNota().getNota()));
    else
      mvprintw(linha / 4 + 4, coluna / 4, "%s", "Nota          : Nao ha avaliacoes cadastradas para essa Excursao");
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "Cidade        : " + excursao.getCidade().getCidade());
    mvprintw(linha / 4 + 8, coluna / 4, "%s", "Duracao       : " + excursao.getDuracao().getDuracao());
    mvprintw(linha / 4 + 10, coluna / 4, "%s", "Endereco      : " + excursao.getEndereco().getEndereco());
    mvprintw(linha / 4 + 12, coluna / 4, "%s", "Email do Guia : " + excursao.getEmail().getEmail() + "\n");
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
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          :";
  char texto5b[] = "Duracao         :";
  char texto5c[] = "Descricao       :";
  char texto5d[] = "Endereco        :";
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
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto6); // Informa formato incorreto.
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
    mvprintw(linha / 4 + 12, coluna / 4, "%s", texto7); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 12, coluna / 4, "%s", texto8); // Informa falha.
  noecho();
  getch();
  echo();
  return;
}

void CntrApresentacaoExcursao::editarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Codigo da Excursao que voce deseja alterar?  :";
  char texto3[] = "Titulo          :";
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          :";
  char texto6[] = "Duracao         :";
  char texto7[] = "Descricao       :";
  char texto8[] = "Endereco        :";
  char texto9[] = "Dados em formato incorreto. Digite algo.";
  char texto10[] = "Sucesso na alteracao. Digite algo.";
  char texto11[] = "Falha na alteracao. Digite algo.";

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
  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto5);  // Imprime nome do campo.
  getstr(campo3);                                     // L� valor do campo.
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto6);  // Imprime nome do campo.
  getstr(campo4);                                     // L� valor do campo.
  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto7); // Imprime nome do campo.
  getstr(campo5);                                     // L� valor do campo.
  mvprintw(linha / 4 + 12, coluna / 4, "%s", texto8); // Imprime nome do campo.
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
    mvprintw(linha / 4 + 14, coluna / 4, "%s", texto9); // Informa formato incorreto.
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
    mvprintw(linha / 4 + 14, coluna / 4, "%s", texto10); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 14, coluna / 4, "%s", texto11); // Informa falha.
  noecho();
  getch();
  echo();
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

void CntrApresentacaoExcursao::listarExcursoes(Email email)
{
  int campo;
  list<Excursao> excursoes = cntrServicoExcursao->listarExcursoes();

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  clear();
  int i = 0;
  for (auto excursao = begin(excursoes); excursao != end(excursoes); ++excursao)
  {
    mvprintw(linha / 4, coluna / 4, "%s", "C�digo        : " + excursao->getCodigo().getCodigo());

    mvprintw(linha / 4 + 2, coluna / 4, "%s", "T�tulo        : " + excursao->getTitulo().getTitulo());
    if (excursao->getNota().getNota() != -1)
      mvprintw(linha / 4 + 4, coluna / 4, "%s", "Nota          : " + to_string(excursao->getNota().getNota()));
    else
      mvprintw(linha / 4 + 4, coluna / 4, "%s", "Nota          : Nao ha avaliacoes cadastradas para essa Excursao");
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "Cidade        : " + excursao->getCidade().getCidade());
    mvprintw(linha / 4 + 8, coluna / 4, "%s", "Dura��o       : " + excursao->getDuracao().getDuracao());
    mvprintw(linha / 4 + 10, coluna / 4, "%s", "Endere�o      : " + excursao->getEndereco().getEndereco());
    mvprintw(linha / 4 + 12, coluna / 4, "%s", "Email do Guia : " + excursao->getEmail().getEmail() + "\n");
    mvprintw(linha / 4 + 14, coluna / 4, "%s", "Pagina " + to_string(i) + " de " + to_string(excursoes.size()) + "   -----------------------------------------------------");
    getch();
    i++;
  }
  campo = getch() - 48;
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar sessoes.";
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

  try
  {
    clear();
    Sessao sessao = cntrServicoExcursao->recuperarSessao(codigo);

    mvprintw(linha / 4, coluna / 4, "%s", "Codigo         : " + sessao.getCodigo().getCodigo());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", "Data           : " + sessao.getData().getData());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", "Horario        : " + sessao.getHorario().getHorario());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "Idioma         : " + sessao.getIdioma().getIdioma());
    mvprintw(linha / 4 + 8, coluna / 4, "%s", "Codigo da Excursao : " + sessao.getCodigoExcursao().getCodigo() + "\n");
  }
  catch (...)
  {
    cout << texto5 << endl; // Informa falha.
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
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto7); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
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
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto8); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto9); // Informa falha.
  noecho();
  getch();
  echo();
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

  char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Data data;
  Horario horario;
  Idioma idioma;

  int linha, coluna; // Dados sobre tamanho da tela.

  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  // Apresenta tela de cadastramento.

  clear(); // Limpa janela.

  mvprintw(linha / 4, coluna / 4, "%s", texto1);     // Imprime nome do campo.
  mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2); // Imprime nome do campo.
  getstr(campo0);                                    // L� valor do campo.
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3); // Imprime nome do campo.
  getstr(campo1);                                    // L� valor do campo.
  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4); // Imprime nome do campo.
  getstr(campo3);                                    // L� valor do campo.
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5); // Imprime nome do campo.
  getstr(campo4);                                    // L� valor do campo.

  try
  {
    codigo.setCodigo(campo0);
    data.setData(campo1);
    horario.setHorario(campo3);
    idioma.setIdioma(campo4);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto8); // Informa formato incorreto.
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

  if (cntrServicoExcursao->editarSessao(sessao, email))
  {
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto9); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto10); // Informa falha.
  noecho();
  getch();
  echo();
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

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();
  int count = 0;

  while (!sessoes.empty())
  {
    Sessao sessao = sessoes.back();
    sessoes.pop_back();
    clear();

    mvprintw(linha / 4 + count, coluna / 4, "%s %s", texto1 + sessao.getCodigo().getCodigo());
    mvprintw(linha / 4 + count + 2, coluna / 4, "%s %s", texto2 + sessao.getData().getData());
    mvprintw(linha / 4 + count + 4, coluna / 4, "%s %s", texto3 + sessao.getHorario().getHorario());
    mvprintw(linha / 4 + count + 6, coluna / 4, "%s %s", texto4 + sessao.getIdioma().getIdioma());
    mvprintw(linha / 4 + count + 8, coluna / 4, "%s %s", texto4 + sessao.getCodigoExcursao().getCodigo());

    count += 1;
    getch();
  }

  noecho();

  echo();
  return;
}

void CntrApresentacaoSessao::listarSessoes(Email email)
{
  char texto1[] = "Codigo             : ";
  char texto2[] = "Data               : ";
  char texto3[] = "Horario            : ";
  char texto4[] = "Idioma             : ";
  char texto5[] = "Codigo da Excursao : ";

  int linha, coluna;               // Dados sobre tamanho da tela.
  getmaxyx(stdscr, linha, coluna); // Armazena quantidade de linhas e colunas.

  list<Sessao> sessoes = cntrServicoExcursao->listarSessoes();
  int count = 0;

  while (!sessoes.empty())
  {
    Sessao sessao = sessoes.back();
    sessoes.pop_back();
    clear();

    mvprintw(linha / 4, coluna / 4, "%s %s", texto1 + sessao.getCodigo().getCodigo());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2 + sessao.getData().getData());
    mvprintw(linha / 4 + 4, coluna / 4, "%s %s", texto3 + sessao.getHorario().getHorario());
    mvprintw(linha / 4 + 6, coluna / 4, "%s %s", texto4 + sessao.getIdioma().getIdioma());
    mvprintw(linha / 4 + 8, coluna / 4, "%s %s", texto4 + sessao.getCodigoExcursao().getCodigo());
    getch();
  }

  noecho();

  echo();
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
      campo = getch() - 48; // Leitura de caracter digitado.
    }
    Excursao excursao;
    excursao.setCodigo(codigo);

    try
    {
      int campo;
      list<Sessao> sessoes = cntrServicoExcursao->listarSessoesExcursao(excursao);
      int j = 0;
      for (auto sessao = begin(sessoes); sessao != end(sessoes); ++sessao)
      {
        clear();

        mvprintw(linha / 4, coluna / 4, "%s", "Codigo              : " + sessao->getCodigo().getCodigo());
        mvprintw(linha / 4 + 2, coluna / 4, "%s", "Data                : " + sessao->getData().getData());
        mvprintw(linha / 4 + 4, coluna / 4, "%s", "Horario             : " + sessao->getHorario().getHorario());
        mvprintw(linha / 4 + 6, coluna / 4, "%s", "Idiomar             : " + sessao->getIdioma().getIdioma());
        mvprintw(linha / 4 + 8, coluna / 4, "%s", "Codigo da Excursao  : " + sessao->getCodigoExcursao().getCodigo() + "\n");
        mvprintw(linha / 4 + 10, coluna / 4, "%s", " Pagina " + to_string(j) + " de " + to_string(sessoes.size()) + "-------------------------------------------------------");
        getch();
      }
      return;
    }
    catch (...)
    {
      cout << texto5 << endl; // Informa falha.
    }
    cout << "1 - Listar sessoes de outra excursao" << endl;
    cout << "2 - Retornar" << endl;
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
  char texto2[] = "1 - Consultar avalia��es.";
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
      listarAvaliacoes();
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

  char campo1[80], campo2[80], campo3[80];

  Nota nota;
  Descricao descricao;
  Codigo codigoExcursao;

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);

  clear();

  mvprintw(linha / 4, coluna / 4, "%s", texto1);
  mvprintw(linha / 4 + 4, coluna / 4, "%s", texto2);
  getstr(campo1);
  mvprintw(linha / 4 + 6, coluna / 4, "%s", texto3);
  getstr(campo2);
  mvprintw(linha / 4 + 8, coluna / 4, "%s", texto4);
  getstr(campo3);

  try
  {
    int icampo2 = stoi(campo1);
    nota.setNota(icampo2);
    descricao.setDescricao(campo2);
    codigoExcursao.setCodigo(campo3);
  }
  catch (invalid_argument &exp)
  {
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto5); // Informa formato incorreto.
    noecho();                                           // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
    echo();                                             // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Avaliacao avaliacao;

  avaliacao.setNota(nota);
  avaliacao.setDescricao(descricao);

  if (cntrServicoExcursao->cadastrarAvaliacao(avaliacao, email, codigoExcursao))
  {
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6); // Informa sucesso.
    noecho();
    getch();
    echo();
    return;
  }

  mvprintw(linha / 4 + 10, coluna / 4, "%s", texto7); // Informa falha.
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

void CntrApresentacaoAvaliacao::listarAvaliacoes()
{
  list<Avaliacao> avaliacoes = cntrServicoExcursao->listarAvaliacoes();

  int linha, coluna;

  getmaxyx(stdscr, linha, coluna);
  int i = 1;
  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    char texto1[] = "Codigo             : ";
    char texto2[] = "Nota               : ";
    char texto3[] = "Descricao          : ";
    char texto4[] = "Email do Avaliador : ";
    char texto5[] = "Codigo da Excursao : ";
    char texto6[] = "Pagina ";
    char texto7[] = " de ";
    char texto8[] = " -----------------------------------------------------";

    clear();
    mvprintw(linha / 4, coluna / 4, "%s %s", texto1, avaliacao->getCodigo().getCodigo().c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s %s", texto2, to_string(avaliacao->getNota().getNota()).c_str());
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
  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", "Codigo             : " + avaliacao->getCodigo().getCodigo());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", "Nota               : " + to_string(avaliacao->getNota().getNota()));
    mvprintw(linha / 4 + 4, coluna / 4, "%s", "Descricao          : " + avaliacao->getDescricao().getDescricao());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "Email do Avaliador : " + avaliacao->getEmail().getEmail());
    mvprintw(linha / 4 + 8, coluna / 4, "%s", "Codigo da Excursao : " + avaliacao->getCodigoExcursao().getCodigo() + "\n");
    mvprintw(linha / 4 + 10, coluna / 4, "%s", "Pagina " + to_string(i) + " de " + to_string(avaliacoes.size()) + "   -----------------------------------------------------");
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
  int i = 1;
  for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
  {
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", "Codigo             : " + avaliacao->getCodigo().getCodigo());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", "Nota               : " + to_string(avaliacao->getNota().getNota()));
    mvprintw(linha / 4 + 4, coluna / 4, "%s", "Descricao          : " + avaliacao->getDescricao().getDescricao());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "Email do Avaliador : " + avaliacao->getEmail().getEmail());
    mvprintw(linha / 4 + 8, coluna / 4, "%s", "Codigo da Excursao : " + avaliacao->getCodigoExcursao().getCodigo() + "\n");
    mvprintw(linha / 4 + 10, coluna / 4, "%s", "Pagina " + to_string(i) + " de " + to_string(avaliacoes.size()) + "   -----------------------------------------------------");
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
      for (auto avaliacao = begin(avaliacoes); avaliacao != end(avaliacoes); ++avaliacao)
      {
        clear();
        mvprintw(linha / 4, coluna / 4, "%s", "Codigo             : " + avaliacao->getCodigo().getCodigo());
        mvprintw(linha / 4 + 2, coluna / 4, "%s", "Nota               : " + to_string(avaliacao->getNota().getNota()));
        mvprintw(linha / 4 + 4, coluna / 4, "%s", "Descricao          : " + avaliacao->getDescricao().getDescricao());
        mvprintw(linha / 4 + 6, coluna / 4, "%s", "Email do Avaliador : " + avaliacao->getEmail().getEmail());
        mvprintw(linha / 4 + 8, coluna / 4, "%s", "Codigo da Excursao : " + avaliacao->getCodigoExcursao().getCodigo() + "\n");
        mvprintw(linha / 4 + 10, coluna / 4, "%s", "Pagina " + to_string(i) + " de " + to_string(avaliacoes.size()) + "   -----------------------------------------------------");
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
