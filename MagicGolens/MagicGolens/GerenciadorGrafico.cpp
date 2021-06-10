#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEstado.h"
#include "Menu.h"

//Construtora e Destrutora

GerenciadorGrafico::GerenciadorGrafico() :
	janela(sf::VideoMode(1280, 720), "MagicGolens"),
	evento(),
	view(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(1920.0f, 1080.0f))
{
	GEstado = NULL;
	menu = NULL;
	LEntidades = NULL;
	GMapa = NULL;
	jogador = NULL;
	janela.setVerticalSyncEnabled(1);
	janela.setFramerateLimit(50);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	GEstado = NULL;
	menu = NULL;
	LEntidades = NULL;
	GMapa = NULL;
	jogador = NULL;
}

//Funcoes

void GerenciadorGrafico::desenhar()
{
	if (GEstado->menuAtivo())
	{
		janela.setView(janela.getDefaultView());
		menu->desenhar();
	}
	else
	{
		GMapa->desenhar();
		atualizaView();
		LEntidades->desenhar();
	}
}

void GerenciadorGrafico::setListaEntidades(ListaEntidades* L)
{
	LEntidades = L;
}

void GerenciadorGrafico::setMenu(Menu* m)
{
	if (m != NULL)
		menu = m;
	else
	{
		cout << "ERRO: Gerenciador grafico nao recebeu menu corretamente" << endl;
		exit(823);
	}
}

void GerenciadorGrafico::fecharJanela()
{
	janela.close();
}

void GerenciadorGrafico::limpar()
{
	janela.clear();
}

void GerenciadorGrafico::renderizar()
{
	janela.display();
}

void GerenciadorGrafico::setGerenciadorEstado(GerenciadorEstado* Ge)
{
	if (Ge != NULL)
		GEstado = Ge;
	else
	{
		cout << "Gerenciador grafico nao recebeu o gerenciador estado corretamente" << endl;
	}
}

void GerenciadorGrafico::setEvento()
{
	if (janela.pollEvent(evento))
	{
		if (clickX())
			fecharJanela();

		if (GEstado->menuAtivo())
		{
			menu->atualizar(evento);
		}
		else
		{
			switch (evento.type)
			{
			case sf::Event::KeyReleased:
				switch (evento.key.code)
				{
				case sf::Keyboard::Escape:
					GEstado->setMenuStatus(true);
					break;
				}
			}
		}
	}
}

bool GerenciadorGrafico::janelaExecutando()
{
	return janela.isOpen();
}

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
	return &janela;
}

bool GerenciadorGrafico::clickX()
{
	if (evento.type == sf::Event::Closed)
	{
		return true;
	}
	else
		return false;
}

void GerenciadorGrafico::setGerenciadorMapa(GerenciadorMapa* Gm) {
	GMapa = Gm;
}

void GerenciadorGrafico::setJogador(Jogador* jog) {
	jogador = jog;
}

void GerenciadorGrafico::atualizaView()
{
	sf::Vector2f posicao_view = jogador->getPosicao();

	float x = posicao_view.x;
	float y = posicao_view.y;

	x = std::floorf(x);
	y = std::floorf(y);

	x += 0.375f;
	y += 0.375f;

	view.setCenter(x, y);

	if ((posicao_view.x - 1920 / 2) < 0)
		view.move(sf::Vector2f((-1) * (posicao_view.x - 1920 / 2), 0.f));

	if ((posicao_view.x + 1920 / 2) > 2880)
		view.move(sf::Vector2f(2880 - (posicao_view.x + 1920 / 2), 0.f));

	if ((posicao_view.y - 1080 / 2) < 0)
		view.move(sf::Vector2f(0.f, (-1) * (posicao_view.y - 1080 / 2)));

	if ((posicao_view.y + 1080 / 2) > 2880)
		view.move(sf::Vector2f(0.f, 2880 - (posicao_view.y + 1080 / 2)));

	janela.setView(view);
}