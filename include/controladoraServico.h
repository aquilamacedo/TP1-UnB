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
private:
    bool checarUsuario(Usuario);

public:
    // abstract services methods of Users
    bool cadastrarUsuario(Usuario);
    bool editarUsuario(Usuario);
    bool descadastrarUsuario(Email);
    Usuario recuperar(Email);
};

class CntrServicoExcursao : public IServicoExcursao
{
private:
    bool checarAvaliacao(Avaliacao, Email);
    bool checarExcursao(Excursao, Email);
    bool checarSessao(Sessao, Email);

public:
    // abstract service methods of Excursion
    int getNextId();
    bool cadastrarExcursao(Excursao, Email);
    bool descadastrarExcursao(Codigo, Email);
    bool editarExcursao(Excursao, Email);
    Excursao recuperarExcursao(Codigo);
    list<Excursao> listarExcursoes();

    // abstract service methods of Avaliation
    list<int> getNotasAvaliacao();
    bool cadastrarAvaliacao(Avaliacao, Email, Codigo);
    bool descadastrarAvaliacao(Codigo, Email);
    bool editarAvaliacao(Avaliacao, Email);
    Avaliacao recuperarAvaliacao(Codigo);
    list<Avaliacao> listarAvaliacoes();
    list<Avaliacao> listarAvaliacoesExcursao(Excursao);
    list<Avaliacao> listarAvaliacoesUsuario(Usuario);

    // abstract service methods of Session
    bool cadastrarSessao(Sessao, Email);
    bool descadastrarSessao(Codigo, Email);
    bool editarSessao(Sessao, Email);
    Sessao recuperarSessao(Codigo);
    list<Sessao> listarSessoes();
    list<Sessao> listarSessoesExcursao(Excursao);
};

#endif
