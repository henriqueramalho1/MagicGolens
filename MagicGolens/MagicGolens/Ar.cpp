#include "stdafx.h"
#include "Ar.h"

Ar::Ar(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
	Tile(ID, tam, p, v, caminhoTextura, t, j)
{
}

Ar::~Ar()
{
}

void Ar::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
}
