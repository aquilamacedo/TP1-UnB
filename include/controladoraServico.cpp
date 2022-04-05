#include "controladoraServico.h"
#include <iostream>
#include <iterator>

using namespace std;

//--------------------------------------------------------------------------------------
//|                                       Usuario                                      |
//--------------------------------------------------------------------------------------

bool CntrServicoAutenticacao::autenticar(Email email, Senha senha)
{
  // Armazena os dados em servidor ou lista

  ComandoSenha passwd(email);

  try
  {
    passwd.executar();

    string resultado;
    resultado = passwd.getResultado();

    if (resultado == senha.getSenha())
    {
      return true;
    }
    return false;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

bool CntrServicoUsuario::cadastrarUsuario(Usuario usuario)
{
  ComandoCadastrarUsuario registerUser(usuario);

  try
  {
    registerUser.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

bool CntrServicoUsuario::editarUsuario(Usuario usuario)
{
  ComandoEditarUsuario editingUser(usuario);

  try
  {
    editingUser.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

/*

bool CntrServicoUsuario::cadastrarUsuario(Usuario usuario)
{ // Armazena os dados em servidor ou lista
  ContainerUsuario *container;

  container = ContainerUsuario::getInstancia();

  return container->cadastrarUsuario(usuario); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoUsuario::descadastrarUsuario(Email email)
{ // Armazena os dados em servidor ou lista
  ContainerUsuario *container;

  container = ContainerUsuario::getInstancia();

  return container->excluirUsuario(email); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoUsuario::editar(Usuario usuario)
{ // Armazena os dados em servidor ou lista
  ContainerUsuario *container;

  container = ContainerUsuario::getInstancia();

  return container->editarUsuario(usuario); // Retorna um bool
}
*/
//--------------------------------------------------------------------------------------
//|                                     Excursão                                       |
//--------------------------------------------------------------------------------------

bool CntrServicoExcursao::cadastrarExcursao(Excursao excursao, Email email)
{

  NextIdExcursao nextIdExcursao;
  nextIdExcursao.executar();
  int result;
  result = nextIdExcursao.getResultado();
  Codigo codigo;

  ComandoCadastrarExcursao registerExcursion(excursao, email, codigo.getDigitoVerificador(result));
  try
  {
    registerExcursion.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

bool CntrServicoExcursao::editarExcursao(Excursao excursao, Email email)
{

  ComandoEditarExcursao editingExcursion(excursao, email);
  try
  {
    editingExcursion.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

bool CntrServicoExcursao::descadastrarExcursao(Codigo codigo, Email email)
{
  ComandoDescadastrarExcursao deregisterExcursion(codigo, email);

  try
  {
    deregisterExcursion.executar();
    return true;
  }
  catch (EErroPersistencia)
  {
    return false;
  }
}

// bool CntrServicoExcursao::editarExcursao(Excursao excursao, Email email)
// {
//   // Armazena os dados em servidor ou lista
//   ComandoEditarExcursao editingExcursion(excursao, email);
//   try
//   {
//     editingExcursion.executar();
//     return true;
//   }

//   catch (EErroPersistencia)
//   {
//     return false;
//   }
// }
/*
Excursao CntrServicoExcursao::recuperarExcursao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->recuperarExcursao(codigo); // Retorna um bool
}

//--------------------------------------------------------------------------------------
//|                                    Sessão                                          |
//--------------------------------------------------------------------------------------
*/
bool CntrServicoExcursao::cadastrarSessao(Sessao sessao, Email email, Codigo codigo)
{
  NextIdSessao nextIdSessao;
  nextIdSessao.executar();
  int result;
  result = nextIdSessao.getResultado();
  Codigo codigoVerificador;

  ComandoCadastrarSessao registerSession(sessao, email, codigo, codigoVerificador.getDigitoVerificador(result));
  try
  {
    registerSession.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::descadastrarSessao(Codigo codigo, Email email)
{
  ComandoDescadastrarSessao deregisterSession(codigo, email);

  try
  {
    deregisterSession.executar();
    return true;
  }
  catch (EErroPersistencia)
  {
    return false;
  }
}
/*
//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::editarSessao(Sessao avaliacao)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  // container = ContainerExcursao::getInstancia();

  return container->editarSessao(avaliacao); // Retorna um bool
}

Sessao CntrServicoExcursao::recuperarSessao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->recuperarSessao(codigo); // Retorna a sessão
}

//--------------------------------------------------------------------------------------
//|                                 Avaliação                                          |
//--------------------------------------------------------------------------------------
*/

bool CntrServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo)
{
  GetNotasAvaliacao getnotas;

  ComandoCadastrarAvaliacao registerAvaliacao(avaliacao, email, codigo);
  try
  {

    getnotas.executar();
    list<int> notas = getnotas.getResultado();
    int soma = 0;
    int contador = 0;
    for (auto it = begin(notas); it != end(notas); ++it)
    {
      soma += *it;
      contador++;
    }

    registerAvaliacao.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}
/*
//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::descadastrarAvaliacao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->excluirAvaliacao(codigo); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::editarAvaliacao(Avaliacao avaliacao)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  // container = ContainerExcursao::getInstancia();

  return container->editarAvaliacao(avaliacao); // Retorna um bool
}

Avaliacao CntrServicoExcursao::recuperarAvaliacao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->recuperarAvaliacao(codigo); // Retorna um bool

*/
