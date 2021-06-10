#pragma once
#include "Inimigo.h"

class GolemFogo :
	public Inimigo
{
private:

	float aceleracao;

public:

	//Construtora e Destrutora
	GolemFogo(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
	~GolemFogo();

	//Funcoes
	void atualizar();
	void desenhar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	void salvar();
	void setAceleracao(float a);
};
