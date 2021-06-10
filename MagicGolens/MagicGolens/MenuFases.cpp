#include "stdafx.h"
#include "MenuFases.h"
#include "MenuInicial.h"

MenuFases::MenuFases(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground, sf::RenderWindow* j) :
	Menu(Ge, Gg, caminhoBackground, j),
	opcoes()
{
	MenuIni = NULL;
	inicializarMenu();
}

MenuFases::~MenuFases()
{
}

void MenuFases::inicializarMenu()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color(0, 144, 150));
	opcoes[0].setString("Fase 1");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 3));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("Fase 2");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 4));

	opcoes[2].setFont(fonte);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setString("Fase 3");
	opcoes[2].setOrigin(opcoes[2].getLocalBounds().width / 2, opcoes[2].getLocalBounds().height / 2);
	opcoes[2].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 5));

	opcoes[3].setFont(fonte);
	opcoes[3].setFillColor(sf::Color::White);
	opcoes[3].setString("Voltar");
	opcoes[3].setOrigin(opcoes[3].getLocalBounds().width / 2, opcoes[3].getLocalBounds().height / 2);
	opcoes[3].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 6));
}

void MenuFases::desenhar()
{
	janela->draw(background);

	for (int i = 0; i < 4; i++)
	{
		janela->draw(opcoes[i]);
	}
}

void MenuFases::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuFases::moverBaixo()
{
	if (itemSelecionado + 1 <= 3)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuFases::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		GGrafico->setMenu(MenuIni->getMenuPause());
		GEstado->inicializarFase1();
		break;

	case 1:
		GGrafico->setMenu(MenuIni->getMenuPause());
		GEstado->inicializarFase2();
		break;

	case 2:
		GGrafico->setMenu(MenuIni->getMenuPause());
		GEstado->inicializarFase3();
		break;

	case 3:
		GGrafico->setMenu(MenuIni->getMenuJogadores());
		break;
	}
}

void MenuFases::setMenuInicial(MenuInicial* m)
{
	if (m != NULL)
	{
		MenuIni = m;
	}
	else
	{
		cout << "MenuFases nao recebeu devidamente o MenuInicial" << endl;
		exit(999);
	}
}