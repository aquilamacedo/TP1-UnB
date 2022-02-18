#include "testes.h"

using namespace std;

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------

void TUEmail::setUp() {
  email = new Email();
  estado = SUCESSO;
}

void TUEmail::tearDown() {
  delete email;
}

void TUEmail::testarCenarioSucesso() {
  try {
    email->setEmail(EMAIL_VALIDO);
    if (email->getEmail() != EMAIL_VALIDO) {
      estado = FALHA;
    }
  }
  catch(...) {
    estado = FALHA;
  }
}

void TUEmail::testarCenarioFalha() {
  try {
    email->setEmail(EMAIL_INVALIDO);
    estado = FALHA;
  }
  catch(...) {
    if (email->getEmail() == EMAIL_INVALIDO) {
      estado = FALHA;
    }
  }
}

int TUEmail::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------

void TUData::setUp() {
  data = new Data();
  estado = SUCESSO;
}

void TUData::tearDown() {
  delete data;
}

void TUData::testarCenarioSucesso() {
  try {
    data->setData(DATA_VALIDA);
    if (data->getData() != DATA_VALIDA) {
      estado = FALHA;
    }
  }
  catch(...) {
    estado = FALHA;
  }
}

void TUData::testarCenarioFalha() {
  try {
    data->setData(DATA_INVALIDA);
    estado = FALHA;
  }
  catch(...) {
    if (data->getData() == DATA_INVALIDA) {
      estado = FALHA;
    }
  }
}

int TUData::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------

void TUDescricao::setUp() {
  descricao = new Descricao();
  estado = SUCESSO;
}

void TUDescricao::tearDown() {
  delete descricao;
}

void TUDescricao::testarCenarioSucesso() {
  try {
    descricao->setDescricao(DESCRICAO_VALIDA);
    if (descricao->getDescricao() != DESCRICAO_VALIDA) {
      estado = FALHA;
    }
  }
  catch(...) {
    estado = FALHA;
  }
}

void TUDescricao::testarCenarioFalha() {
  try {
    descricao->setDescricao(DESCRICAO_INVALIDA);
    estado = FALHA;
  }
  catch(...) {
    if (descricao->getDescricao() == DESCRICAO_INVALIDA) {
      estado = FALHA;
    }
  }
}

int TUDescricao::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------

void TUEndereco::setUp() {
  endereco = new Endereco();
  estado = SUCESSO;
}

void TUEndereco::tearDown() {
  delete endereco;
}

void TUEndereco::testarCenarioSucesso() {
  try {
    endereco->setEndereco(ENDERECO_VALIDO);
    if (endereco->getEndereco() != ENDERECO_VALIDO) {
      estado = FALHA;
    }
  }
  catch(...) {
    estado = FALHA;
  }
}

void TUEndereco::testarCenarioFalha() {
  try {
    endereco->setEndereco(ENDERECO_INVALIDO);
    estado = FALHA;
  }
  catch(...) {
    if (endereco->getEndereco() == ENDERECO_INVALIDO) {
      estado = FALHA;
    }
  }
}

int TUEndereco::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------

void TUIdioma::setUp() {
  idioma = new Idioma();
  estado = SUCESSO;
}

void TUIdioma::tearDown() {
  delete idioma;
}

void TUIdioma::testarCenarioSucesso() {
  try {
    idioma->setIdioma(IDIOMA_VALIDO);
    if (idioma->getIdioma() != IDIOMA_VALIDO) {
      estado = FALHA;
    }
  }
  catch(...) {
    estado = FALHA;
  }
}

void TUIdioma::testarCenarioFalha() {
  try {
    idioma->setIdioma(IDIOMA_INVALIDO);
    estado = FALHA;
  }
  catch(...) {
    if (idioma->getIdioma() == IDIOMA_INVALIDO) {
      estado = FALHA;
    }
  }
}

int TUIdioma::run() {
  setUp();
  testarCenarioSucesso();
  testarCenarioFalha();
  tearDown();
  return estado;
}

// -------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------
