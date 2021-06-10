#include "stdafx.h"
#include "Menu.h"
#include "GerenciadorGrafico.h"

Menu::Menu(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground, sf::RenderWindow* j) :
	textura(),
	background(),
	fonte(),
	itemSelecionado(0)
{
	GEstado = Ge;
	GGrafico = Gg;
	textura.loadFromFile(caminhoBackground);
	background.setTexture(textura);
	background.setScale(sf::Vector2f(2 / 3.f, 2 / 3.f));
	janela = j;
}

Menu::~Menu()
{
}

void Menu::atualizar(sf::Event evento)
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
		}
	}
}
