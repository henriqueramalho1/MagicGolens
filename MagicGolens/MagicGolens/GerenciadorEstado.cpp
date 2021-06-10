#include "stdafx.h"
#include "GerenciadorEstado.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorAtualizacoes.h"
#include "MenuInicial.h"

GerenciadorEstado::GerenciadorEstado() :
	bFase1(false),
	bFase2(false),
	bFase3(false),
	bMenu(true),
	coop(false)
{
	GGrafico = NULL;
	GAtualizacoes = NULL;
	GColisoes = NULL;
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
	menu = NULL;
	jogador1 = NULL;
	jogador2 = NULL;
}

GerenciadorEstado::~GerenciadorEstado()
{
	GGrafico = NULL;
	GAtualizacoes = NULL;
	GColisoes = NULL;
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
	menu = NULL;
	jogador1 = NULL;
	jogador2 = NULL;
}

void GerenciadorEstado::inicializarFase1()
{
	if (coop)
		fase1->inicializarFase(jogador1, jogador2);
	else
	{
		fase1->inicializarFase(jogador1, NULL);
	}

	GGrafico->setListaEntidades(fase1->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase1->getGerenciadorMapa());
	GColisoes->setGerenciadorMapa(fase1->getGerenciadorMapa());
	GAtualizacoes->setFase(fase1);
	GAtualizacoes->setListaEntidades(fase1->getListaEntidades());
	bMenu = false;
	bFase1 = true;
	bFase2 = false;
	bFase3 = false;
}

void GerenciadorEstado::inicializarFase2()
{
	if (coop)
		fase2->inicializarFase(jogador1, jogador2);
	else
		fase2->inicializarFase(jogador1, NULL);

	GGrafico->setListaEntidades(fase2->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase2->getGerenciadorMapa());
	GColisoes->setGerenciadorMapa(fase2->getGerenciadorMapa());
	GAtualizacoes->setFase(fase2);
	GAtualizacoes->setListaEntidades(fase2->getListaEntidades());
	bMenu = false;
	bFase1 = false;
	bFase2 = true;
	bFase3 = false;
}

void GerenciadorEstado::inicializarFase3()
{
	if (coop)
		fase3->inicializarFase(jogador1, jogador2);
	else
		fase3->inicializarFase(jogador1, NULL);

	GGrafico->setListaEntidades(fase3->getListaEntidades());
	GGrafico->setGerenciadorMapa(fase3->getGerenciadorMapa());
	GColisoes->setGerenciadorMapa(fase3->getGerenciadorMapa());
	GAtualizacoes->setListaEntidades(fase3->getListaEntidades());
	GAtualizacoes->setFase(fase3);
	bMenu = false;
	bFase1 = false;
	bFase2 = false;
	bFase3 = true;
}

void GerenciadorEstado::reiniciarFases()
{
	fase1->reiniciarFase();
	fase2->reiniciarFase();
	fase3->reiniciarFase();
}

void GerenciadorEstado::esvaziarGColisoes()
{
	GColisoes->esvaziar();
}

void GerenciadorEstado::setFases(Fase* f1, Fase* f2, Fase* f3)
{
	fase1 = f1;
	fase2 = f2;
	fase3 = f3;
}

void GerenciadorEstado::setGerenciadores(GerenciadorGrafico* Gg, GerenciadorAtualizacoes* Ga, GerenciadorColisoes* Gc)
{
	if (Gg != NULL && Ga != NULL && Gc != NULL)
	{
		GGrafico = Gg;
		GAtualizacoes = Ga;
		GColisoes = Gc;
	}
	else
	{
		cout << "ERRO: Gerenciador de estados nao conseguiu receber os gerenciadores de forma correta" << endl;
		exit(432);
	}
}

void GerenciadorEstado::setJogadores(Jogador* j1, Jogador* j2)
{
	jogador1 = j1;
	jogador2 = j2;
}

