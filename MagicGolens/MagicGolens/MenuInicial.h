#pragma once
#include"stdafx.h"
#include"Menu.h"
#include "GerenciadorGrafico.h"
#include "MenuFases.h"
#include "MenuPause.h"
#include "MenuJogadores.h"
#include "Leaderboard.h"

class MenuInicial :
	public Menu
{
private:

	sf::Text opcoes[3];
	MenuFases MFases;
	MenuPause MPause;
	MenuJogadores MJogadores;
	Leaderboard MLeaderboard;

public:
	//Construtora e Destrutora
	MenuInicial(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL, string caminhoBackground = "", sf::RenderWindow* j = NULL);
	~MenuInicial();

	//Funcoes
	void inicializarMenu();
	void desenhar();
	void moverCima();
	void moverBaixo();
	void executarEnter();
	Menu* getMenuPause();
	Menu* getMenuFases();
	Menu* getMenuJogadores();
	Leaderboard* getLeaderboard();
};
