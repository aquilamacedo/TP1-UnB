#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "entidades.h"
#include "dominios.h"
#include <list>
#include <iostream>
#include <stdio.h>

using namespace std;

class ContainerUsuario
{
private:
    list<Usuario> container;
    static ContainerUsuario *instancia;
    ContainerUsuario(){};

public:
    static ContainerUsuario *getInstancia();
    bool cadastrarUsuario(Usuario);
    bool autenticarUsuario(Email, Senha);
    bool editarUsuario(Usuario);
    bool excluirUsuario(Email);
};

class ContainerExcursao
{
private:
    list<Excursao> containerExcursao;
    list<Sessao> containerSessao;
    list<Avaliacao> containerAvaliacao;
    static ContainerExcursao *instancia;
    ContainerExcursao(){};

public:
    static ContainerExcursao *getInstancia();
    bool cadastrarExcursao(Excursao);
    Excursao recuperarExcursao(Codigo);
    bool editarExcursao(Excursao);
    bool excluirExcursao(Codigo);

    bool cadastrarSessao(Sessao);
    Sessao recuperarSessao(Codigo);
    bool editarSessao(Sessao);
    bool excluirSessao(Codigo);

    bool cadastrarAvaliacao(Avaliacao);
    Avaliacao recuperarAvaliacao(Codigo);
    bool editarAvaliacao(Avaliacao);
    bool excluirAvaliacao(Codigo);
};

#endif // CONTAINERS_H_INCLUDED
