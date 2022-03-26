#include "conteiner.h"

//##############################################################################################################
//#                                          Usuários                                                          #
//##############################################################################################################

ContainerUsuario *ContainerUsuario::instancia = nullptr;

ContainerUsuario *ContainerUsuario::getInstancia()
{
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::cadastrarUsuario(Usuario usuario)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getEmail() == usuario.getEmail().getEmail())
        {
            return false;
        }
    }
    // Inclui objeto.
    container.push_back(usuario);
    return true;
}

bool ContainerUsuario::autenticarUsuario(Email email, Senha senha)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getEmail() == email.getEmail())
        {
            if (elemento->getSenha().getSenha() == senha.getSenha())
            {
                return true;
            }
        }
    }
    return false;
}

bool ContainerUsuario::excluirUsuario(Email email)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getEmail() == email.getEmail())
        {
            // Remove objeto localizado.
            container.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::editarUsuario(Usuario usuario)
{
    for (list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++)
    {
        if (elemento->getEmail().getEmail() == usuario.getEmail().getEmail())
        {
            elemento->setNome(usuario.getNome());
            elemento->setSenha(usuario.getSenha());
            return true;
        }
    }
    return false;
}

//##############################################################################################################
//#                                              Excursões                                                     #
//##############################################################################################################

ContainerExcursao *ContainerExcursao::instancia = nullptr;

ContainerExcursao *ContainerExcursao::getInstancia()
{
    if (instancia == nullptr)
        instancia = new ContainerExcursao();
    return instancia;
}

bool ContainerExcursao::cadastrarExcursao(Excursao excursao)
{
    ;
    for (list<Excursao>::iterator elemento = containerExcursao.begin(); elemento != containerExcursao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == excursao.getCodigo().getCodigo())
        {
            return false;
        }
    }
    // Inclui objeto.
    containerExcursao.push_back(excursao);

    return true;
}

bool ContainerExcursao::excluirExcursao(Codigo codigo)
{
    for (list<Excursao>::iterator elemento = containerExcursao.begin(); elemento != containerExcursao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo())
        {
            // Remove objeto localizado.
            containerExcursao.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerExcursao::editarExcursao(Excursao excursao)
{
    for (list<Excursao>::iterator elemento = containerExcursao.begin(); elemento != containerExcursao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == excursao.getCodigo().getCodigo())
        {
            elemento->setTitulo(excursao.getTitulo());
            elemento->setNota(excursao.getNota());
            elemento->setCidade(excursao.getCidade());
            elemento->setDuracao(excursao.getDuracao());
            elemento->setDescricao(excursao.getDescricao());
            elemento->setEndereco(excursao.getEndereco());
            return true;
        }
    }
    return false;
}

Excursao ContainerExcursao::recuperarExcursao(Codigo codigo)
{
    // int numeracao = 1;

    // char texto1[] = "Essas são as peças existentes:";
    // cout << texto1 << "\n"
    //      << endl;

    for (list<Excursao>::iterator elemento = containerExcursao.begin(); elemento != containerExcursao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo())
        {
            std::cout << elemento->getTitulo().getTitulo() << std::endl;
            std::cout << elemento->getCodigo().getCodigo() << std::endl;
        }
    }
    return Excursao();
}

//##############################################################################################################
//#                                              Sessão                                                        #
//##############################################################################################################

bool ContainerExcursao::cadastrarSessao(Sessao sessao)
{
    ;
    for (list<Sessao>::iterator elemento = containerSessao.begin(); elemento != containerSessao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == sessao.getCodigo().getCodigo())
        {
            return false;
        }
    }
    // Inclui objeto.
    containerSessao.push_back(sessao);

    return true;
}

bool ContainerExcursao::excluirSessao(Codigo codigo)
{
    for (list<Sessao>::iterator elemento = containerSessao.begin(); elemento != containerSessao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo())
        {
            // Remove objeto localizado.
            containerSessao.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerExcursao::editarSessao(Sessao excursao)
{
    for (list<Sessao>::iterator elemento = containerSessao.begin(); elemento != containerSessao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == excursao.getCodigo().getCodigo())
        {
            elemento->setData(excursao.getData());
            elemento->setHorario(excursao.getHorario());
            elemento->setIdioma(excursao.getIdioma());
            return true;
        }
    }
    return false;
}

Sessao ContainerExcursao::recuperarSessao(Codigo codigo)
{
    for (list<Sessao>::iterator elemento = containerSessao.begin(); elemento != containerSessao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo())
        {
            std::cout << elemento->getCodigo().getCodigo() << std::endl;
            std::cout << elemento->getData().getData() << std::endl;
            std::cout << elemento->getHorario().getHorario() << std::endl;
            std::cout << elemento->getIdioma().getIdioma() << std::endl;
        }
    }
    return Sessao();
}

//##############################################################################################################
//#                                                Avaliação                                                   #
//##############################################################################################################

bool ContainerExcursao::cadastrarAvaliacao(Avaliacao sessao)
{
    ;
    for (list<Avaliacao>::iterator elemento = containerAvaliacao.begin(); elemento != containerAvaliacao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == sessao.getCodigo().getCodigo())
        {
            return false;
        }
    }
    // Inclui objeto.
    containerAvaliacao.push_back(sessao);

    return true;
}

bool ContainerExcursao::excluirAvaliacao(Codigo codigo)
{
    for (list<Avaliacao>::iterator elemento = containerAvaliacao.begin(); elemento != containerAvaliacao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo())
        {
            // Remove objeto localizado.
            containerAvaliacao.erase(elemento);
            return true;
        }
    }
    return false;
}

bool ContainerExcursao::editarAvaliacao(Avaliacao excursao)
{
    for (list<Avaliacao>::iterator elemento = containerAvaliacao.begin(); elemento != containerAvaliacao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == excursao.getCodigo().getCodigo())
        {
            elemento->setDescricao(excursao.getDescricao());
            elemento->setNota(excursao.getNota());
            return true;
        }
    }
    return false;
}

Avaliacao ContainerExcursao::recuperarAvaliacao(Codigo codigo)
{
    for (list<Avaliacao>::iterator elemento = containerAvaliacao.begin(); elemento != containerAvaliacao.end(); elemento++)
    {
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo())
        {
            std::cout << elemento->getCodigo().getCodigo() << std::endl;
            std::cout << elemento->getDescricao().getDescricao() << std::endl;
            std::cout << elemento->getNota().getNota() << std::endl;
        }
    }
    return Avaliacao();
}