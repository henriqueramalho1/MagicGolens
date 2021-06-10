#include "stdafx.h"
#include "GerenciadorMapa.h"

GerenciadorMapa::GerenciadorMapa(map <int, Tile*> map, Mapa* pm, sf::RenderWindow* j) :
	mapaTiles(map),
	pmapa(pm)
{
	if (pm == NULL)
		exit(80);

	background = NULL;
	janela = j;
}

GerenciadorMapa::~GerenciadorMapa()
{
	mapaTiles.clear();
}

void GerenciadorMapa::desenhar()
{
	janela->draw(*background);

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			Tile* ptile = NULL;
			int k = pmapa->getInfoMapa(i, j).x + pmapa->getInfoMapa(i, j).y;
			ptile = mapaTiles[k];
			ptile->setPosicao(i * 96.f, j * 96.f);
			ptile->setRectTextura((pmapa->getInfoXMapa(i, j) * 16), (pmapa->getInfoYMapa(i, j) * 16));
			ptile->desenhar();
		}
	}
}

sf::Vector2f GerenciadorMapa::converterCoordenadas(int i, int j)
{
	return sf::Vector2f(96.f * i + 96 / 2.f, 96.f * j + 96 / 2.f);
}

vector<GerenciadorMapa::DadosTiles> GerenciadorMapa::checarColisoes(sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt)
{
	vector<GerenciadorMapa::DadosTiles> colisoes;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			int k = pmapa->getInfoXMapa(i, j) + pmapa->getInfoYMapa(i, j);

			Tile* tile = mapaTiles[k];

			if (tile->getId() != naocolidivel)
			{
				sf::Vector2f p = converterCoordenadas(i, j);
				tile->setPosicao(p.x, p.y);

				if (estaoColidindo(posicaoEnt, tamanhoEnt, p))
				{
					colisoes.push_back({ tile ,tile->getId(), tile->getPosicao(), tile->getDimensoes() });
				}
			}
		}
	}

	return colisoes;
}

bool GerenciadorMapa::estaoColidindo(sf::Vector2f posicaoEnt, sf::Vector2f tamanhoEnt, sf::Vector2f posTile)
{
	sf::Vector2f dist = posicaoEnt - posTile;

	if ((fabsf(dist.x) < ((tamanhoEnt.x + 96) / 2)) && (fabsf(dist.y) < ((tamanhoEnt.y + 96) / 2)))
		return true;

	return false;
}

void GerenciadorMapa::setMapa(Mapa* pm)
{
	pmapa = pm;
}

Mapa* GerenciadorMapa::getMapa() const
{
	return pmapa;
}

void GerenciadorMapa::setBackground(sf::Sprite* sp) {
	background = sp;
}

sf::Sprite* GerenciadorMapa::getBackground() {
	return background;
}