#pragma once
#include "Jogador.h"

class Anjo :
    public Jogador
{
private:


public:

    //Construtora e Destrutora
    Anjo(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(60.f, 90.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = NULL, float* t = NULL, sf::RenderWindow* j = NULL, string caminhoCongelado = NULL);
    ~Anjo();

    //Funcoes
    void atualizar();
};

