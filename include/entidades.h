#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

#include "dominios.h"

using namespace std;

/// -----------------------------------------------------------------------------
/// Declaracao da entidade Usuario. Matricula: 200060295
/// -----------------------------------------------------------------------------

class Usuario
{
private:
    ///@param Nome nome
    ///@param Email email
    ///@param Senha senha

    Nome nome;
    Email email;
    Senha senha;

public:
    void setNome(const Nome &);
    Nome getNome() const;
    void setEmail(const Email &);
    Email getEmail() const;
    void setSenha(const Senha &);
    Senha getSenha() const;
};

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline set da entidade Usuario. Matricula: 200060295
/// -----------------------------------------------------------------------------

inline void Usuario::setNome(const Nome &nome)
{
    this->nome = nome;
}
inline void Usuario::setEmail(const Email &email)
{
    this->email = email;
}
inline void Usuario::setSenha(const Senha &senha)
{
    this->senha = senha;
}

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline get da entidade Usuario. Matricula: 200060295
/// -----------------------------------------------------------------------------

inline Nome Usuario::getNome() const
{
    return nome;
}
inline Email Usuario::getEmail() const
{
    return email;
}
inline Senha Usuario::getSenha() const
{
    return senha;
}

/// -----------------------------------------------------------------------------
/// Declaracao da entidade Avaliacao. Matricula: 200060295
/// -----------------------------------------------------------------------------

class Avaliacao
{
private:
    ///@param Codigo codigo
    ///@param Nota nota
    ///@param Descricao descricao

    Codigo codigo;
    Nota nota;
    Descricao descricao;
    Codigo codigoExcursao;
    Email email;

public:
    void setCodigo(const Codigo &);
    Codigo getCodigo() const;
    void setNota(const Nota &);
    Nota getNota() const;
    void setDescricao(const Descricao &);
    Descricao getDescricao() const;
    void setEmail(const Email &);
    Email getEmail() const;
    void setCodigoExcursao(const Codigo &);
    Codigo getCodigoExcursao() const;
};

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline set da entidade Avaliacao. Matricula: 200060295
/// -----------------------------------------------------------------------------

inline void Avaliacao::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}
inline void Avaliacao::setDescricao(const Descricao &descricao)
{
    this->descricao = descricao;
}
inline void Avaliacao::setNota(const Nota &nota)
{
    this->nota = nota;
}
inline void Avaliacao::setEmail(const Email &email)
{
    this->email = email;
}
inline void Avaliacao::setCodigoExcursao(const Codigo &codigoExcursao)
{
    this->codigoExcursao = codigoExcursao;
}
/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline get da entidade Avaliacao. Matricula: 200060295
/// -----------------------------------------------------------------------------

inline Codigo Avaliacao::getCodigo() const
{
    return codigo;
}
inline Nota Avaliacao::getNota() const
{
    return nota;
}
inline Descricao Avaliacao::getDescricao() const
{
    return descricao;
}

inline Email Avaliacao::getEmail() const
{
    return email;
}
inline Codigo Avaliacao::getCodigoExcursao() const
{
    return codigoExcursao;
}
/// -----------------------------------------------------------------------------
/// Declaracao da entidade Excursao. Matricula: 202021767
/// -----------------------------------------------------------------------------

class Excursao
{

private:
    ///@param Codigo codigo
    ///@param Titulo titulo
    ///@param Nota nota
    ///@param Cidade cidade
    ///@param Duracao duracao
    ///@param Descricao descricao
    ///@param Endereco endereco

    Codigo codigo;
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;
    Email email;

public:
    void setCodigo(const Codigo &);
    void setTitulo(const Titulo &);
    void setNota(const Nota &);
    void setCidade(const Cidade &);
    void setDuracao(const Duracao &);
    void setDescricao(const Descricao &);
    void setEndereco(const Endereco &);
    void setEmail(const Email &);

    Codigo getCodigo() const;
    Titulo getTitulo() const;
    Nota getNota() const;
    Cidade getCidade() const;
    Duracao getDuracao() const;
    Descricao getDescricao() const;
    Endereco getEndereco() const;
    Email getEmail() const;
};

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline set da entidade Excursao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline void Excursao::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline void Excursao::setTitulo(const Titulo &titulo)
{
    this->titulo = titulo;
}

inline void Excursao::setNota(const Nota &nota)
{
    this->nota = nota;
}

inline void Excursao::setCidade(const Cidade &cidade)
{
    this->cidade = cidade;
}

inline void Excursao::setDuracao(const Duracao &duracao)
{
    this->duracao = duracao;
}

inline void Excursao::setDescricao(const Descricao &descricao)
{
    this->descricao = descricao;
}

inline void Excursao::setEndereco(const Endereco &endereco)
{
    this->endereco = endereco;
}

inline void Excursao::setEmail(const Email &email)
{
    this->email = email;
}

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline get da entidade Excursao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline Codigo Excursao::getCodigo() const
{
    return codigo;
}

inline Titulo Excursao::getTitulo() const
{
    return titulo;
}

inline Nota Excursao::getNota() const
{
    return nota;
}

inline Cidade Excursao::getCidade() const
{
    return cidade;
}

inline Duracao Excursao::getDuracao() const
{
    return duracao;
}

inline Descricao Excursao::getDescricao() const
{
    return descricao;
}

inline Endereco Excursao::getEndereco() const
{
    return endereco;
}

inline Email Excursao::getEmail() const
{
    return email;
}

/// -----------------------------------------------------------------------------
/// Declaracao da entidade Sessao. Matricula: 202021767
/// -----------------------------------------------------------------------------

class Sessao
{
private:
    ///@param Codigo codigo
    ///@param Data data
    ///@param Horario horario
    ///@param Idioma idioma

    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;
    Codigo codigoExcursao;

public:
    void setCodigo(const Codigo &);
    void setData(const Data &);
    void setHorario(const Horario &);
    void setIdioma(const Idioma &);
    void setCodigoExcursao(const Codigo &);

    Codigo getCodigo() const;
    Data getData() const;
    Horario getHorario() const;
    Idioma getIdioma() const;
    Codigo getCodigoExcursao() const;
};

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline set da entidade Sessao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline void Sessao::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

inline void Sessao::setData(const Data &data)
{
    this->data = data;
}

inline void Sessao::setHorario(const Horario &horario)
{
    this->horario = horario;
}

inline void Sessao::setIdioma(const Idioma &idioma)
{
    this->idioma = idioma;
}

inline void Sessao::setCodigoExcursao(const Codigo &codigoExcursao)
{
    this->codigoExcursao = codigoExcursao;
}

/// -----------------------------------------------------------------------------
/// Implementação Metodos inline get da entidade Sessao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline Codigo Sessao::getCodigo() const
{
    return codigo;
}

inline Data Sessao::getData() const
{
    return data;
}

inline Horario Sessao::getHorario() const
{
    return horario;
}

inline Idioma Sessao::getIdioma() const
{
    return idioma;
}

inline Codigo Sessao::getCodigoExcursao() const
{
    return codigoExcursao;
}
#endif // ENTIDADES_H_INCLUDED
