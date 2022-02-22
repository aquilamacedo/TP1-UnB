/**
 * @file dominios.cpp
 *
 * @brief This file contains validation methods and defines domain classes.
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dominios.h"

/// ------------------------------------------------------------------------------------------
/// Implementacoes de dominios e validacoes das classes Email e Senha.
/// Matricula: 202021800
/// ------------------------------------------------------------------------------------------

Email::Email() { }

Email::Email(string email) {
  this->email=email;
}

void Email::validar(string email) throw (invalid_argument) {
  string parteLocal, parteDominio, delimiter, especialChar;
  int tamanhoLocal, tamanhoDominio;
  int flag = 0;

  delimiter = "@";

  parteLocal = email.substr(0, email.find(delimiter));
  parteDominio = email.erase(0, email.find(delimiter) + delimiter.size());

  tamanhoLocal = parteLocal.size();
  tamanhoDominio = parteDominio.size();

  if(tamanhoLocal > TAMANHO_MAX_LOCAL) {
    throw invalid_argument("Email Invalido. A parte local do email nao pode passar de 64 caracteres.");
    }
  else if (tamanhoDominio > TAMANHO_MAX_DOMINIO) {
    throw invalid_argument("Email Invalido. A parte dominio do email nao pode passar de 253 caracteres.");
  }

  for (int i = 0; i < tamanhoLocal; i++) {
    if(!(isalpha(parteLocal[i])) && !(isdigit(parteLocal[i]))) {
        especialChar+=parteLocal[i];
    }
    if((parteLocal[0] == '.' || parteLocal[tamanhoLocal-1] == '.') || (parteLocal[i] == '.' && i != tamanhoLocal-1 && parteLocal[i+1] == '.')) {
      throw invalid_argument("Email Invalido. A parte local nao pode conter ponto(.) no primeiro e no ultimo caractere, tambem nao eh possivel pontos consecutivos.");
    }
  }

  string stringEspecial = "!#$%&'*+-/=?^_`{|}~";

  for(int i = 0; i < especialChar.size(); i++) {
    for(int j = 0; j < stringEspecial.size(); j++) {
      if(especialChar[i] == stringEspecial[j]) {
        flag+=1;
      }
    }
  }

  if(especialChar.size() != flag) {
    throw invalid_argument ("Email Invalido. A parte local pode ter apenas os seguintes caracteres especiais !#$%&'*+-/=?^_`{|}~ sao validos");
  }

  for (int i = 0; i < tamanhoDominio; i++) {
    if(!(isalpha(parteDominio[i])) && !(isdigit(parteDominio[i])) && parteDominio[i] != '-' && parteDominio[i] != '.') {
      throw invalid_argument("Email Invalido. Na parte dominio apenas os caracteres (A-Z ou a-z), hifen(-), ponto(.) e digitos(0-9) podem ser utilizados.");
    }
    if((parteDominio[0] == '.') || (i != tamanhoDominio-1 && parteDominio[i] == '.' && parteDominio[i+1] == '.')) {
      throw invalid_argument("Email Invalido. Na parte dominio o primeiro caractere nao pode ser um ponto(.) e tambem nao eh possivel pontos consecutivos.");
    }
  }
}

void Email::setEmail(string email) {
  validar(email);
  this->email=email;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Nome::Nome() { }

Nome::Nome(string nome) {
  this->nome=nome;
}

void Nome::validar(string nome) throw (invalid_argument) {
  if(nome.size() > TAMANHO_MAX) {
    throw invalid_argument("Nome Invalido. O tamanho limite maximo do nome foi excedido.");
    }
  else if(nome.size() < TAMANHO_MIN) {
    throw invalid_argument("Nome Invalido. O Tamanho limite minimo do nome nao foi satisfeito.");
  }

  for (int i = 0; i < nome.size(); i++) {
    if(!(isalpha(nome[i])) && nome[i] != '.' && nome[i] != ' ') {
      throw invalid_argument("Nome Invalido. Apenas os caracteres (A-Z ou a-z), ponto(.) ou espaço em branco devem ser utilizados");
    }
    if(nome[0] == '.') {
      throw invalid_argument("Nome Invalido. O primeiro caractere nao pode ser um ponto");
    }
    if(nome[i] == '.' && !(isalpha(nome[i-1]))) {
      throw invalid_argument("Nome Invalido. O Caractere precedente ao ponto nao pertence ao alfabeto(A-Z ou a-z)");
    }
    if(nome[i] == ' ' && (i != nome.size() - 1) && nome[i+1] == ' ') {
      throw invalid_argument("Nome Invalido. Nao pode ter espaco consecutivo");
    }
    if(!(isupper(nome[0])) && isalpha(nome[0]) || nome[i] == ' ' && !(isupper(nome[i+1])) && isalpha(nome[i+1])) {
      throw invalid_argument("Nome Invalido. Todos os caracteres de um termo devem iniciar com letra maiscula");
    }
  }
}

void Nome::setNome(string nome) {
  validar(nome);
  this->nome=nome;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Senha::Senha() { }

Senha::Senha(string senha) {
  this->senha=senha;
}

void Senha::validar(string senha) throw (invalid_argument) {
  string aux = " ";
  int maiuscula = 0;
  int minuscula = 0;
  int digito = 0;

  if (senha.size() != LIMITE) {
    throw invalid_argument("Senha invalida. O tamanho da senha precisa ser de 6 caracteres.");
     }

  for ( int i = 0; i < senha.size(); i++ ) {
    if (!(isalpha(senha[i])) && !(isdigit(senha[i]))) {
      throw invalid_argument("Senha invalida. Precisa conter caracteres de A-Z ou dígitos de 0-9.");
    }

    for ( int y = 0; y < aux.size(); y++ ) {
      if (tolower(aux[y]) == tolower(senha[i])) {
        throw invalid_argument("Senha invalida. A senha não pode conter caracteres repetidos.");
      }
    }

    aux += senha[i];
    if (isupper(senha[i])) {
      maiuscula += 1;
    }
    if (isdigit(senha[i])) {
      digito += 1;
    }
    if (islower(senha[i])) {
      minuscula += 1;
    }
  }
  
  if ( maiuscula < 1 || minuscula < 1 || digito < 1 ) {
      throw invalid_argument("Senha invalida. A senha precisa conter pelo menos uma letra maiuscula, uma letra minuscula e um número.");
    }
}

void Senha::setSenha(string senha) {
  validar(senha);
  this->senha=senha;
}

/// ------------------------------------------------------------------------------------------
/// Implementacoes de dominios e validacoes das classes Data, Horario e Idioma.
/// Matricula: 202021800
/// ------------------------------------------------------------------------------------------

Data::Data() { }

Data::Data(string data) {
  this->data=data;
}

void Data::validar(string data) throw (invalid_argument) {
  if(data.size() > TAMANHO_MAX) {
    throw invalid_argument("Data Invalida. Formato invalido!");
  }

  if(data[2] != '-' && data[6] != '-') {
    throw invalid_argument("Data Invalida. Utilize o formato: DD-MES-AAAA");
  }

  vector<string> mesValues = {"Jan","Fev","Mar","Abr","Mai","Jun","Jul","Ago","Set","Out","Nov","Dez"};

  string dia,mes,ano;
  int diaInt,anoInt;
  bool flag = false;

  dia = data.substr(0,2);
  mes = data.substr(3,3);
  ano = data.substr(7,4);

  diaInt = stoi(dia);
  anoInt = stoi(ano);

  // tratamento dos dias
  if(diaInt < 1 or diaInt > 31) {
    throw invalid_argument("Data Invalida. Utilize apenas os dias entre 01 e 31.");
  }

  // tratamento dos meses
  for(int i = 0; i < mesValues.size(); i++) {
    if(mes == mesValues[i]) {
      flag = true;
    }
  }

  if(!(flag)) {
    throw invalid_argument("Data invalida. O mes nao existe ou nao segue o formato ideal.");
  }

  // tratamento dos anos
  if(anoInt < 2000 || anoInt > 9999) {
    throw invalid_argument("Data Invalida. O ano nao existe, utilize apenas o intervalo entre os anos 2000 e 9999");
  }

  // validando se eh bissexto ou nao
  if(mes == "Fev") {
    if((anoInt%4 == 0 && anoInt%100 != 0) || anoInt%400 == 0) {
      if(diaInt > 29) {
        throw invalid_argument("Data Invalida. O ano eh bissexto, porem em fevereiro so pode ter 29 dias");
      }
    }
    else {
      if(diaInt > 28) {
        throw invalid_argument("Data Invalida. O ano nao eh bissexto");
      }
    }
  }
}

void Data::setData(string data) {
  validar(data);
  this->data=data;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Horario::Horario() { }

Horario::Horario(string horario) {
  this->horario=horario;
}

void Horario::validar(string horario) throw (invalid_argument) {
  if(horario.size() > TAMANHO_MAX) {
    throw invalid_argument("Horario Invalido. o limite maximo do horario foi excedido.");
  }

  string hora,minuto;
  int horaInt,minutoInt;

  hora = horario.substr(0,2);
  minuto = horario.substr(3,2);

  horaInt = stoi(hora);
  minutoInt = stoi(minuto);

  if(horaInt < 00 || horaInt > 23) {
    throw invalid_argument("Horario Invalido. Hora Incorreta, use algo entre 00h a 23h");
  }
  if(minutoInt < 00 || minutoInt > 59) {
    throw invalid_argument("Horario Invalido. Minuto Incorreto, use algo entre 00m a 59m");
  }
}

void Horario::setHorario(string horario) {
  validar(horario);
  this->horario=horario;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Idioma::Idioma() { }

Idioma::Idioma(string idioma) {
  this->idioma=idioma;
}

void Idioma::validar(string idioma) throw (invalid_argument) {
  vector<string> listaIdiomas = {"Ingles", "Chines", "Mandarim", "Hindi", "Espanhol", "Frances", "Arabe", "Bengali", "Russo", "Portugues", "Indonesio"};
  bool flag = false;

  for (int i = 0; i < listaIdiomas.size(); i++) {
    if(idioma == listaIdiomas[i]) {
      flag = true;
    }
  }

  if(!(flag)) {
    throw invalid_argument("Idioma Invalido. O idioma escolhido nao existe.");
  }
}

void Idioma::setIdioma(string idioma) {
  validar(idioma);
  this->idioma=idioma;
}

/// ----------------------------------------------------------------------------------------------------------------
/// Implementacoes de dominios e validacoes das classes Titulo, Nota, Cidade, Duracao, Descricao, Codigo e Endereco
/// Matricula: 202021800
/// ----------------------------------------------------------------------------------------------------------------

Titulo::Titulo() { }

Titulo::Titulo(string titulo) {
  this->titulo=titulo;
}

void Titulo::validar(string titulo) throw (invalid_argument) {
  if(titulo.size() < TAMANHO_MIN) {
    throw invalid_argument("Titulo Invalido. O tamanho minimo do titulo nao foi satisfeito.");
  }
  if(titulo.size() > TAMANHO_MAX) {
    throw invalid_argument("Titulo Invalido. O tamanho excedeu o limite maximo do titulo.");
  }

  for (int i = 0; i < titulo.size(); i++) {
    if(!(isalpha(titulo[i])) && titulo[i] != ' ' && titulo[i] != '.') {
      throw invalid_argument("Titulo Invalido. Apenas os caracteres (A-Z ou a-z) sao permitidos.");
    }
    if(titulo[i] == ' ' && (i != titulo.size()-1) && titulo[i+1] == ' ') {
      throw invalid_argument("Titulo Invalido. Nao podem existir espacos consecutivos.");
    }
    if(titulo[i] == '.' && (i != titulo.size()-1) && titulo[i+1] == '.') {
      throw invalid_argument("Titulo Invalido. Nao podem existir pontos(.) consecutivos.");
    }
  }
}

void Titulo::setTitulo(string titulo) {
  validar(titulo);
  this->titulo=titulo;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Nota::Nota() { }

Nota::Nota(int nota) {
  this->nota=nota;
}

void Nota::validar(int nota) throw (invalid_argument) {
  bool flag = false;

  for(int i = 0; i < 6; i++) {
    if(nota == i) {
      flag=true;
    }
  }

  if(!(flag)) {
    throw invalid_argument("Nota Invalida. A nota passada eh invalida, apenas os caracteres 0-6 sao validos.");
  }
}

void Nota::setNota(int nota) {
  validar(nota);
  this->nota=nota;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Cidade::Cidade() { }

Cidade::Cidade(string cidade) {
  this->cidade=cidade;
}

void Cidade::validar(string cidade) throw (invalid_argument) {
  bool flag = false;
  vector<string> cidadeLista = {"Hong Kong", "Bangkok", "Macau", "Singapura", "Londres", "Paris", "Dubai", "Delhi", "Istambul", "Kuala Lumpur", "Nova Iorque", "Antalya", "Mumbai", "Shenzhen", "Phuket"};

  for(int i = 0; i < cidadeLista.size(); i++) {
    if(cidadeLista[i] == cidade) {
      flag = true;
    }
  }

  if(!(flag)) {
    throw invalid_argument("Cidade Invalida. Essa cidade nao existe.");
  }
}

void Cidade::setCidade(string cidade) {
  validar(cidade);
  this->cidade=cidade;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Duracao::Duracao() { }

Duracao::Duracao(string duracao) {
  this->duracao=duracao;
}

void Duracao::validar(string duracao) throw (invalid_argument) {
  int duracaoInt;
  duracaoInt = stoi(duracao);

  if(duracaoInt != 30 && duracaoInt != 60 && duracaoInt != 90 && duracaoInt != 120 && duracaoInt != 180) {
    throw invalid_argument("Duracao Invalida. Apenas as duracoes 30, 60, 90, 120 ou 180 sao permitidas.");
  }
}

void Duracao::setDuracao(string duracao) {
  validar(duracao);
  this->duracao=duracao;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Descricao::Descricao() { }

Descricao::Descricao(string descricao) {
  this->descricao=descricao;
}

void Descricao::validar(string descricao) throw (invalid_argument) {
  if(descricao.size() < TAMANHO_MIN) {
    throw invalid_argument("Descricao Invalida. O tamanho limite minimo da descricao nao foi satisfeito.");
  }
  if(descricao.size() > TAMANHO_MAX) {
    throw invalid_argument("Descricao Invalida. O tamanho limite maximo da descricao foi excedido.");
  }

  for (int i = 0; i < descricao.size(); i++) {
    if(descricao[i] == ' ' && (i != descricao.size()-1) && descricao[i+1] == ' ') {
      throw invalid_argument("Descricao Invalida. Nao podem existir espacos conscutivos.");
    }
    if(descricao[i] == '.' && (i != descricao.size()-1) && descricao[i+1] == '.') {
      throw invalid_argument("Descricao Invalida. Nao podem existir pontos(.) consecutivos.");
    }
  }
}

void Descricao::setDescricao(string descricao) {
  validar(descricao);
  this->descricao=descricao;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Codigo::Codigo() { }

Codigo::Codigo(string codigo) {
  this->codigo = codigo;
}

void Codigo::validar(string codigo) throw (invalid_argument) {
  if (codigo == "000000"){
    throw invalid_argument("Codigo Invalido. Nao existe esse codigo.");
  }
  if (codigo.size() > TAMANHO_MAX) {
    throw invalid_argument("Codigo Invalido. O codigo tem que estar no padrao DDDDDDX.");
  }

  int tamanhoCodigo = codigo.size();
  int somaPar=0, somaImpar=0;
  for (int i = tamanhoCodigo-1; i >= 0; i--) {
    if (i%2!=0) {
      int valorA = codigo[i] - '0';
      valorA *= 2;
      if (valorA > 9) {
        valorA = valorA - 9;
      }
      somaPar+=valorA;
    }
    else {
      int valorB = codigo[i] - '0';
      somaImpar+=valorB;
    }
  }

  int somaTotal = somaImpar+somaPar;

  if (somaTotal%10!=0) {
    throw invalid_argument("Codigo Invalido.");
  }
}

void Codigo::setCodigo(string codigo) {
    validar(codigo);
    this->codigo = codigo;
};

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------

Endereco::Endereco() { }

Endereco::Endereco(string endereco) {
  this->endereco=endereco;
}

void Endereco::validar(string endereco) throw (invalid_argument) {
  if(endereco.size() < TAMANHO_MIN) {
    throw invalid_argument("Endereco Invalido. O tamanho limite minimo do endereco nao foi satisfeito.");
  }
  if(endereco.size() > TAMANHO_MAX) {
    throw invalid_argument("Endereco Invalido. O tamanho limite maximo do endereco foi excedido.");
  }

  for (int i = 0; i < endereco.size(); i++) {
    if(endereco[i] == ' ' && (i != endereco.size()-1) && endereco[i+1] == ' ') {
      throw invalid_argument("Endereco Invalido. Nao podem existir espacos conscutivos.");
    }
    if(endereco[i] == '.' && (i != endereco.size()-1) && endereco[i+1] == '.') {
      throw invalid_argument("Endereco Invalido. Nao podem existir pontos(.) consecutivos.");
    }
  }
}

void Endereco::setEndereco(string endereco) {
  validar(endereco);
  this->endereco=endereco;
}

// ------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------
