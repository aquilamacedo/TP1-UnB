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

bool CntrServicoUsuario::descadastrarUsuario(Email email) {
  // Armazena os dados em servidor ou lista
  ComandoDescadastrarUsuario deleteUser(email);

  try {
    deleteUser.executar();
    return true;
  }

  catch (EErroPersistencia)
  {
    return false;
  }
}

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
  ComandoDescadastrarSessao deleteSession(codigo, email);
  try
  {
    deleteSession.executar();
    return true;
  }
  catch (EErroPersistencia)
  {
    return false;
  }
}
//--------------------------------------------------------------------------------------------

/*
bool CntrServicoExcursao::editarSessao(Sessao sessao, Email email) {
  ComandoEditarSessao editSession(sessao, email);
  try {
    editSession.executar();
    return true;
  }
  catch(EErroPersistencia) {
    return false;
  }
  
}
*/

Sessao CntrServicoExcursao::recuperarSessao(Codigo codigo)
{
  ComandoRecuperarSessao getSession(codigo);
  try
  {
    getSession.executar();
    return getSession.getResultado();
  }
  catch (EErroPersistencia)
  {
    throw EErroPersistencia("Erro na execução do comando!");
  }
}

list<Sessao> CntrServicoExcursao::listarSessoes()
{
  ComandoListarSessoes getSessions;
  try
  {
    getSessions.executar();
    list<Sessao> sessoes = getSessions.getResultado();
    return sessoes;
  }
  catch (EErroPersistencia)
  {
    throw EErroPersistencia("Erro na execução do comando!");
  }
}

list<Sessao> CntrServicoExcursao::listarSessoes(Excursao excursao)
{
  ComandoListarSessoes getSessions(excursao);
  try
  {
    getSessions.executar();
    return getSessions.getResultado();
  }
  catch (EErroPersistencia)
  {
    throw EErroPersistencia("Erro na execução do comando!");
  }
}

//--------------------------------------------------------------------------------------
//|                                 Avaliação                                          |
//--------------------------------------------------------------------------------------

bool CntrServicoExcursao::cadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo)
{
  GetNotasAvaliacao getnotas;

  ComandoCadastrarAvaliacao registerAvaliacao(avaliacao, email, codigo);
  try
  {

    getnotas.executar();
    list<string> notas = getnotas.getResultado();
    int soma = 0;
    int contador = 0;
    for (auto it = begin(notas); it != end(notas); ++it)
    {
      // soma += *it;
      // contador++;
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

/*
bool CntrServicoExcursao::descadastrarAvaliacao(Codigo codigo){
  ComandoDescadastrarAvaliacao deleteAvaliation(codigo);
  try {
    deleteAvaliation.executar();
    return true;
} catch(EErroPersistencia) {
    return false;
}
}


//--------------------------------------------------------------------------------------------
/*
bool CntrServicoExcursao::editarAvaliacao(Avaliacao avaliacao, Email email) {
  ComandoEditarAvaliacao  editAvaliation(avaliacao, email);
  try {
    editAvaliation.executar();
    return true
  }
  catch(EErroPersistencia) {
    return false;
  }

}


Avaliacao CntrServicoExcursao::recuperarAvaliacao(Codigo codigo)
{ // Armazena os dados em servidor ou lista
  ContainerExcursao *container;

  container = ContainerExcursao::getInstancia();

  return container->recuperarAvaliacao(codigo); // Retorna um bool

*/
