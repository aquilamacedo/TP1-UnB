/**
 * @file dominios.h
 *
 * @brief file with the declaration of the program's domain classes
 *
 * @author Aquila Macedo - 202021800
 *
 */

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <string>

#define ll long long;

using namespace std;

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

///Dominio Email quer permite instanciar um email.
class Email
{
private:
  ///@param string email
  string email;

  ///Funcao validar que valida uma string que sera usada como email
  ///@param string
  ///@throw invalid_argument
  ///@return void
  void validar(string);

public:
  ///Construtor Email vazio
  Email(); // default

  ///Construtor Email que recebe string para inicilizar um objeto
  ///@param string
  Email(string);

  ///Funcao setEmail, que instancia o objeto com uma string
  ///@param string
  ///return void
  void setEmail(string);

  ///Funcao getEmail
  ///@return string email
  string getEmail() const
  {
    return email;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

///Dominio Nota quer permite instanciar uma nota.
class Nota
{
private:
  ///@param int nota
  int nota;

  ///Funcao validar que valida um inteiro
  ///@throw invalid_argument
  ///@return void
  void validar(int);

public:
  ///Construtor Nota vazio
  Nota(); // default

  ///Construtor Nota que recebe int para inicilizar um objeto
  ///@param int
  Nota(int);

  ///Funcao setNota, que instancia o objeto com um int
  ///@param int
  ///return void
  void setNota(int);

  ///Funcao getNota
  ///@return int nota
  int getNota() const
  {
    return nota;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

///Dominio Nome quer permite instanciar um nome.
class Nome
{
private:
  ///@param string nome
  string nome;
  const static unsigned int TAMANHO_MIN = 5;  //constante
  const static unsigned int TAMANHO_MAX = 20; //constante

  ///Funcao validar que valida uma string
  ///@throw invalid_argument
  ///@return void
  void validar(string);

public:
  ///Construtor Nome vazio
  Nome(); // default

  ///Construtor Nome que recebe uma string para inicilizar um objeto
  ///@param string
  Nome(string);

  ///Funcao setNota, que instancia o objeto com uma string
  ///@param string
  ///return void
  void setNome(string);

  ///Funcao getNome
  ///@return string nome
  string getNome() const
  {
    return nome;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

///Dominio Senha quer permite instanciar uma senha.
class Senha
{
private:
  ///@param string senha
  string senha;
  const static unsigned int LIMITE = 6; //constante

  ///Funcao validar que valida uma string
  ///@throw invalid_argument
  ///@return void
  void validar(string);

public:
  ///Construtor Senha vazio
  Senha(); // default

  ///Construtor Senha que recebe uma string para inicilizar um objeto
  ///@param string
  Senha(string);

  ///Funcao setSenha, que instancia o objeto com uma string
  ///@param string
  ///return void
  void setSenha(string);

  ///Funcao getSenha
  ///@return string senha
  string getSenha() const
  {
    return senha;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

///Dominio Data quer permite instanciar uma data.
class Data
{
private:
  ///@param string data
  string data;
  const static unsigned int TAMANHO_MAX = 11; //constante

  ///Funcao validar que valida uma string
  ///@throw invalid_argument
  ///@return void
  void validar(string);

public:
  ///Construtor Data vazio
  Data(); // default

  ///Construtor Data que recebe uma string para inicilizar um objeto
  ///@param string
  Data(string);

  ///Funcao setData, que instancia o objeto com uma string
  ///@param string
  ///return void
  void setData(string);

  ///Funcao getData
  ///@return string data
  string getData() const
  {
    return data;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Horario
{
private:
  string horario;
  const static unsigned int TAMANHO_MAX = 5;
  void validar(string);

public:
  Horario(); // default
  Horario(string);

  void setHorario(string);

  string getHorario() const
  {
    return horario;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Idioma
{
private:
  string idioma;
  void validar(string);

public:
  Idioma(); // default
  Idioma(string);

  void setIdioma(string);

  string getIdioma() const
  {
    return idioma;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Titulo
{
private:
  string titulo;
  const static int TAMANHO_MIN = 5;
  const static int TAMANHO_MAX = 20;
  void validar(string);

public:
  Titulo(); // default
  Titulo(string);

  void setTitulo(string);

  string getTitulo() const
  {
    return titulo;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Cidade
{
private:
  string cidade;
  void validar(string);

public:
  Cidade(); // default
  Cidade(string);

  void setCidade(string);

  string getCidade() const
  {
    return cidade;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Duracao
{
private:
  string duracao;
  void validar(string);

public:
  Duracao(); // default
  Duracao(string);

  void setDuracao(string);

  string getDuracao() const
  {
    return duracao;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Descricao
{
private:
  string descricao;
  const static int TAMANHO_MIN = 0;
  const static int TAMANHO_MAX = 30;
  void validar(string);

public:
  Descricao(); // default
  Descricao(string);

  void setDescricao(string);

  string getDescricao() const
  {
    return descricao;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Codigo
{
private:
  string codigo;
  const static unsigned int TAMANHO_MAX = 7;
  void validar(string);

public:
  Codigo(); // default
  Codigo(string);

  void setCodigo(string);

  string getDigitoVerificador(int);

  string getCodigo() const
  {
    return codigo;
  }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Endereco
{
private:
  string endereco;
  const static int TAMANHO_MIN = 0;
  const static int TAMANHO_MAX = 20;
  void validar(string);

public:
  Endereco(); // default
  Endereco(string);

  void setEndereco(string);

  string getEndereco() const
  {
    return endereco;
  }
};

#endif // DOMINIOS_H_INCLUDED
