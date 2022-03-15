#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

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
        virtual bool cadastrar(Excursao) = 0;
        virtual bool descadastar(Codigo) = 0;
        virtual bool editar(Excursao) = 0;
        virtual Excursao recuperar(Codigo) = 0;
        // virtual vector listarExcursoes() = 0;
        virtual ~IServicoExcursao(){}
};

class IServicoAvaliacao{
public:
        virtual bool cadastrarAvaliacao(Avaliacao) = 0;
        virtual bool descadastrar(Codigo) = 0;
        virtual bool editar(Avaliacao) = 0;
        virtual Avaliacao recuperar(Codigo) = 0;
        virtual ~IServicoAvaliacao(){}
};

class IServicoSessao{
public:
        virtual bool cadastrarSessao(Sessao) = 0;
        virtual bool descadastrar(Codigo) = 0;
        virtual bool editar(Sessao) = 0;
        virtual Avaliacao recuperar(Codigo) = 0;
        virtual ~IServicoSessao(){}
};
#endif
