#pragma once
#include "Inimigo.h"
#include "Atirador.h"
#include "Jogador.h"
#include "CristalGelo.h"

class GolemGelo :
	public Inimigo, public Atirador
{
protected:

	float tamanhoCristal;

public:

	//Construtora e Destrutora
	GolemGelo(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL, float tamCristal = 1);
	~GolemGelo();

	//Funcoes
	void atualizar();
	void desenhar();
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	virtual void arremessarCristal();
	virtual void salvar();
	void setTamanhoCristal(float tamcri);
};
