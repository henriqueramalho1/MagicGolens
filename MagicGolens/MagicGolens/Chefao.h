#pragma once
#include "GolemGelo.h"
class Chefao :
	public GolemGelo
{
private:

public:

	//Construtora e Destrutora
	Chefao(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL, float tamCristal = 1);
	~Chefao();

	//Funcoes
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	void arremessarCristal();
	void salvar();

};

