#include "stdafx.h"
#include "FaseGelo.h"
#include "Mago.h"

FaseGelo::FaseGelo(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j) :
	Fase(caminhoTile, caminhoMapa, caminhoBackground, ponto, t, j, 3)
{
}

FaseGelo::~FaseGelo()
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

void FaseGelo::setPosicaoJogadores()
{
	jogador1->reiniciar();
	jogador1->setPosicao(sf::Vector2f(3.5 * 96.f, 5 * 96.f));

	if (jogador2 != NULL)
	{
		jogador2->reiniciar();
		jogador2->setPosicao(sf::Vector2f(3.5 * 96.f, 5 * 96.f));
	}
}

const sf::Vector2f FaseGelo::getPontoFinal() const
{
	return pontoFinal;
}

void FaseGelo::criarInimigos()
{
	int qntd = rand() % 3 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 2400 + 200);
		float py = static_cast<float>(rand() % 2400 + 200);

		GolemGelo* pGolemGelo = new GolemGelo(golemGelo, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(80.f, 80.f), "text/golemGelov2.png", dt, janela);
		LEntidades->incluirEntidade(pGolemGelo);
		GColisoes->adicionarEntidade(pGolemGelo);
		pGolemGelo->setListaEntidades(LEntidades);
		pGolemGelo->setGerenciadorColisoes(GColisoes);
	}

	qntd = rand() % 3 + 5;

	for (int i = 0; i < qntd; i++)
	{
		float px = static_cast<float>(rand() % 2400 + 200);
		float py = static_cast<float>(rand() % 2400 + 200);

		GolemPedra* pGolemPedra = new GolemPedra(golemPedra, sf::Vector2f(96.f, 144.f), sf::Vector2f(px, py), sf::Vector2f(50.f, 50.f), "text/golemPedrav2.png", dt, janela);
		LEntidades->incluirEntidade(pGolemPedra);
		GColisoes->adicionarEntidade(pGolemPedra);
	}

	Chefao* pChefao = new Chefao(boss, sf::Vector2f(288.f, 432.f), sf::Vector2f(1920.f, 2060.f), sf::Vector2f(0.f, 0.f), "text/golemGelov2.png", dt, janela, 3.f);
	LEntidades->incluirEntidade(pChefao);
	GColisoes->adicionarEntidade(pChefao);
	pChefao->setListaEntidades(LEntidades);
	pChefao->setGerenciadorColisoes(GColisoes);
}

void FaseGelo::criarObstaculos()
{
	int qntd;
	float px;

	qntd = rand() % 5 + 2;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 288);
		Estalactite* pEst = NULL;
		pEst= new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(2208.f + px, 96.5f + 100/2.f), sf::Vector2f(0.f, 0.f), "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}

	qntd = rand() % 5 + 2;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 384);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(192.f + px, 672.5f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}

	qntd = rand() % 5 + 2;

	for (int i = 1; i <= qntd; i++)
	{
		px = static_cast<float>(rand() % 864);
		Estalactite* pEst = NULL;
		pEst = new Estalactite(estalactite, sf::Vector2f(40.f, 100.f), sf::Vector2f(1900.f + px, 1824.5f + 100 / 2.f), sf::Vector2f(0.f, 0.f), "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		LEntidades->incluirEntidade(pEst);
		GColisoes->adicionarEntidade(pEst);
	}
}

void FaseGelo::inicializarTiles(const char* caminhoTile)
{
	Tile* pTile = NULL;

	pTile = new Espinho(espinho, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[1] = pTile;
}


void FaseGelo::recuperarEntes()
{
	ifstream Carregador("salvar/GolemPedra.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar golem pedra" << endl;
		exit(24315123);
	}

	GolemPedra* pGoPe;
	sf::Vector2f posicao, velocidade, dimensoes;
	bool viradoDir, caindo, podeAtirar;
	int hp, nivel;
	float crescimento, cura, limite, cooldown, tamanhoCristal;

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

	Carregador.open("salvar/GolemGelo.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar golem fogoooo" << endl;
		exit(24315123);
	}
	GolemGelo* pGoGe;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir >> hp >> nivel >> limite >> cooldown >> podeAtirar >> tamanhoCristal;

		pGoGe = new GolemGelo(golemGelo, dimensoes, posicao, velocidade, "text/golemGelov2.png", dt, janela, tamanhoCristal);
		pGoGe->setViradoDir(viradoDir);
		pGoGe->setHP(hp);
		pGoGe->setNivel(nivel);
		pGoGe->setLimite(limite);
		pGoGe->setCooldown(cooldown);
		pGoGe->setPodeAtir(podeAtirar);
		pGoGe->setTamanhoCristal(tamanhoCristal);
		pGoGe->setListaEntidades(LEntidades);
		pGoGe->setGerenciadorColisoes(GColisoes);
		LEntidades->incluirEntidade(pGoGe);
		GColisoes->adicionarEntidade(pGoGe);
		
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


	Carregador.open("salvar/CristalGelo.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar cristaisgelo" << endl;
		exit(24315123);
	}
	CristalGelo* pCrGe;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir;

		pCrGe = new CristalGelo(cristal, dimensoes, posicao, velocidade, "text/cristal.png", dt, janela);
		pCrGe->setViradoDir(viradoDir);
		LEntidades->incluirEntidade(pCrGe);
		GColisoes->adicionarEntidade(pCrGe);
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

		if (jogador2 != NULL)
			pEstal = new Estalactite(estalactite, dimensoes, posicao, velocidade, "text/estalactitegelo.png", dt, janela, jogador1, jogador2);
		else
			pEstal = new Estalactite(estalactite, dimensoes, posicao, velocidade, "text/estalactitegelo.png", dt, janela, jogador1, NULL);

		pEstal->setCaindo(caindo);
		LEntidades->incluirEntidade(pEstal);
		GColisoes->adicionarEntidade(pEstal);
	}
	Carregador.close();


	Carregador.open("salvar/Chefao.txt", ios::in);
	if (!Carregador) {
		cerr << "Incapaz de recuperar chefaoo" << endl;
		exit(24315123);
	}
	Chefao* pChe;

	while (!Carregador.eof())
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y
			>> dimensoes.x >> dimensoes.y >> viradoDir >> hp >> nivel >> limite >> cooldown >> podeAtirar >> tamanhoCristal;

		pChe = new Chefao(boss, dimensoes, posicao, velocidade, "text/golemGelov2.png", dt, janela, tamanhoCristal);
		if(!viradoDir)
			pChe->setViradoDir(viradoDir);
		else
			pChe->setViradoDir(!viradoDir);
		pChe->setHP(hp);
		pChe->setNivel(nivel);
		pChe->setLimite(limite);
		pChe->setCooldown(cooldown);
		pChe->setPodeAtir(podeAtirar);
		pChe->setTamanhoCristal(tamanhoCristal);
		pChe->setListaEntidades(LEntidades);
		pChe->setGerenciadorColisoes(GColisoes);
		LEntidades->incluirEntidade(pChe);
		GColisoes->adicionarEntidade(pChe);

	}
	Carregador.close();

}