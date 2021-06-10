#include "stdafx.h"
#include "Atirador.h"

Atirador::Atirador(float t) :
	limite(t - 0.7f),
	podeAtirar(false),
	cooldown(0.f)
{
	LEntidades = NULL;
	GColisoes = NULL;
}

Atirador::~Atirador()
{
	LEntidades = NULL;
}

void Atirador::setListaEntidades(ListaEntidades* lista)
{
	LEntidades = lista;
}

void Atirador::setGerenciadorColisoes(GerenciadorColisoes* Gc)
{
	if (Gc != NULL)
	{
		GColisoes = Gc;
	}
}

void Atirador::possoAtirar(float t)
{
	if (t >= limite)
	{
		podeAtirar = true;
	}
}

void Atirador::setLimite(float lim)
{
	limite = lim;
}

void Atirador::setCooldown(float cool)
{
	cooldown = cool;
}

void Atirador::setPodeAtir(bool pode)
{
	podeAtirar = pode;
}
