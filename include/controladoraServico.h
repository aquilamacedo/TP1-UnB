#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        // abstract service method of autentication
        virtual bool autenticar(Email, Senha);
};

class CntrServicoUsuario:public IServicoUsuario{
    public:
        // abstract services methods of Users
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual bool descadastrarUsuario(Email) = 0;
        virtual bool editar(Usuario) = 0;
        virtual Usuario recuperar(Email) = 0;
};

class CntrServicoExcursao:public IServicoExcursao{
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
};

#endif