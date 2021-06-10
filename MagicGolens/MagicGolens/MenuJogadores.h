#pragma once
#include "Menu.h"
#include "stdafx.h"

class MenuInicial;

class MenuJogadores :
    public Menu
{
private:

    sf::Text opcoes[3];
    MenuInicial* MenuIni;

public:

    //Construtora e Destrutora
    MenuJogadores(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL, string caminhoBackground = "", sf::RenderWindow* j = NULL);
    ~MenuJogadores();

    //Funcoes
    void inicializarMenu();
    void desenhar();
    void moverCima();
    void moverBaixo();
    void executarEnter();
    void setMenuInicial(MenuInicial* m);
};

