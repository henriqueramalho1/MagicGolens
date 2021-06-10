#include "stdafx.h"
#include "Inimigo.h"

Inimigo::Inimigo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Personagem(ID, tam, p, v, caminhoTextura, t, j),
nivel(1)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::setNivel(int ni)
{
	nivel = ni;
}
