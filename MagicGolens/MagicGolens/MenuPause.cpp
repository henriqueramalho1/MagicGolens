#include "stdafx.h"
#include "MenuPause.h"
#include "GerenciadorEstado.h"
#include "GerenciadorGrafico.h"
#include "MenuInicial.h"

MenuPause::MenuPause(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground, sf::RenderWindow* j) :
	Menu(Ge, Gg, caminhoBackground, j),
	opcoes()
{
	MenuIni = NULL;
	inicializarMenu();
}

MenuPause::~MenuPause()
{
}

void MenuPause::inicializarMenu()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color(0, 144, 150));
	opcoes[0].setString("Voltar ao jogo");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 3));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("Salvar");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 4));

	opcoes[2].setFont(fonte);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setString("Menu principal");
	opcoes[2].setOrigin(opcoes[2].getLocalBounds().width / 2, opcoes[2].getLocalBounds().height / 2);
	opcoes[2].setPosition(sf::Vector2f(1280 / 2.f, 720 / 8 * 5));
}

void MenuPause::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuPause::moverBaixo()
{
	if (itemSelecionado + 1 <= 2)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void MenuPause::desenhar()
{
	janela->draw(background);

	for (int i = 0; i < 3; i++)
	{
		janela->draw(opcoes[i]);
	}
}

void MenuPause::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		GEstado->setMenuStatus(false);
		break;

	case 2:
		GGrafico->setMenu(MenuIni);
		GEstado->esvaziarGColisoes();
		GEstado->reiniciarFases();
		break;
	case 1:
		GEstado->salvarJogada();
		break;
	}
}

void MenuPause::atualizar(sf::Event evento)
{
	switch (evento.type)
	{
	case sf::Event::KeyReleased:
		switch (evento.key.code)
		{
		case sf::Keyboard::Up:
			moverCima();
			break;

		case sf::Keyboard::Down:
			moverBaixo();
			break;

		case sf::Keyboard::Return:
			executarEnter();
			break;

		case sf::Keyboard::Escape:
			GEstado->setMenuStatus(false);
		}
	}
}

void MenuPause::setMenuInicial(MenuInicial* m)
{
	if (m != NULL)
		MenuIni = m;
	else
	{
		cout << "ERRO: MenuPause nao recebeu devidamente o menu inicial" << endl;
		exit(890);
	}
}