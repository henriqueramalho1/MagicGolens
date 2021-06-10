#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

class Estalactite :
    public Obstaculo
{
private:
    bool caindo;
    Jogador* j1;
    Jogador* j2;

public:

    //Construtora e Destrutora
    Estalactite(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 96.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL, Jogador* jog1 = NULL, Jogador* jog2 = NULL);
    ~Estalactite();

    //Funcoes
	void atualizar();
	void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
    void devoCair();
    void salvar();
    void setCaindo(bool ca);
};

