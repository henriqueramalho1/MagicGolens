#include "stdafx.h"
#include "FasePedra.h"

FasePedra::FasePedra(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j) :
	Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto, t, j, 1)
{
}

FasePedra::~FasePedra()
{
	if (jogador1 != NULL)
	{
		LEntidades->removerEntidade(jogador1);
	}

	if (jogador2 != NULL)
	{
		LEntidades->removerEntidade(jogador2);
	}

	if (!LEntidades->getVaziaStatus())
		LEntidades->destruirEntidades();

	delete LEntidades;
	delete mapaTiles[0];
	delete mapaTiles[1];
	delete mapaTiles[2];
	delete mapaTiles[3];
}

void FasePedra::setPosicaoJogadores()
{
	jogador1->reiniciar();
	jogador1->setPosicao(sf::Vector2f(3.5 * 96.f, 27 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->reiniciar();
		jogador2->setPosicao(sf::Vector2f(3.5 * 96.f, 27 * 96.f));
	}
}

const sf::Vector2f FasePedra::getPontoFinal() const
{
	return pontoFinal;
}

void FasePedra::criarInimigos()
{
	int qntd = rand() % 3 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 2400 + 200);
		float py = static_cast<float>(rand() % 2400 + 200);

		GolemPedra* pGolemPedra = new GolemPedra(golemPedra, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(50.f, 0.f), "text/golemPedrav2.png", dt, janela);
		LEntidades->incluirEntidade(pGolemPedra);
		GColisoes->adicionarEntidade(pGolemPedra);
	}

	qntd = rand() % 3 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 2500 + 200);
		float py = static_cast<float>(rand() % 2400 + 200);

		GolemFogo* pGolemFogo = new GolemFogo(golemFogo, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(120.f, 0.f), "text/golemFogov2.png", dt, janela);
		LEntidades->incluirEntidade(pGolemFogo);
		GColisoes->adicionarEntidade(pGolemFogo);
	}
}

void FasePedra::criarObstaculos()
{
	int qntd;
	float px;

	qntd = rand() % 5 + 2;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 768);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(576.f + px, 1920.3f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitepedra.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}

	qntd = rand() % 5 + 2;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 1152);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(1440.f + px, 1248.3f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitepedra.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}

	qntd = rand() % 5 + 2;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 1248);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(864.f + px, 672.3f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitepedra.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}
}

void FasePedra::inicializarTiles(const char* caminhoTile)
{
	Tile* pTile = NULL;

	pTile = new Areia(areia, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[1] = pTile;
}



void FasePedra::recuperarEntes()
{
	ifstream Carregador("salvar/GolemPedra.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar golem pedra" << endl;
		exit(24315123);
	}

	GolemPedra* pGoPe;
	sf::Vector2f posicao, velocidade, dimensoes;
	bool viradoDir, caindo;
	int hp, nivel;
	float crescimento, cura, aceleracao;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir >> hp >> nivel >> crescimento >> cura;

		pGoPe = new GolemPedra(golemPedra, dimensoes, posicao, velocidade, "text/golemPedrav2.png", dt, janela);
		pGoPe->setViradoDir(viradoDir);
		pGoPe->setHP(hp);
		pGoPe->setNivel(nivel);
		pGoPe->setCrescimento(crescimento);
		pGoPe->setCura(cura);

		LEntidades->incluirEntidade(pGoPe);
		GColisoes->adicionarEntidade(pGoPe);
	}
	Carregador.close();

	Carregador.open("salvar/GolemFogo.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar golem fogoooo" << endl;
		exit(24315123);
	}
	GolemFogo* pGoFo;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir >> hp >> nivel >> aceleracao;
		
		pGoFo = new GolemFogo(golemFogo, dimensoes, posicao, velocidade, "text/golemFogov2.png", dt, janela);
		pGoFo->setViradoDir(viradoDir);
		pGoFo->setHP(hp);
		pGoFo->setNivel(nivel);
		pGoFo->setAceleracao(aceleracao);
		LEntidades->incluirEntidade(pGoFo);
		GColisoes->adicionarEntidade(pGoFo);
	}
	Carregador.close();


	Carregador.open("salvar/Orbe.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar orbes" << endl;
		exit(24315123);
	}
	Orbe* pOrbe;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir;

		pOrbe = new Orbe(orb, dimensoes, posicao, velocidade, "text/orbe.png", dt, janela);
		pOrbe->setViradoDir(viradoDir);
		LEntidades->incluirEntidade(pOrbe);
		GColisoes->adicionarEntidade(pOrbe);
	}
	Carregador.close();


	Carregador.open("salvar/Estalactite.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar estalactite" << endl;
		exit(24315123);
	}
	Estalactite* pEstal;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir >> caindo;

		if(jogador2 != NULL)
			pEstal = new Estalactite(estalactite, dimensoes, posicao, velocidade, "text/estalactitepedra.png", dt, janela, jogador1, jogador2);
		else
			pEstal = new Estalactite(estalactite, dimensoes, posicao, velocidade, "text/estalactitepedra.png", dt, janela, jogador1, NULL);

		pEstal->setCaindo(caindo);
		LEntidades->incluirEntidade(pEstal);
		GColisoes->adicionarEntidade(pEstal);
	}
	Carregador.close();

}
