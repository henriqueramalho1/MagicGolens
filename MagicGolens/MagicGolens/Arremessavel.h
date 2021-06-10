#pragma once
#include "Entidade.h"
#include "ListaEntidades.h"
#include "GerenciadorColisoes.h"


class Arremessavel : public Entidade
{
protected:

public:

	//Construtora e Destrutora
	Arremessavel(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(28.f, 28.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
	~Arremessavel();

	//Funcoes
	virtual void atualizar() = 0;
	void desenhar();
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL) = 0;
	virtual void salvar() = 0;
};
