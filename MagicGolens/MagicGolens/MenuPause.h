#pragma once
#include "Menu.h"
#include "stdafx.h"

class GerenciadorEstado;
class GerenciadorGrafico;
class MenuInicial;

class MenuPause :
	public Menu
{
private:

	sf::Text opcoes[3];
	MenuInicial* MenuIni;

public:

	//Construtora e Destrutora
	MenuPause(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground = "", sf::RenderWindow* j = NULL);
	~MenuPause();

	//Funcoes
	void inicializarMenu();
	void moverCima();
	void moverBaixo();
	void desenhar();
	void executarEnter();
	void atualizar(sf::Event evento);
	void setMenuInicial(MenuInicial* m);
};
