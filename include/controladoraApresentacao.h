#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <iostream>
#include <string.h>

#include "ncurses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");
// -------------------------------------------
// Declaration of controllers of control
// -------------------------------------------

class CntrApresentacaoControle
{
private:
    Email email;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoUsuario *cntrApresentacaoUsuario;
    IApresentacaoExcursao *cntrApresentacaoExcursao;
    IApresentacaoAvaliacao *cntrApresentacaoAvaliacao;
    IApresentacaoSessao *cntrApresentacaoSessao;

public:
    void executar();
    void executar(Email);
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *);
    void setCntrApresentacaoUsuario(IApresentacaoUsuario *);
    void setCntrApresentacaoExcursao(IApresentacaoExcursao *);
    void setCntrApresentacaoAvaliacao(IApresentacaoAvaliacao *);
    void setCntrApresentacaoSessao(IApresentacaoSessao *);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntrApresentacaoAutenticacao)
{
    this->cntrApresentacaoAutenticacao = cntrApresentacaoAutenticacao;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario *cntrApresentacaoUsuario)
{
    this->cntrApresentacaoUsuario = cntrApresentacaoUsuario;
}

inline void CntrApresentacaoControle::setCntrApresentacaoExcursao(IApresentacaoExcursao *cntrApresentacaoExcursao)
{
    this->cntrApresentacaoExcursao = cntrApresentacaoExcursao;
}

inline void CntrApresentacaoControle::setCntrApresentacaoAvaliacao(IApresentacaoAvaliacao *cntrApresentacaoAvaliacao)
{
    this->cntrApresentacaoAvaliacao = cntrApresentacaoAvaliacao;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSessao(IApresentacaoSessao *cntrApresentacaoSessao)
{
    this->cntrApresentacaoSessao = cntrApresentacaoSessao;
}

// -------------------------------------------
// Declaration of controller of authentication
// -------------------------------------------

class CntrApresentacaoAutenticacao : public IApresentacaoAutenticacao
{
private:
    IServicoAutenticacao *cntr;

public:
    bool autenticar(Email *);
    void setCntrServicoAutenticacao(IServicoAutenticacao *);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr)
{
    this->cntr = cntr;
}

// -------------------------------------------
// Declaration of controller of User
// -------------------------------------------

class CntrApresentacaoUsuario : public IApresentacaoUsuario
{
private:
    IServicoUsuario *cntrServicoUsuario;
    void consultarDadosUsuario();
    void editarUsuario();

public:
    void executar(Email);
    void cadastrar();
    void setCntrServicoUsuario(IServicoUsuario *);
};

inline void CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario *cntrServicoUsuario)
{
    this->cntrServicoUsuario = cntrServicoUsuario;
}

// -------------------------------------------
// Declaration of controller of Excursion
// -------------------------------------------

class CntrApresentacaoExcursao : public IApresentacaoExcursao
{
private:
    IServicoExcursao *cntrServicoExcursao;
    void consultarExcursao(Email);
    void cadastrarExcursao(Email);
    void editarExcursao(Email);
    void descadastrarExcursao(Email);
    void listarExcursoes(Email);

public:
    void executar();
    void executar(Email);
    void setCntrServicoExcursao(IServicoExcursao *);
};

inline void CntrApresentacaoExcursao::setCntrServicoExcursao(IServicoExcursao *cntrServicoExcursao)
{
    this->cntrServicoExcursao = cntrServicoExcursao;
}

// -------------------------------------------
// Declaration of controller of Session
// -------------------------------------------

class CntrApresentacaoSessao : public IApresentacaoSessao
{
private:
    IServicoExcursao *cntrServicoExcursao;
    void consultarSessao(Email);
    void cadastrarSessao(Email);
    void editarSessao(Email);
    void descadastrarSessao(Email);
    void listarSessoes(Email);

public:
    void executar();
    void executar(Email);
    void setCntrServicoExcursao(IServicoExcursao *);
};

inline void CntrApresentacaoSessao::setCntrServicoExcursao(IServicoExcursao *cntrServicoExcursao)
{
    this->cntrServicoExcursao = cntrServicoExcursao;
}

// -------------------------------------------
// Declaration of controller of Avaliation
// -------------------------------------------

class CntrApresentacaoAvaliacao : public IApresentacaoAvaliacao
{
private:
    IServicoExcursao *cntrServicoExcursao;
    void consultarAvaliacao(Email);
    void cadastrarAvaliacao(Email);
    void editarAvaliacao(Email);
    void descadastrarAvaliacao(Email);
    void listarAvaliacoes(Email);

public:
    void executar();
    void executar(Email);
    void setCntrServicoExcursao(IServicoExcursao *);
};

inline void CntrApresentacaoAvaliacao::setCntrServicoExcursao(IServicoExcursao *cntrServicoExcursao)
{
    this->cntrServicoExcursao = cntrServicoExcursao;
}

#endif
