#pragma once
#include "Inimigo.h"

class GolemPedra :
	public Inimigo
{
private:

	float crescimento;
	float cura;

public:

	//Construtora e Destrutora
	GolemPedra(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(20.f, 40.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL);
	~GolemPedra();

	//Funcoes
	void atualizar();
	void desenhar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	void salvar();
	void setCrescimento(float cre);
	void setCura(float cur);
};
