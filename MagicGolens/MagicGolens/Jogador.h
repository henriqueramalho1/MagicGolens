#pragma once
#include "Personagem.h"
#include "Orbe.h"
#include "Atirador.h"

class Jogador :
	public Personagem, public Atirador
{
protected:

	float lentidao;
	bool vivo;
	bool podePular;
	float alturaPulo;
	float tempoCongelamento;
	bool congelado;
	float cooldownGelo;
	sf::Texture texturaCongelado;
	float pontuacao;
	int penalidadeAtual;
	int penalidadeAnte;

public:

	//Construtora e Destrutora
	Jogador(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(60.f, 90.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL, string caminhoCongelado = NULL);
	~Jogador();

	//Funcoes
	virtual void atualizar() = 0;
	void desenhar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
	void morrer();
	bool estaVivo();
	void reiniciar();
	void reiniciarTudo();
	void setPulo(bool b);
	void congelar();
	void descongelado(float t);
	void salvar();
	void carregar(sf::Vector2f posicao, sf::Vector2f velocidade, sf::Vector2f dimensoes, bool viradoDir, bool podePular, bool congelado, int hp, int penalidadeAnte, int penalidadeAtual, float alturaPulo, float tempoCongelamento, float cooldownGelo, float pontuacao);
	void aumentaPenalidade();
	float getPontuacao();
	int getPenalidadeAtual();
	int getPenalidadeAnte();
	void reiniciarPontuacao();
};
