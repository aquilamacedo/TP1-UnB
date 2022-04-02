#include "controladoraServico.h"
#include <iostream>

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

int CntrServicoExcursao::getNextId()
{
  NextIdExcursao nextIdExcursao;
  try
  {
    nextIdExcursao.executar();
    int result;
    result = nextIdExcursao.getResultado();
    return result;
  }
  catch (EErroPersistencia)
  {
  }
}

bool CntrServicoExcursao::cadastrarExcursao(Excursao excursao)
{

  ComandoCadastrarExcursao registerExcursion(excursao);
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

bool CntrServicoExcursao::descadastrarExcursao(Codigo codigo)
{
  ComandoDescadastrarExcursao deregisterExcursion(codigo);

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
/*
//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::descadastrarExcursao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->excluirExcursao(codigo); // Retorna um bool
}
*/
//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::editarExcursao(Excursao excursao)
{
  // Armazena os dados em servidor ou lista
  ComandoEditarExcursao editingExcursion(excursao);
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

bool CntrServicoExcursao::cadastrarSessao(Sessao avaliacao)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->cadastrarSessao(avaliacao); // Retorna um bool
}

//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::descadastrarSessao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->excluirSessao(codigo); // Retorna um bool
}

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

bool CntrServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->cadastrarAvaliacao(avaliacao); // Retorna um bool
}

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
