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

class Email {
  private:
    string email;
    const static int TAMANHO_MAX_LOCAL = 64;
    const static int TAMANHO_MAX_DOMINIO = 253;
    void validar(string) throw (invalid_argument);
  
  public:
    Email(); // default
    Email(string);

    void setEmail(string);

    string getEmail() const {
      return email;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Nota {
  private:
    int nota;
    void validar(int) throw (invalid_argument);

  public:
    Nota(); // default
    Nota(int);

    void setNota(int);

    int getNota() const {
      return nota;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Nome {
  private:
    string nome;
    const static unsigned int TAMANHO_MIN = 5;
    const static unsigned int TAMANHO_MAX = 20;
    void validar(string) throw (invalid_argument);

  public:
    Nome(); // default
    Nome(string);

    void setNome(string);

    string getNome() const {
      return nome;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Senha {
  private:
    string senha;
    const static unsigned int LIMITE = 6;
    void validar(string) throw (invalid_argument);

  public:
    Senha(); // default
    Senha(string);

    void setSenha(string);

    string getSenha() const {
      return senha;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Data {
  private:
    string data;
    const static unsigned int TAMANHO_MAX = 11;
    void validar(string) throw (invalid_argument);

  public:
    Data(); // default
    Data(string);

    void setData(string);

    string getData() const {
      return data;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Horario {
  private:
    string horario;
    const static unsigned int TAMANHO_MAX = 5;
    void validar(string) throw (invalid_argument);

  public:
    Horario(); // default
    Horario(string);

    void setHorario(string);

    string getHorario() const {
      return horario;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Idioma {
  private:
    string idioma;
    void validar(string) throw (invalid_argument);

  public:
    Idioma(); // default
    Idioma(string);

    void setIdioma(string);

    string getIdioma() const {
      return idioma;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Titulo {
  private:
    string titulo;
    const static int TAMANHO_MIN = 5;
    const static int TAMANHO_MAX = 20;
    void validar(string) throw (invalid_argument);

  public:
    Titulo(); // default
    Titulo(string);

    void setTitulo(string);

    string getTitulo() const {
      return titulo;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Cidade {
  private:
    string cidade;
    void validar(string) throw (invalid_argument);

  public:
    Cidade(); // default
    Cidade(string);

    void setCidade(string);

    string getCidade() const {
      return cidade;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Duracao {
  private:
    string duracao;
    void validar(string) throw (invalid_argument);

  public:
    Duracao(); // default
    Duracao(string);

    void setDuracao(string);

    string getDuracao() const {
      return duracao;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Descricao {
  private:
    string descricao;
    const static int TAMANHO_MIN = 0;
    const static int TAMANHO_MAX = 30;
    void validar(string) throw (invalid_argument);

  public:
    Descricao(); // default
    Descricao(string);

    void setDescricao(string);

    string getDescricao() const {
      return descricao;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Codigo {
  private:
    string codigo;
    const static unsigned int TAMANHO_MAX = 6;
    void validar(string) throw (invalid_argument);

  public:
    Codigo(); // default
    Codigo(string);

    void setCodigo(string);

    string getCodigo() const {
      return codigo;
    }
};

// -------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------

class Endereco {
  private:
    string endereco;
    const static int TAMANHO_MIN = 0;
    const static int TAMANHO_MAX = 20;
    void validar(string) throw (invalid_argument);

  public:
    Endereco(); // default
    Endereco(string);

    void setEndereco(string);

    string getEndereco() const {
      return endereco;
    }
};

#endif // DOMINIOS_H_INCLUDED


