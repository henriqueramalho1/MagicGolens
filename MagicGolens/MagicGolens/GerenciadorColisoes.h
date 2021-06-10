#pragma once
#include "stdafx.h"
#include <set>
#include <list>
#include "GerenciadorMapa.h"
#include "Entidade.h"
#include "ListaEntidades.h"
using namespace IdsCol;

class Arremessavel;

class GerenciadorColisoes
{
private:

	set<Entidade*> lista;
	GerenciadorMapa* GMapa;
	ListaEntidades* LEntidades;

public:

	//Construtora e Destrutora
	GerenciadorColisoes();
	~GerenciadorColisoes();

	//Funcoes
	void setGerenciadorMapa(GerenciadorMapa* pGm);
	void setListaEntidades(ListaEntidades* lista);
	void adicionarEntidade(Entidade* e);
	void removerEntidade(Entidade* e);
	void limparEntidades();
	void esvaziar();
	void verificarColisoes();
	bool estaoColidindo(Entidade* e1, Entidade* e2);
	Entidade* operator[](int i);
	bool operator !();
};
