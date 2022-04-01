#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declara��es de classes stub.

class StubServicoAutenticacao : public IServicoAutenticacao
{
private:
    static const string INVALIDO;

public:
    bool autenticar(Email, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoUsuario : public IServicoUsuario
{
private:
    static const string INVALIDO;

public:
    bool cadastrarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------

class StubServicoExcursao : public IServicoExcursao
{
private:
    static const string INVALIDO;

public:
    bool cadastrarExcursao(Excursao);
    Excursao recuperarExcursao(Codigo);
    bool descadastrarExcursao(Codigo);
    bool editarExcursao(Excursao);
    // list<Excursao> listarExcursoes();

    bool cadastrarAvaliacao(Avaliacao);
    bool descadastrarAvaliacao(Codigo);
    bool editarAvaliacao(Avaliacao);
    Avaliacao recuperarAvaliacao(Codigo);
    // list<Avaliacao> listarAvaliacoes();
    // list<Avaliacao> listarAvaliacoes(Excursao);
    // list<Avaliacao> listarAvaliacoes(Usuario);

    bool cadastrarSessao(Sessao);
    bool descadastrarSessao(Codigo);
    bool editarSessao(Sessao);
    Sessao recuperarSessao(Codigo);
    // list<Sessao> listarSessoes();
    // list<Sessao> listarSessoes(Excursao);

    //bool cadastrarProdutoInvestimento(Produto);
    // bool descadastrarProdutoInvestimento(Codigo);
    // bool realizarAplicacao(Aplicacao);
    // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

//--------------------------------------------------------------------------------------------

// class StubServicoSessao : public IServicoSessao
// {
// private:
//     static const string INVALIDO;

// public:
//     bool cadastrarSessao(Sessao);
//     bool consultarSessao(Sessao *);
//     bool descadastrarSessao(Codigo);
//     bool editarSessao(Codigo);
//     //bool cadastrarProdutoInvestimento(Produto);
//     // bool descadastrarProdutoInvestimento(Codigo);
//     // bool realizarAplicacao(Aplicacao);
//     // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
// };

// //--------------------------------------------------------------------------------------------

// class StubServicoSala : public IServicoSala
// {
// private:
//     static const string INVALIDO;

// public:
//     bool cadastrarSala(Sala);
//     bool consultarSala(Sala *);
//     bool descadastrarSala(Codigo);
//     bool editarSala(Codigo);
//     //bool cadastrarProdutoInvestimento(Produto);
//     // bool descadastrarProdutoInvestimento(Codigo);
//     // bool realizarAplicacao(Aplicacao);
//     // bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
// };

//--------------------------------------------------------------------------------------------
#endif // STUBS_H_INCLUDED
