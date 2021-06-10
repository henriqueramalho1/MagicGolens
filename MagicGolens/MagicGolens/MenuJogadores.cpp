#include "stdafx.h"
#include "MenuJogadores.h"
#include "MenuInicial.h"

MenuJogadores::MenuJogadores(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground, sf::RenderWindow* j):
Menu(Ge, Gg, caminhoBackground, j),
opcoes(),
MenuIni()
{
	MenuIni = NULL;
	inicializarMenu();
}

MenuJogadores::~MenuJogadores()
{
}

void MenuJogadores::inicializarMenu()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color(0, 144, 150));
	opcoes[0].setString("1 Jogador");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 3));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("2 Jogadores");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 4));

	opcoes[2].setFont(fonte);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setString("Voltar");
	opcoes[2].setOrigin(opcoes[2].getLocalBounds().width / 2, opcoes[2].getLocalBounds().height / 2);
	opcoes[2].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 5));

}

void MenuJogadores::desenhar()
{
	janela->draw(background);

	for (int i = 0; i < 3; i++)
	{
		janela->draw(opcoes[i]);
	}
}

void MenuJogadores::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuJogadores::moverBaixo()
{
	if (itemSelecionado + 1 <= 2)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuJogadores::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		GGrafico->setMenu(MenuIni->getMenuFases());
		GEstado->setCoop(false);
		break;

	case 1:
		GGrafico->setMenu(MenuIni->getMenuFases());
		GEstado->setCoop(true);
		break;

	case 2:
		GGrafico->setMenu(MenuIni);
		break;
	}
}

void MenuJogadores::setMenuInicial(MenuInicial* m)
{
	MenuIni = m;
}
