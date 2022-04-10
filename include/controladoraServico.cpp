#include "controladoraServico.h"
#include <iostream>
#include <iterator>
#include <algorithm>
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
  if (checarUsuario(usuario))
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
  return false;
}

bool CntrServicoUsuario::checarUsuario(Usuario usuario)
{
  list<string> usuarios;
  ComandoChecarUsuario comandoChecarUsuarios;
  comandoChecarUsuarios.executar();
  usuarios = comandoChecarUsuarios.getResultado();

  return !(find(begin(usuarios), end(usuarios), usuario.getEmail().getEmail()) == end(usuarios));
}

//--------------------------------------------------------------------------------------------

bool CntrServicoUsuario::descadastrarUsuario(Email email)
{
  Usuario usuario;
  usuario.setEmail(email);
  if (checarUsuario(usuario))
  {
    ComandoDescadastrarUsuario deleteUser(email);
    try
    {
      deleteUser.executar();
      return true;
    }
    catch (EErroPersistencia)
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

//--------------------------------------------------------------------------------------
//|                                     Excursão                                       |
//--------------------------------------------------------------------------------------
bool CntrServicoExcursao::checarExcursao(Excursao excursao, Email email)
{
  list<string> excursoes;
  ComandoChecarExcursao comandoChecarExcursoes(email);
  comandoChecarExcursoes.executar();
  excursoes = comandoChecarExcursoes.getResultado();
  list<string> iexcursoes;
  string str;
  Codigo codigo;
  for (auto excursao = excursoes.begin(); excursao != excursoes.end(); excursao++)
  {
    str = codigo.getCodigoDigitoVerificador(stoi(*excursao));
    iexcursoes.push_back(str);
  }
  return find(begin(iexcursoes), end(iexcursoes), excursao.getCodigo().getCodigo()) != end(iexcursoes);
}

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

  if (checarExcursao(excursao, email))
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
  return false;
}

bool CntrServicoExcursao::descadastrarExcursao(Codigo codigo, Email email)
{
  Excursao excursao;
  excursao.setCodigo(codigo);
  if (checarExcursao(excursao, email))
  {

    Excursao excursao;
    excursao.setCodigo(codigo);
    if (checarExcursao(excursao, email))
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
  }
  return false;
}

Excursao CntrServicoExcursao::recuperarExcursao(Codigo codigo)
{
  Excursao excursao;
  ComandoRecuperarExcursao recuperarExcursao(codigo);

  recuperarExcursao.executar();
  excursao = recuperarExcursao.getResultado();

  return excursao;
}

list<Excursao> CntrServicoExcursao::listarExcursoes()
{
  ComandoListarExcursoes getExcursions;
  try
  {
    getExcursions.executar();
    return getExcursions.getResultado();
  }
  catch (EErroPersistencia)
  {
    throw EErroPersistencia("Erro na execução do comando!");
  }
}
/*
//--------------------------------------------------------------------------------------
//|                                    Sessão                                          |
//--------------------------------------------------------------------------------------
*/

bool CntrServicoExcursao::checarSessao(Sessao sessao, Email email)
{
  ComandoChecarSessao comandoChecarSessoes(sessao.getCodigo(), email);

  comandoChecarSessoes.executar();

  return comandoChecarSessoes.getResultado();
}

bool CntrServicoExcursao::cadastrarSessao(Sessao sessao, Email email)
{
  NextIdSessao nextIdSessao;
  nextIdSessao.executar();
  int result;
  result = nextIdSessao.getResultado();
  Codigo codigoVerificador;

  ComandoCadastrarSessao registerSession(sessao, email, sessao.getCodigoExcursao(), codigoVerificador.getDigitoVerificador(result));
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
  Sessao sessao;
  sessao.setCodigo(codigo);
  if (checarSessao(sessao, email))
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
  return false;
}
//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::editarSessao(Sessao sessao, Email email)
{
  if (checarSessao(sessao, email))
  {
    ComandoEditarSessao editSession(sessao, email);
    try
    {
      editSession.executar();
      return true;
    }
    catch (EErroPersistencia)
    {
      return false;
    }
  }
  return false;
}

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
    return getSessions.getResultado();
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
  string icodigo = codigo.getCodigo();
  icodigo.pop_back();

  NextIdAvaliacao nextIdAvaliacao;
  nextIdAvaliacao.executar();
  int result;
  result = nextIdAvaliacao.getResultado();
  float nota;

  try
  {

    ComandoCadastrarAvaliacao registerAvaliacao(avaliacao, email, codigo, codigo.getDigitoVerificador(result));
    registerAvaliacao.executar();
    GetNotasMediaAvaliacao getnotas(stoi(icodigo));
    getnotas.executar();
    nota = getnotas.getResultado();
    ComandoAtualizarNotaExcursao updatingExcursion(nota, email, codigo);
    updatingExcursion.executar();

    return true;
  }
  catch (EErroPersistencia)
  {
    return false;
  }
}

