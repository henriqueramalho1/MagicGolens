#include "stdafx.h"
#include "Fogo.h"

Fogo::Fogo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
	Obstaculo(ID, tam, p, v, caminhoTextura, t, j)
{
}

Fogo::~Fogo()
{
}

void Fogo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
}
