#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"
#include "GerenciadorEstado.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "Mago.h"
#include "Anjo.h"
#include "FasePedra.h"
#include "FaseFogo.h"
#include "FaseGelo.h"
#include "MenuInicial.h"

class Jogo
{
private:

	//Gerenciadores
	GerenciadorGrafico GerenciadorGrafico;
	GerenciadorAtualizacoes GerenciadorAtualizacoes;
	GerenciadorEstado GerenciadorEstado;
	GerenciadorColisoes GerenciadorColisoes;

	//Menu
	MenuInicial menu;

	//Entidades
	Jogador* jogador1;
	Jogador* jogador2;

	//Fases
	FasePedra fasePedra;
	FaseFogo faseFogo;
	FaseGelo faseGelo;

public:

	//Construtora e Destrutora
	Jogo();
	~Jogo();

	//Funcoes
	void executarJogo();
	void inicializarGerenciadores();
	void inicializarFases();
};
