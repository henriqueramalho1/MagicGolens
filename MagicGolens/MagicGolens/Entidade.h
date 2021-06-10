#pragma once
#include "stdafx.h"
#include "IdsColidiveis.h"
#include <fstream>
using namespace IdsCol;

class Entidade
{
protected:
	const IdsColidiveis Id;
	sf::Texture textura;
	sf::Sprite sprite;
	sf::Vector2f posicao;
	sf::Vector2f velocidade;
	sf::Vector2f dimensoes;
	sf::RectangleShape corpo;
	sf::RenderWindow* janela;
	float* dt;
	bool destruir;
	bool viradoDir;

public:

	//Construtora e Destrutora
	Entidade(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 144.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
	~Entidade();

	//Funcoes
	virtual void atualizar() = 0;
	virtual void desenhar() = 0;
	virtual void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL) = 0;
	void setPosicao(sf::Vector2f p);
	void setVelocidadeX(float x);
	void setVelocidadeY(float y);
	void virar();
	sf::Vector2f getPosicao();
	sf::Vector2f getDimensoes();
	const IdsColidiveis getId();
	bool destruirEntidade() const;
	bool getViradoDir();
	void setViradoDir(bool v);
	virtual void salvar() = 0;
	void limparSalvamento();
};