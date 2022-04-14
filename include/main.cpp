#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <math.h>
#include <string>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoraApresentacao.h"
#include "controladoraServico.h"
#include <regex>

using namespace std;

int main()
{
  // setlocale(LC_ALL, "Portuguese");
  // SetConsoleOutputCP(65001);
  // Declarar poteiros e instanciar controladoras.

  CntrApresentacaoControle *cntrApresentacaoControle;
  IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
  IApresentacaoUsuario *cntrApresentacaoUsuario;
  IApresentacaoExcursao *cntrApresentacaoExcursao;
  IApresentacaoSessao *cntrApresentacaoSessao;
  IApresentacaoAvaliacao *cntrApresentacaoAvaliacao;

  cntrApresentacaoControle = new CntrApresentacaoControle();
  cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
  cntrApresentacaoUsuario = new CntrApresentacaoUsuario();
  cntrApresentacaoExcursao = new CntrApresentacaoExcursao();
  cntrApresentacaoSessao = new CntrApresentacaoSessao();
  cntrApresentacaoAvaliacao = new CntrApresentacaoAvaliacao();

  // Instanciar serviços.

  IServicoAutenticacao *cntrServicoAutenticacao;
  IServicoUsuario *cntrServicoUsuario;
  IServicoExcursao *cntrServicoExcursao;
  IServicoAvaliacao *cntrServicoAvaliacao;
  IServicoSessao *cntrServicoSessao;

  cntrServicoUsuario = new CntrServicoUsuario();
  cntrServicoAutenticacao = new CntrServicoAutenticacao();
  cntrServicoExcursao = new CntrServicoExcursao();

  // Interligar controladoras e stubs.

  cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
  cntrApresentacaoControle->setCntrApresentacaoUsuario(cntrApresentacaoUsuario);
  cntrApresentacaoControle->setCntrApresentacaoExcursao(cntrApresentacaoExcursao);
  cntrApresentacaoControle->setCntrApresentacaoSessao(cntrApresentacaoSessao);
  cntrApresentacaoControle->setCntrApresentacaoAvaliacao(cntrApresentacaoAvaliacao);

  cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
  cntrApresentacaoUsuario->setCntrServicoUsuario(cntrServicoUsuario);
  cntrApresentacaoExcursao->setCntrServicoExcursao(cntrServicoExcursao);
  cntrApresentacaoAvaliacao->setCntrServicoExcursao(cntrServicoExcursao);
  cntrApresentacaoSessao->setCntrServicoExcursao(cntrServicoExcursao);
  initscr();
  cntrApresentacaoControle->executar(); // Solicitar servi�o apresentacao.
  endwin();
  return 0;
}
