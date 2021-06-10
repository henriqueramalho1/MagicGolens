#include "stdafx.h"
#include "Personagem.h"

//Construtora e Destrutora

Personagem::Personagem(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Entidade(ID, tam, p, v, caminhoTextura, t, j),
	hp(100)
{
}

Personagem::~Personagem()
{
}

void Personagem::setHP(int hp)
{
	this->hp = hp;
}
