#include "testes.h"

using namespace std;

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade do domínio código. matricula:200060295
// --------------------------------------------------------------------------

void TUCodigo::setUp()
{
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown()
{
    delete codigo;
}

void TUCodigo::testarCenarioSucesso()
{
    try
    {
        codigo->setCodigo(VALOR_VALIDO);
        if (codigo->getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioFalha()
{
    try
    {
        codigo->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (codigo->getCodigo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigo::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade do domínio Horario. matricula:200060295

void TUHorario::setUp()
{
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown()
{
    delete horario;
}

void TUHorario::testarCenarioSucesso()
{
    try
    {
        horario->setHorario(VALOR_VALIDO);
        if (horario->getHorario() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUHorario::testarCenarioFalha()
{
    try
    {
        horario->setHorario(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (horario->getHorario() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUHorario::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade do domínio Nota. matricula:200060295

void TUNota::setUp()
{
    nota = new Nota();
    estado = SUCESSO;
}

void TUNota::tearDown()
{
    delete nota;
}

void TUNota::testarCenarioSucesso()
{
    try
    {
        nota->setNota(VALOR_VALIDO);
        if (nota->getNota() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUNota::testarCenarioFalha()
{
    try
    {
        nota->setNota(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (nota->getNota() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUNota::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


// --------------------------------------------------------------------------
// Implementações de métodos de classe de teste de unidade do domínio Titulo. matricula:200060295

void TUTitulo::setUp()
{
    titulo = new Titulo();
    estado = SUCESSO;
}

void TUTitulo::tearDown()
{
    delete titulo;
}

void TUTitulo::testarCenarioSucesso()
{
    try
    {
        titulo->setTitulo(VALOR_VALIDO);
        if (titulo->getTitulo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUTitulo::testarCenarioFalha()
{
    try
    {
        titulo->setTitulo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch (invalid_argument &excecao)
    {
        if (titulo->getTitulo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUTitulo::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

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

/// -------------------------------------------------------------------------------
///  Implementação dos métodos TUNome.
///  Matricula: 202021767
/// -------------------------------------------------------------------------------

void TUNome::setUp(){
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown(){
    delete nome;
}

void TUNome::testarCenarioSucesso(){
    try {
        nome -> setNome(NOME_VALIDO);
        if (nome -> getNome() != NOME_VALIDO)
            estado = FALHA;
    }
    catch(...) {
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha(){
    try{
        nome -> setNome(NOME_INVALIDO);
        estado = FALHA;
    }
    catch(...){
        if (nome -> getNome() == NOME_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

/// -------------------------------------------------------------------------------
///  Implementação dos métodos TUSenha.
///  Matricula: 202021767
/// -------------------------------------------------------------------------------

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try {
        senha -> setSenha(SENHA_VALIDA);
        if (senha -> getSenha() != SENHA_VALIDA)
            estado = FALHA;
    }
    catch(...) {
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha(){
    try{
        senha -> setSenha(SENHA_INVALIDA);
        estado = FALHA;
    }
    catch(...){
        if (senha -> getSenha() == SENHA_INVALIDA)
            estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

/// -------------------------------------------------------------------------------
///  Implementação dos metodos TUCidade.
///  Matricula: 202021767
/// -------------------------------------------------------------------------------

void TUCidade::setUp(){
    cidade = new Cidade();
    estado = SUCESSO;
}

void TUCidade::tearDown(){
    delete cidade;
}

void TUCidade::testarCenarioSucesso(){
    try {
        cidade -> setCidade(CIDADE_VALIDA);
        if (cidade -> getCidade() != CIDADE_VALIDA)
            estado = FALHA;
    }
    catch(...) {
        estado = FALHA;
    }
}

void TUCidade::testarCenarioFalha(){
    try{
        cidade -> setCidade(CIDADE_INVALIDA);
        estado = FALHA;
    }
    catch(...){
        if (cidade -> getCidade() == CIDADE_INVALIDA)
            estado = FALHA;
    }
}

int TUCidade::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

/// -------------------------------------------------------------------------------
///  Implementação dos metodos TUDuracao.
///  Matricula: 202021767
/// -------------------------------------------------------------------------------

void TUDuracao::setUp(){
    duracao = new Duracao();
    estado = SUCESSO;
}

void TUDuracao::tearDown(){
    delete duracao;
}

void TUDuracao::testarCenarioSucesso(){
    try {
        duracao -> setDuracao(DURACAO_VALIDA);
        if (duracao -> getDuracao() != DURACAO_VALIDA)
            estado = FALHA;
    }
    catch(...) {
        estado = FALHA;
    }
}

void TUDuracao::testarCenarioFalha(){
    try{
        duracao -> setDuracao(DURACAO_INVALIDA);
        estado = FALHA;
    }
    catch(...){
        if (duracao -> getDuracao() == DURACAO_INVALIDA)
            estado = FALHA;
    }
}

int TUDuracao::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
