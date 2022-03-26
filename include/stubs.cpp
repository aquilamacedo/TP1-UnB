// #include "stubs.h"

// //--------------------------------------------------------------------------------------------
// // Valores usados como gatilhos de erros.

// const string StubServicoAutenticacao::INVALIDO = "12344";
// const string StubServicoUsuario::INVALIDO = "12344";
// const string StubServicoExcursao::INVALIDO = "12345";

// //--------------------------------------------------------------------------------------------
// // Implementa��es dos m�todos de classes stub.

// bool StubServicoAutenticacao::autenticar(Email email, Senha senha)
// {
//   if (email.getEmail().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// bool StubServicoUsuario::cadastrarUsuario(Usuario usuario)
// {
//   if (usuario.getEmail().getEmail().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// //############################################################################################

// bool StubServicoExcursao::cadastrarExcursao(Excursao excursao)
// {
//   if (excursao.getCodigo().getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// Excursao StubServicoExcursao::recuperarExcursao(Codigo codigo)
// {
//   if (codigo.getCodigo().compare(INVALIDO) == 0)
//   {
//     Excursao excursao;
//     return excursao;
//   }
// }

// bool StubServicoExcursao::descadastrarExcursao(Codigo codigo)
// {
//   if (codigo.getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// bool StubServicoExcursao::editarExcursao(Excursao excursao)
// {
//   if (excursao.getCodigo().getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }
// //############################################################################################

// bool StubServicoExcursao::cadastrarSessao(Sessao sessao)
// {
//   if (sessao.getCodigo().getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// Sessao StubServicoExcursao::recuperarSessao(Codigo codigo)
// {
//   if (codigo.getCodigo().compare(INVALIDO) == 0)
//   {
//     Sessao sessao;
//     return sessao;
//   }
// }

// bool StubServicoExcursao::descadastrarSessao(Codigo codigo)
// {
//   if (codigo.getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// bool StubServicoExcursao::editarSessao(Sessao sessao)
// {
//   if (sessao.getCodigo().getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }
// //############################################################################################

// bool StubServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao)
// {
//   if (avaliacao.getCodigo().getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// Avaliacao StubServicoExcursao::recuperarAvaliacao(Codigo codigo)
// {
//   if (codigo.getCodigo().compare(INVALIDO) == 0)
//   {
//     Avaliacao excursao;
//     return excursao;
//   }
// }

// bool StubServicoExcursao::descadastrarAvaliacao(Codigo codigo)
// {
//   if (codigo.getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }

// bool StubServicoExcursao::editarAvaliacao(Avaliacao avaliacao)
// {
//   if (avaliacao.getCodigo().getCodigo().compare(INVALIDO) == 0)
//     return false;
//   return true;
// }
