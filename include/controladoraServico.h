#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "database.h"

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
    bool editarUsuario(Usuario);
    //bool descadastrarUsuario(Email);
    //Usuario recuperarUsuario(Email);
};

class CntrServicoExcursao : public IServicoExcursao
{
public:
    // abstract service methods of Excursion
    int getNextId();
    bool cadastrarExcursao(Excursao, Email);
    bool descadastrarExcursao(Codigo, Email);
    bool editarExcursao(Excursao, Email);
    // Excursao recuperarExcursao(Codigo);
    // list<Excursao> listarExcursoes();

    // // abstract service methods of Avaliation
    // bool cadastrarAvaliacao(Avaliacao);
    // bool descadastrarAvaliacao(Codigo);
    // bool editarAvaliacao(Avaliacao);
    // Avaliacao recuperarAvaliacao(Codigo);
    // list<Avaliacao> listarAvaliacoes();
    // list<Avaliacao> listarAvaliacoes(Excursao);
    // list<Avaliacao> listarAvaliacoes(Usuario);

    // // abstract service methods of Session
    // bool cadastrarSessao(Sessao);
    // bool descadastrarSessao(Codigo);
    // bool editarSessao(Sessao);
    // Sessao recuperarSessao(Codigo);
    // list<Sessao> listarSessoes();
    // list<Sessao> listarSessoes(Excursao);
};

#endif
