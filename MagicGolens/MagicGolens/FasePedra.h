#pragma once
#include "Fase.h"

class FasePedra :
	public Fase
{
private:

public:

	//Construtora e Destrutora
	FasePedra(const char* caminhoTile = "", const char* caminhoMapa = "", const char* caminhoBackground = "", sf::Vector2f ponto = sf::Vector2f(0.f, 0.f), float* t = NULL, sf::RenderWindow* j = NULL);
	~FasePedra();

	//Funcoes
	void setPosicaoJogadores();
	const sf::Vector2f getPontoFinal() const;
	void criarInimigos();
	void criarObstaculos();
	void inicializarTiles(const char* caminhoTile);
	void recuperarEntes();

};
