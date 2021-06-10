#include "stdafx.h"
#include "Obstaculo.h"

Obstaculo::Obstaculo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
	Tile(ID, tam, p, v, caminhoTextura, t, j)
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::atualizar()
{
}
