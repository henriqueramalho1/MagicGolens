#include "stdafx.h"
#include "GerenciadorAtualizacoes.h"
#include "GerenciadorEstado.h"

GerenciadorAtualizacoes::GerenciadorAtualizacoes() :
	relogio(),
	dt(0.f)
{
	GEstado = NULL;
	LEntidades = NULL;
	fase = NULL;
	relogio.restart();
}

GerenciadorAtualizacoes::~GerenciadorAtualizacoes()
{
	LEntidades = NULL;
	GEstado = NULL;
	LEntidades = NULL;
	fase = NULL;
}

void GerenciadorAtualizacoes::setGerenciador(GerenciadorEstado* Ge)
{
	if (Ge != NULL)
	{
		GEstado = Ge;
	}
	else
	{
		cout << "ERRO: Gerenciador de atualizacoes nao conseguir receber o gerenciador de estados corretamente" << endl;
		exit(987);
	}
}

void GerenciadorAtualizacoes::setListaEntidades(ListaEntidades* L)
{
	if (L != NULL)
		LEntidades = L;
	else
		cout << "ERRO: Gerenciador de atualizacoes nao conseguiu receber a lista de forma correta" << endl;
}

void GerenciadorAtualizacoes::relogioRestart()
{
	dt = relogio.restart().asSeconds();
}

void GerenciadorAtualizacoes::atualizar()
{
	if (!GEstado->menuAtivo())
	{
		LEntidades->atualizar();

		if (fase->jogadorMorto())
		{
			fase->setPosicaoJogadores();
		}

		if (calcularDistancia(fase->getPosicaoJogador(), fase->getPontoFinal()) <= 96)
		{
			fase->setConcluida(true);
		}
	}
}

void GerenciadorAtualizacoes::setFase(Fase* f)
{
	if (f != NULL)
		fase = f;
	else
	{
		cout << "ERRO: Gerenciador de atualizacoes nao conseguiu receber a fase devidamente" << endl;
		exit(244);
	}
}

float* GerenciadorAtualizacoes::getTempo()
{
	return &dt;
}

float GerenciadorAtualizacoes::calcularDistancia(sf::Vector2f pj, sf::Vector2f pf)
{
	float d, dx, dy;

	dx = (pj.x - pf.x);
	dy = (pj.y - pf.y);

	d = sqrt(dx * dx + dy * dy);

	return d;
}