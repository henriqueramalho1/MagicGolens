#pragma once
#include "Entidade.h"
class Personagem :
	public Entidade
{
protected:
	
	int hp;

public:

	//Construtora e Destrutora
	Personagem(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
	~Personagem();

	//Funcoes
	virtual void atualizar() = 0;
	virtual void desenhar() = 0;
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL) = 0;
	virtual void salvar() = 0;
	void setHP(int hp);
};
