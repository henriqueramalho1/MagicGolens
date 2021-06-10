#pragma once
#include "stdafx.h"
#include "ListaEntidades.h"
#include "Menu.h"
#include "GerenciadorMapa.h"
#include "Jogador.h"
using namespace IdsCol;

class Menu;
class GerenciadorEstado;

class GerenciadorGrafico
{
private:

	GerenciadorEstado* GEstado;
	GerenciadorMapa* GMapa;
	sf::RenderWindow janela;
	sf::Event evento;
	Menu* menu;
	ListaEntidades* LEntidades;
	sf::View view;
	Jogador* jogador;

public:

	//Construtora e Destrutora
	GerenciadorGrafico();
	~GerenciadorGrafico();

	//Funcoes
	void desenhar();
	void limpar();
	void renderizar();
	void setGerenciadorEstado(GerenciadorEstado* Ge);
	void setListaEntidades(ListaEntidades* L);
	void setGerenciadorMapa(GerenciadorMapa* Gm);
	void setMenu(Menu* m);
	void fecharJanela();
	void setEvento();
	bool janelaExecutando();
	sf::RenderWindow* getJanela();
	bool clickX();
	void setJogador(Jogador* jog);
	void atualizaView();
};
