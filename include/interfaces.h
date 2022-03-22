#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "list"

// -------------------------------------------
// Forward declarations of services.
// -------------------------------------------

class IServicoAutenticacao;
class IServicoUsuario;
class IServicoExcursao;
class IServicoAvaliacao;
class IServicoSessao;

// -------------------------------------------
// Declarations of Interfaces of Apresentation
// -------------------------------------------

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoUsuario{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoUsuario(IServicoUsuario*) = 0;
        virtual ~IApresentacaoUsuario(){}
};

class IApresentacaoExcursao{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoExcursao(IServicoExcursao*) = 0;
        virtual ~IApresentacaoExcursao(){}
};

class IApresentacaoAvaliacao{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoAvaliacao(IServicoAvaliacao*) = 0;
        virtual ~IApresentacaoAvaliacao(){}
};

class IApresentacaoSessao{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServicoSessao(IServicoSessao*) = 0;
        virtual ~IApresentacaoSessao(){}
};

// -------------------------------------------
// Declarations of Interfaces of Services
// -------------------------------------------

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoUsuario{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual bool descadastrarUsuario(Email) = 0;
        virtual bool editar(Usuario) = 0;
        virtual Usuario recuperar(Email) = 0;
        virtual ~IServicoUsuario(){}
};

class IServicoExcursao{
public:
        // abstract service methods of Excursion
        virtual bool cadastrarExcursao(Excursao) = 0;
        virtual bool descadastrarExcursao(Codigo) = 0;
        virtual bool editarExcursao(Excursao) = 0;
        virtual Excursao recuperarExcursao(Codigo) = 0;
        virtual list<Excursao> listarExcursoes() = 0;

         // abstract service methods of Avaliation
        virtual bool cadastrarAvaliacao(Avaliacao) = 0;
        virtual bool descadastrarAvaliacao(Codigo) = 0;
        virtual bool editarAvaliacao(Avaliacao) = 0;
        virtual Avaliacao recuperar(Codigo) = 0;
        virtual list<Avaliacao> listarAvaliacoes() = 0;
        virtual list<Avaliacao> listarAvaliacoes(Excursao) = 0;
        virtual list<Avaliacao> listarAvaliacoes(Usuario) = 0;

        // abstract service methods of Session
        virtual bool cadastrarSessao(Sessao) = 0;
        virtual bool descadastrarSessao(Codigo) = 0;
        virtual bool editarSessao(Sessao) = 0;
        virtual Sessao recuperarSessao(Codigo) = 0;
        virtual list<Sessao> listarSessoes() = 0;
        virtual list<Sessao> listarSessoes(Excursao) = 0;

        virtual ~IServicoExcursao(){}
};
#endif
