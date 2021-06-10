#include "stdafx.h"
#include "Tile.h"

Tile::Tile(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Entidade(ID, tam, p, v, caminhoTextura, t, j)
{
	
}

Tile::~Tile() {}

void Tile::setPosicao(float x, float y) {
	sprite.setPosition(x, y);
	posicao.x = x;
	posicao.y = y;
}

void Tile::setRectTextura(int x, int y) {
	sprite.setTextureRect(sf::IntRect(x, y, 16, 16));
	sprite.setScale(sf::Vector2f(6, 6));
}

sf::Sprite Tile::getTileSprite()
{
	return sprite;
}

void Tile::desenhar()
{
	janela->draw(sprite);
}

void Tile::atualizar()
{
}
