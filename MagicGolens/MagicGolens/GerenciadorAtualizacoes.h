#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Fase.h"
#include "Menu.h"
#include "GerenciadorGrafico.h"
using namespace IdsCol;

class GerenciadorEstado;

class GerenciadorAtualizacoes
{
private:

	GerenciadorEstado* GEstado;
	ListaEntidades* LEntidades;
	Fase* fase;
	sf::Clock relogio;
	float dt;

public:

	//Construtora e Destrutora
	GerenciadorAtualizacoes();
	~GerenciadorAtualizacoes();

	//Funcoes
	void setGerenciador(GerenciadorEstado* Ge);
	void setListaEntidades(ListaEntidades* L);
	void relogioRestart();
	void atualizar();
	void setFase(Fase* f);
	float* getTempo();
	float calcularDistancia(sf::Vector2f pj, sf::Vector2f pf);

};
