#include "stdafx.h"
#include "Fase.h"

Fase::Fase(const char* caminhoTile, const char* caminhoMapa, const char* caminhoBackground, sf::Vector2f ponto, float* t, sf::RenderWindow* j, int nF) :
	LEntidades(),
	statusConcluida(false),
	pontoFinal(ponto),
	mapaTiles(),
	numFase(nF)
{
	dt = t;
	janela = j;
	jogador1 = NULL;
	jogador2 = NULL;
	GColisoes = NULL;
	LEntidades = new ListaEntidades();
	pGm = NULL;
	pMapa = NULL;

	try {
		this->caminhoTile = caminhoTile;

		if (caminhoTile == NULL)
			throw 32;
	}
	catch (int x)
	{
		if(x == 32)
		cout << "CaminhoTile == NULL" << endl;
		exit(10);
	}

	this->caminhoMapa = caminhoMapa;
	this->caminhoBackground = caminhoBackground;
}

Fase::~Fase()
{
	delete (pMapa);
	pMapa = NULL;
	delete (pGm);
	pGm = NULL;
}

void Fase::criarMapa()
{
	Tile* pTile = NULL;

	pTile = new Bloco(bloco, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[0] = pTile;
	pTile = new Ar(naocolidivel, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[3] = pTile;
	pTile = new Porta(porta, sf::Vector2f(96.f, 96.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), caminhoTile, dt, janela);
	mapaTiles[2] = pTile;
	inicializarTiles(caminhoTile);

	pMapa = new Mapa(caminhoMapa);
	pGm = new GerenciadorMapa(mapaTiles, pMapa, janela);

	if (!backgroundText.loadFromFile(caminhoBackground)) {
		cout << "Erro, nao pode abrir a Textura" << endl;
		exit(404);
	}

	backgroundSpr.setTexture(backgroundText);
	backgroundSpr.setPosition(sf::Vector2f(0.f, 0.f));
	backgroundSpr.setScale(sf::Vector2f(1.f, 1.f));

	pGm->setBackground(&backgroundSpr);
}

void Fase::setJogadores(Jogador* j1, Jogador* j2)
{
	jogador1 = j1;
	jogador2 = j2;

	jogador1->setGerenciadorColisoes(GColisoes);
	jogador1->setListaEntidades(LEntidades);
	LEntidades->incluirEntidade(j1);

	if (jogador2 != NULL)
	{
		LEntidades->incluirEntidade(j2);
		jogador2->setGerenciadorColisoes(GColisoes);
		jogador2->setListaEntidades(LEntidades);
	}
}

void Fase::inicializarFase(Jogador* j1, Jogador* j2)
{
	setJogadores(j1, j2);

	jogador1->reiniciar();
	GColisoes->adicionarEntidade(jogador1);

	if (jogador2 != NULL)
	{
		j2->reiniciar();
		GColisoes->adicionarEntidade(j2);
	}

	GColisoes->setListaEntidades(LEntidades);
	criarObstaculos();
	criarInimigos();
	setPosicaoJogadores();
}

void Fase::reiniciarFase()
{
	statusConcluida = false;
	if (!LEntidades->getVaziaStatus())
	{

		jogador1->reiniciarTudo();
		LEntidades->removerEntidade(jogador1);

		if (jogador2 != NULL)
		{
			jogador2->reiniciarTudo();
			LEntidades->removerEntidade(jogador2);
		}

		jogador1 = NULL;
		jogador2 = NULL;


		if (!LEntidades->getVaziaStatus())
			LEntidades->destruirEntidades();
	}
}

void Fase::setConcluida(bool b)
{
	statusConcluida = b;
}

const bool Fase::getStatus() const
{
	return statusConcluida;
}

ListaEntidades* Fase::getListaEntidades()
{
	return LEntidades;
}

sf::Vector2f Fase::getPosicaoJogador() const
{
	return jogador1->getPosicao();
}

void Fase::setPosicaoJogadores(sf::Vector2f p1, sf::Vector2f p2)
{
	jogador1->reiniciar();
	jogador1->setPosicao(p1);

	if (jogador2 != NULL)
	{
		jogador2->reiniciar();
		jogador2->setPosicao(p2);
	}
}

const sf::Vector2f Fase::getPontoFinal() const
{
	return pontoFinal;
}

GerenciadorMapa* Fase::getGerenciadorMapa() 
{
	return pGm;
}

void Fase::setGerenciadorColisoes(GerenciadorColisoes* pg)
{
	GColisoes = pg;
}

bool Fase::jogadorMorto()
{
	if (!jogador1->estaVivo())
		return true;
	if (jogador2 != NULL)
		if (!jogador2->estaVivo())
			return true;

	return false;
}

void Fase::deletarTiles()
{
	Tile* pTile = NULL;
	for (auto iterador = mapaTiles.begin(); iterador != mapaTiles.end(); iterador++)
	{
		pTile = (*iterador).second;
		delete pTile;
	}

	mapaTiles.clear();
}

void Fase::salvar() 
{
	ofstream Gravador("salvar/Fase.txt", ios::trunc);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	if (jogador2 == NULL)
		Gravador << numFase << ' ' << 1;
	else
		Gravador << numFase << ' ' << 2;

	Gravador.close();

	LEntidades->salvar();
}

void Fase::inicializarFaseSalva(Jogador* j1, Jogador* j2)
{
	setJogadores(j1, j2);
	recuperarJogadores();


	jogador1->reiniciar();
	GColisoes->adicionarEntidade(jogador1);

	if (jogador2 != NULL)
	{
		j2->reiniciar();
		GColisoes->adicionarEntidade(j2);
	}

	GColisoes->setListaEntidades(LEntidades);
	recuperarEntes();

}


void Fase::recuperarJogadores()
{
	ifstream Carregador("salvar/Jogador.txt", ios::in);

	if (!Carregador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(67);
	}


	sf::Vector2f posicao, velocidade, dimensoes;
	bool viradoDir, podePular, congelado;
	int hp, penalidadeAnte, penalidadeAtual;
	float alturaPulo, tempoCongelamento, cooldownGelo, pontuacao;
	int vezesLoop = 2;
	if (jogador2 == NULL)
		vezesLoop = 1;

	Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> dimensoes.x >>
		dimensoes.y >> viradoDir >> hp >> podePular >> alturaPulo >> tempoCongelamento >>
		congelado >> cooldownGelo >> penalidadeAnte >> penalidadeAtual >> pontuacao;

	jogador1->carregar(posicao, velocidade, dimensoes, viradoDir, podePular, congelado, hp, penalidadeAnte, penalidadeAtual, alturaPulo, tempoCongelamento, cooldownGelo, pontuacao);

	if (jogador2 != NULL) 
	{
		Carregador >> posicao.x >> posicao.y >> velocidade.x >> velocidade.y >> dimensoes.x >>
			dimensoes.y >> viradoDir >> hp >> podePular >> alturaPulo >> tempoCongelamento >>
			congelado >> cooldownGelo >> penalidadeAnte >> penalidadeAtual >> pontuacao;

		jogador2->carregar(posicao, velocidade, dimensoes, viradoDir, podePular, congelado, hp, penalidadeAnte, penalidadeAtual, alturaPulo, tempoCongelamento, cooldownGelo, pontuacao);
	}

	Carregador.close();

}

