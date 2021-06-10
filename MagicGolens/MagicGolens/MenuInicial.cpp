#include "stdafx.h"
#include "MenuInicial.h"

MenuInicial::MenuInicial(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground, sf::RenderWindow* j) :
	Menu(Ge, Gg, caminhoBackground, j),
	opcoes(),
	MFases(Ge, Gg, caminhoBackground, j),
	MPause(Ge, Gg, caminhoBackground, j),
	MJogadores(Ge, Gg, caminhoBackground, j),
	MLeaderboard(Ge, Gg, caminhoBackground, j)
{
	inicializarMenu();
	MFases.setMenuInicial(this);
	MPause.setMenuInicial(this);
	MJogadores.setMenuInicial(this);
	MLeaderboard.setMenuInicial(this);
}

MenuInicial::~MenuInicial()
{
}

void MenuInicial::inicializarMenu()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color(0, 144, 150));
	opcoes[0].setString("Jogar");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 3));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("Carregar Jogada");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 4));

	opcoes[2].setFont(fonte);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setString("Sair");
	opcoes[2].setOrigin(opcoes[2].getLocalBounds().width / 2, opcoes[2].getLocalBounds().height / 2);
	opcoes[2].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 6));
}

void MenuInicial::desenhar()
{
	janela->draw(background);

	for (int i = 0; i < 3; i++)
	{
		janela->draw(opcoes[i]);
	}
}

void MenuInicial::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuInicial::moverBaixo()
{
	if (itemSelecionado + 1 <= 2)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuInicial::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		GGrafico->setMenu(&MJogadores);
		break;

	case 2:
		GGrafico->fecharJanela();
		break;

	case 1:
		GGrafico->setMenu(&MPause);
		GEstado->inicializaFaseSalvada();
		break;

	}
}

Menu* MenuInicial::getMenuPause()
{
	return &MPause;
}

Menu* MenuInicial::getMenuFases()
{
	return &MFases;
}

Menu* MenuInicial::getMenuJogadores()
{
	return &MJogadores;
}

Leaderboard* MenuInicial::getLeaderboard()
{
	return &MLeaderboard;
}
