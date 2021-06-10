#pragma once
#include <math.h>
#include "Arremessavel.h"
class Orbe : public Arremessavel
{
private:

public:

	//Construtora e Destrutora
	Orbe(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(28.f, 28.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
	~Orbe();

	//Funcoes
	void atualizar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	void salvar();
};
