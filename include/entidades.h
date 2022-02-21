#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>

#include "dominios.h"

using namespace std;

/// -----------------------------------------------------------------------------
/// Declaracao da entidade Excursao. Matricula: 202021767
/// -----------------------------------------------------------------------------
class Excursao {

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
    public:
        void setCodigo(const Codigo&);
        void setTitulo(const Titulo&);
        void setNota(const Nota&);
        void setCidade(const Cidade&);
        void setDuracao(const Duracao&);
        void setDescricao(const Descricao&);
        void setEndereco(const Endereco&);

        Codigo getCodigo() const;
        Titulo getTitulo() const;
        Nota getNota() const;
        Cidade getCidade() const;
        Duracao getDuracao() const;
        Descricao getDescricao() const;
        Endereco getEndereco() const;
};

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline set da entidade Excursao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline void Excursao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline void Excursao::setTitulo(const Titulo& titulo){
    this->titulo = titulo;
}

inline void Excursao::setNota(const Nota& nota){
    this->nota = nota;
}

inline void Excursao::setCidade(const Cidade& cidade){
    this->cidade = cidade;
}

inline void Excursao::setDuracao(const Duracao& duracao){
    this->duracao = duracao;
}

inline void Excursao::setDescricao(const Descricao& descricao){
    this->descricao = descricao;
}

inline void Excursao::setEndereco(const Endereco& endereco){
    this->endereco = endereco;
}

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline get da entidade Excursao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline Codigo Excursao::getCodigo() const {
    return codigo;
}

inline Titulo Excursao::getTitulo() const {
    return titulo;
}

inline Nota Excursao::getNota() const {
    return nota;
}

inline Cidade Excursao::getCidade() const {
    return cidade;
}

inline Duracao Excursao::getDuracao() const {
    return duracao;
}

inline Descricao Excursao::getDescricao() const {
    return descricao;
}

inline Endereco Excursao::getEndereco() const {
    return endereco;
}

/// -----------------------------------------------------------------------------
/// Declaracao da entidade Sessao. Matricula: 202021767
/// -----------------------------------------------------------------------------

class Sessao {
    private:
///@param Codigo codigo
///@param Data data
///@param Horario horario
///@param Idioma idioma

        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;
    public:
        void setCodigo(const Codigo&);
        void setData(const Data&);
        void setHorario(const Horario&);
        void setIdioma(const Idioma&);

        Codigo getCodigo() const;
        Data getData() const;
        Horario getHorario() const;
        Idioma getIdioma() const;
};

/// -----------------------------------------------------------------------------
/// Implementacao Metodos inline set da entidade Sessao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline void Sessao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline void Sessao::setData(const Data& data){
    this->data = data;
}

inline void Sessao::setHorario(const Horario& horario){
    this->horario = horario;

}

inline void Sessao::setIdioma(const Idioma& idioma){
    this->idioma = idioma;
}

/// -----------------------------------------------------------------------------
/// Implementação Metodos inline get da entidade Sessao. Matricula: 202021767
/// -----------------------------------------------------------------------------

inline Codigo Sessao::getCodigo() const {
    return codigo;
}

inline Data Sessao::getData() const {
    return  data;
}

inline Horario Sessao::getHorario() const {
    return horario;
}

inline Idioma Sessao::getIdioma() const {
    return idioma;
}

#endif // ENTIDADES_H_INCLUDED