//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::descadastrarAvaliacao(Codigo codigo, Email email)
{
  Avaliacao avaliacao;
  avaliacao.setCodigo(codigo);
  if (checarAvaliacao(avaliacao, email))
  {
    ComandoDescadastrarAvaliacao deleteAvaliation(codigo, email);

    try
    {
      ComandoRecuperarAvaliacao recuperarAvaliacao(avaliacao.getCodigo().getCodigo());
      recuperarAvaliacao.executar();
      avaliacao = recuperarAvaliacao.getResultado();
      string icodigo = avaliacao.getCodigoExcursao().getCodigo();
      icodigo.pop_back();

      deleteAvaliation.executar();
      avaliacao.setCodigoExcursao(avaliacao.getCodigoExcursao());
      GetNotasMediaAvaliacao getnotas(stoi(icodigo));
      getnotas.executar();
      float nota = getnotas.getResultado();
      ComandoAtualizarNotaExcursao updatingExcursion(nota, email, avaliacao.getCodigoExcursao());
      updatingExcursion.executar();

      return true;
    }
    catch (EErroPersistencia)
    {
      return false;
    }
  }
  return false;
}

//--------------------------------------------------------------------------------------------

bool CntrServicoExcursao::editarAvaliacao(Avaliacao avaliacao, Email email)
{
  Avaliacao avaliacaoAtual;

  if (checarAvaliacao(avaliacao, email))
  {
    ComandoEditarAvaliacao editAvaliation(avaliacao, email);
    try
    {
      editAvaliation.executar();

      ComandoRecuperarAvaliacao recuperarAvaliacao(avaliacao.getCodigo().getCodigo());

      recuperarAvaliacao.executar();
      avaliacaoAtual = recuperarAvaliacao.getResultado();
      string icodigo = avaliacaoAtual.getCodigoExcursao().getCodigo();
      icodigo.pop_back();

      avaliacao.setCodigoExcursao(avaliacaoAtual.getCodigoExcursao());
      GetNotasMediaAvaliacao getnotas(stoi(icodigo));
      getnotas.executar();
      float nota = getnotas.getResultado();
      ComandoAtualizarNotaExcursao updatingExcursion(nota, email, avaliacao.getCodigoExcursao());
      updatingExcursion.executar();

      return true;
    }
    catch (EErroPersistencia)
    {
      return false;
    }
  }
  return false;
}

bool CntrServicoExcursao::checarAvaliacao(Avaliacao avaliacao, Email email)
{
  list<string> avaliacoes;
  ComandoChecarAvaliacao comandoChecarAvaliacoes(email);

  comandoChecarAvaliacoes.executar();
  avaliacoes = comandoChecarAvaliacoes.getResultado();
  list<string> iavaliacoes;
  string str;
  Codigo codigo;
  for (auto avaliacao = avaliacoes.begin(); avaliacao != avaliacoes.end(); avaliacao++)
  {
    str = codigo.getCodigoDigitoVerificador(stoi(*avaliacao));
    iavaliacoes.push_back(str);
  }
  return find(begin(iavaliacoes), end(iavaliacoes), avaliacao.getCodigo().getCodigo()) != end(iavaliacoes);
}

Avaliacao CntrServicoExcursao::recuperarAvaliacao(Codigo codigo)
{
  Avaliacao avaliacao;
  ComandoRecuperarAvaliacao recuperarAvaliacao(codigo);

  recuperarAvaliacao.executar();
  avaliacao = recuperarAvaliacao.getResultado();

  return avaliacao;
}

list<Avaliacao> CntrServicoExcursao::listarAvaliacoes()
{
  ComandoListarAvaliacoes getExcursions;
  try
  {
    getExcursions.executar();
    return getExcursions.getResultado();
  }
  catch (EErroPersistencia)
  {
    throw EErroPersistencia("Erro na execução do comando!");
  }
}