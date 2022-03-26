#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "conteiner.h"

class CntrServicoAutenticacao : public IServicoAutenticacao
{
public:
    // abstract service method of autentication
    bool autenticar(Email, Senha);
};

class CntrServicoUsuario : public IServicoUsuario
{
public:
    // abstract services methods of Users
    bool cadastrarUsuario(Usuario);
    bool descadastrarUsuario(Email);
    bool editar(Usuario);
    Usuario recuperarUsuario(Email);
};

class CntrServicoExcursao : public IServicoExcursao
{
public:
    // abstract service methods of Excursion
    bool cadastrarExcursao(Excursao);
    bool descadastrarExcursao(Codigo);
    bool editarExcursao(Excursao);
    Excursao recuperarExcursao(Codigo);
    // list<Excursao> listarExcursoes();

    // abstract service methods of Avaliation
    bool cadastrarAvaliacao(Avaliacao);
    bool descadastrarAvaliacao(Codigo);
    bool editarAvaliacao(Avaliacao);
    Avaliacao recuperarAvaliacao(Codigo);
    // list<Avaliacao> listarAvaliacoes();
    // list<Avaliacao> listarAvaliacoes(Excursao);
    // list<Avaliacao> listarAvaliacoes(Usuario);

    // abstract service methods of Session
    bool cadastrarSessao(Sessao);
    bool descadastrarSessao(Codigo);
    bool editarSessao(Sessao);
    Sessao recuperarSessao(Codigo);
    // list<Sessao> listarSessoes();
    // list<Sessao> listarSessoes(Excursao);
};

#endif