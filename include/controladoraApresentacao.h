#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

// -------------------------------------------
// Declaration of controllers of control
// -------------------------------------------

class CntrApresentacaoControle{
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
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoUsuario(IApresentacaoUsuario*);
        void setCntrApresentacaoExcursao(IApresentacaoExcursao*);
        void setCntrApresentacaoAvaliacao(IApresentacaoAvaliacao*);
        void setCntrApresentacaoSessao(IApresentacaoSessao*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntrApresentacaoAutenticacao){
    this->cntrApresentacaoAutenticacao = cntrApresentacaoAutenticacao;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario *cntrApresentacaoUsuario){
            this->cntrApresentacaoUsuario = cntrApresentacaoUsuario;
}

inline void CntrApresentacaoControle::setCntrApresentacaoExcursao(IApresentacaoExcursao *cntrApresentacaoExcursao){
    this->cntrApresentacaoExcursao = cntrApresentacaoExcursao;
}

inline void CntrApresentacaoControle::setCntrApresentacaoAvaliacao(IApresentacaoAvaliacao *cntrApresentacaoAvaliacao){
    this->cntrApresentacaoAvaliacao = cntrApresentacaoAvaliacao;
}

inline void CntrApresentacaoControle::setCntrApresentacaoSessao(IApresentacaoSessao *cntrApresentacaoSessao){
    this->cntrApresentacaoSessao = cntrApresentacaoSessao;
}

// -------------------------------------------
// Declaration of controller of authentication
// -------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        bool autenticar(Email*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

// -------------------------------------------
// Declaration of controller of User
// -------------------------------------------

class CntrApresentacaoUsuario:public IApresentacaoUsuario{
    private:
        IServicoUsuario *cntrServicoUsuario;
    public:
        void executar(Email);
        void executar();
        void setCntrServicoUsuario(IServicoUsuario*);
};

inline void CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario *cntrServicoUsuario){
    this->cntrServicoUsuario = cntrServicoUsuario;
}

// -------------------------------------------
// Declaration of controller of Excursion
// -------------------------------------------

class CntrApresentacaoExcursao:public IApresentacaoExcursao{
    private:
        IServicoExcursao *cntrServicoExcursao;
    public:
        void executar();
        void executar(Email);
        void setCntrServicoExcursao(IServicoExcursao*);
};

inline void CntrApresentacaoExcursao::setCntrServicoExcursao(IServicoExcursao *cntrServicoExcursao){
    this->cntrServicoExcursao = cntrServicoExcursao;
}

// -------------------------------------------
// Declaration of controller of Avaliation
// -------------------------------------------

class CntrApresentacaoAvaliacao:public IApresentacaoAvaliacao{
    private:
        IServicoAvaliacao *cntrServicoAvaliacao;
    public:
        void executar();
        void executar(Email);
        void setCntrServicoAvaliacao(IServicoAvaliacao*);
};

inline void CntrApresentacaoAvaliacao::setCntrServicoAvaliacao(IServicoAvaliacao *cntrServicoAvaliacao){
    this->cntrServicoAvaliacao = cntrServicoAvaliacao;
}

// -------------------------------------------
// Declaration of controller of Session
// -------------------------------------------

class CntrApresentacaoSessao:public IApresentacaoSessao{
    private:
        IServicoSessao *cntrServicoSessao;
    public:
        void executar();
        void executar(Email);
        void setCntrServicoSessao(IServicoSessao*);
};

inline void CntrApresentacaoSessao::setCntrServicoSessao(IServicoSessao *cntrServicoSessao){
    this->cntrServicoSessao = cntrServicoSessao;
}
#endif