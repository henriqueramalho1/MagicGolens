#pragma once
#include "Tile.h"

class Ar :
    public Tile
{
private:

public:

    //Construtora e Destrutora
    Ar(IdsColidiveis ID = standby, sf::Vector2f tam = sf::Vector2f(96.f, 96.f), sf::Vector2f p = sf::Vector2f(0.f, 0.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), string caminhoTextura = "", float* t = NULL, sf::RenderWindow* j = NULL);
    ~Ar();

    //Funcoes
    void colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e = NULL);
};

