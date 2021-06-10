#include "stdafx.h"
#include "Jogo.h"

//Construtora e Destrutora

Jogo::Jogo() :
	GerenciadorEstado(),
	GerenciadorGrafico(),
	GerenciadorAtualizacoes(),
	GerenciadorColisoes(),
	menu(&GerenciadorEstado, &GerenciadorGrafico, "menu/menuBackground.png", GerenciadorGrafico.getJanela()),
	fasePedra("mapas/fase1/pedratiles.png", "mapas/fase1/mapa1Copy2.txt", "mapas/fase1/background_floresta.jpg", sf::Vector2f(1.5 * 96.f, 3 * 96.f), GerenciadorAtualizacoes.getTempo(), GerenciadorGrafico.getJanela()),
	faseFogo("mapas/fase2/firetiles.png", "mapas/fase2/mapa2Copy2.txt", "mapas/fase2/background_fogo.jpg", sf::Vector2f(27.5 * 96.f, 2.0 * 96.f), GerenciadorAtualizacoes.getTempo(), GerenciadorGrafico.getJanela()),
	faseGelo("mapas/fase3/icetiles.png", "mapas/fase3/mapa3Copy2.txt", "mapas/fase3/background_gelo.jpg", sf::Vector2f(28.5 * 96.f, 28.0 * 96.f), GerenciadorAtualizacoes.getTempo(), GerenciadorGrafico.getJanela())
{
	jogador1 = NULL;
	jogador2 = NULL;
	jogador1 = new Mago(jogador, sf::Vector2f(118.f, 144.f), sf::Vector2f(400.f, 400.f), sf::Vector2f(0.f, 0.f), "text/magov2.png", GerenciadorAtualizacoes.getTempo(), GerenciadorGrafico.getJanela(), "text/magov2congelado.png");
	jogador2 = new Anjo(jogador, sf::Vector2f(96.f, 144.f), sf::Vector2f(400.f, 400.f), sf::Vector2f(0.f, 0.f), "text/anjov2.png", GerenciadorAtualizacoes.getTempo(), GerenciadorGrafico.getJanela(), "text/anjov2congelado.png");
	inicializarGerenciadores();
	inicializarFases();
}

Jogo::~Jogo()
{
	delete jogador1;
	delete jogador2;
}

//Funcoes

void Jogo::executarJogo()
{
	srand(static_cast<unsigned int>(time(NULL)));

	while (GerenciadorGrafico.janelaExecutando())
	{
		GerenciadorEstado.verificaEstado();

		GerenciadorAtualizacoes.relogioRestart();

		GerenciadorGrafico.setEvento();

		GerenciadorGrafico.limpar();

		GerenciadorAtualizacoes.atualizar();

		if(!GerenciadorEstado.menuAtivo())
			GerenciadorColisoes.verificarColisoes();

		GerenciadorGrafico.desenhar();

		GerenciadorGrafico.renderizar();
	}
}

void Jogo::inicializarGerenciadores()
{
	//GerenciadorAtualizacoes
	GerenciadorAtualizacoes.setGerenciador(&GerenciadorEstado);

	//GerenciadorGrafico
	GerenciadorGrafico.setMenu(&menu);
	GerenciadorGrafico.setGerenciadorEstado(&GerenciadorEstado);
	GerenciadorGrafico.setJogador(jogador1);

	//GerenciadorEstado
	GerenciadorEstado.setMenu(&menu);
	GerenciadorEstado.setGerenciadores(&GerenciadorGrafico, &GerenciadorAtualizacoes, &GerenciadorColisoes);
	GerenciadorEstado.setFases(&fasePedra, &faseFogo, &faseGelo);
	GerenciadorEstado.setJogadores(jogador1, jogador2);
}

void Jogo::inicializarFases()
{
	fasePedra.setGerenciadorColisoes(&GerenciadorColisoes);
	faseFogo.setGerenciadorColisoes(&GerenciadorColisoes);
	faseGelo.setGerenciadorColisoes(&GerenciadorColisoes);

	fasePedra.criarMapa();
	faseFogo.criarMapa();
	faseGelo.criarMapa();
}