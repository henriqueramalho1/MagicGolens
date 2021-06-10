#include "stdafx.h"
#include "Arremessavel.h"

Arremessavel::Arremessavel(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Entidade(ID, tam, p, v, caminhoTextura, t, j)
{
}

Arremessavel::~Arremessavel()
{
}

void Arremessavel::desenhar()
{
	janela->draw(corpo);
}