void GerenciadorEstado::verificaEstado()
{
	if (bMenu)
	{
	}
	else if (bFase1)
	{
		if (fase1->getStatus())
		{
			bFase1 = false;
			bFase2 = false;
			bFase3 = false;
			GColisoes->esvaziar();
			inicializarFase2();
		}
	}
	else if (bFase2)
	{
		if (fase2->getStatus())
		{
			bFase2 = false;
			bFase1 = false;
			bMenu = false;
			GColisoes->esvaziar();
			inicializarFase3();
		}
	}
	else if (bFase3)
	{
		if (fase3->getStatus())
		{
			bFase1 = false;
			bFase2 = false;
			bFase3 = false;
			bMenu = true;
			if (coop)
			{
				menu->getLeaderboard()->setJogadores(jogador1, jogador2);
				GGrafico->setMenu(menu->getLeaderboard());
			}
			else
			{
				menu->getLeaderboard()->setJogadores(jogador1, NULL);
				GGrafico->setMenu(menu->getLeaderboard());
			}

			GColisoes->esvaziar();
			reiniciarFases();
		}
	}
}

void GerenciadorEstado::setMenu(MenuInicial* m)
{
	if (m != NULL)
	{
		menu = m;
	}
	else
	{
		cout << "ERRO: GerenciadorEstado nao recebeu menu corretamente" << endl;
	}
}

bool GerenciadorEstado::menuAtivo() const
{
	return bMenu;
}

void GerenciadorEstado::setMenuStatus(bool b)
{
	bMenu = b;
}

void GerenciadorEstado::setCoop(bool b)
{
	coop = b;
}

//new

void GerenciadorEstado::salvarJogada()
{
	if (bFase1)
		fase1->salvar();
	else if (bFase2)
		fase2->salvar();
	else if (bFase3)
		fase3->salvar();
}


void GerenciadorEstado::inicializaFaseSalvada()
{
	ifstream Carregador("salvar/Fase.txt", ios::in);
	int nfase;
	int nplayers;

	if (!Carregador) {
		cerr << "nao foi possivel abrir fase.txt" << endl;
		exit(001);
	}

	Carregador >> nfase >> nplayers;

	switch (nfase)
	{
	case 1:
		if (nplayers == 2)
			fase1->inicializarFaseSalva(jogador1, jogador2);
		else
			fase1->inicializarFaseSalva(jogador1, NULL);

		GGrafico->setListaEntidades(fase1->getListaEntidades());
		GGrafico->setGerenciadorMapa(fase1->getGerenciadorMapa());
		GColisoes->setGerenciadorMapa(fase1->getGerenciadorMapa());
		GAtualizacoes->setFase(fase1);
		GAtualizacoes->setListaEntidades(fase1->getListaEntidades());

		bFase1 = true;
		break;
	
	case 2:
		if (nplayers == 2)
			fase2->inicializarFaseSalva(jogador1, jogador2);
		else
			fase2->inicializarFaseSalva(jogador1, NULL);

		GGrafico->setListaEntidades(fase2->getListaEntidades());
		GGrafico->setGerenciadorMapa(fase2->getGerenciadorMapa());
		GColisoes->setGerenciadorMapa(fase2->getGerenciadorMapa());
		GAtualizacoes->setFase(fase2);
		GAtualizacoes->setListaEntidades(fase2->getListaEntidades());

		bFase2 = true;
		break;

	case 3:
		if (nplayers == 2)
			fase3->inicializarFaseSalva(jogador1, jogador2);
		else
			fase3->inicializarFaseSalva(jogador1, NULL);

		GGrafico->setListaEntidades(fase3->getListaEntidades());
		GGrafico->setGerenciadorMapa(fase3->getGerenciadorMapa());
		GColisoes->setGerenciadorMapa(fase3->getGerenciadorMapa());
		GAtualizacoes->setFase(fase3);
		GAtualizacoes->setListaEntidades(fase3->getListaEntidades());

		bFase3 = true;
		break;
	}


	bMenu = false;

}
