#include "stdafx.h"
#include <math.h>
#include "GerenciadorColisoes.h"
#include "Arremessavel.h"

GerenciadorColisoes::GerenciadorColisoes() :
	lista()
{
	GMapa = NULL;
	LEntidades = NULL;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::setGerenciadorMapa(GerenciadorMapa* pGm)
{
	GMapa = pGm;
}

void GerenciadorColisoes::setListaEntidades(ListaEntidades* lista)
{
	LEntidades = lista;
}

void GerenciadorColisoes::adicionarEntidade(Entidade* e)
{
	lista.insert(e);
}

void GerenciadorColisoes::removerEntidade(Entidade* e)
{
	lista.erase(e);
}

void GerenciadorColisoes::limparEntidades()
{
	Entidade* pAux;
	set<Entidade*> limpeza;

	for (auto iterador = lista.begin(); iterador != lista.end(); iterador++)
	{
		pAux = *iterador;

		if (pAux->destruirEntidade())
		{
			limpeza.insert(pAux);
		}
	}

	for (auto iterador = limpeza.begin(); iterador != limpeza.end(); iterador++)
	{
		pAux = *iterador;
		removerEntidade(pAux);
		LEntidades->removerDestruir(pAux);
	}

	limpeza.clear();
}

void GerenciadorColisoes::esvaziar()
{
	lista.clear();
}

void GerenciadorColisoes::verificarColisoes()
{
	for (auto colidivel = lista.begin(); colidivel != lista.end(); colidivel++)
	{
		Entidade* e1 = *colidivel;
		vector<GerenciadorMapa::DadosTiles> tilesColidindo = GMapa->checarColisoes(e1->getPosicao(), e1->getDimensoes());

		for (auto colisao : tilesColidindo)
		{
			e1->colidir(colisao.Id, colisao.posicao, colisao.tamanho);
			colisao.tile->setPosicao(colisao.posicao.x, colisao.posicao.y);
			colisao.tile->colidir(e1->getId(), e1->getPosicao(), e1->getDimensoes(), e1);
		}

		auto outroColidivel = colidivel;
		outroColidivel++;

		for (; outroColidivel != lista.end(); outroColidivel++)
		{
			Entidade* e2 = *outroColidivel;

			if (estaoColidindo(e1, e2))
			{
				e1->colidir(e2->getId(), e2->getPosicao(), e2->getDimensoes());
				e2->colidir(e1->getId(), e1->getPosicao(), e1->getDimensoes());
			}
		}
	}

	limparEntidades();

}

bool GerenciadorColisoes::estaoColidindo(Entidade* e1, Entidade* e2)
{
	sf::Vector2f p1 = e1->getPosicao();
	sf::Vector2f p2 = e2->getPosicao();
	sf::Vector2f dim1 = e1->getDimensoes();
	sf::Vector2f dim2 = e2->getDimensoes();

	sf::Vector2f dist = p1 - p2;

	if (fabsf(dist.x) < ((dim1.x + dim2.x) / 2) && fabsf(dist.y) < ((dim1.y + dim2.y) / 2))
		return true;

	return false;
}

Entidade* GerenciadorColisoes::operator[](int i)
{
	if (i >= 0 && i < lista.size())
	{
		set<Entidade*>::iterator it = lista.begin();

		for (int j = 0; j != i; j++, it++)
		{

		}

		return *it;
	}
	else
	{
		cout << "ERRO: Acesso indevido de memória na lista do gerenciador de colisoes" << endl;
		exit(90);
	}
}

bool GerenciadorColisoes::operator!()
{
	return lista.empty();
}
