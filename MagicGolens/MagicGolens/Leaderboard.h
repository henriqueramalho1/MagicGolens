#pragma once
#include "Menu.h"
#include "Textbox.h"
#include <fstream>
#include <map>

class MenuInicial;

class Leaderboard :
    public Menu

{
private:

    vector<pair<string, float>> ranking;
    sf::Text opcoes[2];
    sf::Text leader[5];
    sf::Text posicoes[5];
    sf::Text pontuacoes[5];
    Textbox textbox;
    MenuInicial* MenuIni;
    Jogador* j1;
    Jogador* j2;
    bool nomeCadastrado;

public:

    //Construtora e Destrutora
    Leaderboard(GerenciadorEstado* Ge = NULL, GerenciadorGrafico* Gg = NULL, string caminhoBackground = "", sf::RenderWindow* j = NULL);
    ~Leaderboard();

    //Funcoes
    void inicializarLeaderboard();
    void inicializarRanking();
    void inicializarNomes();
    void inicializarPosicoes();
    void inicializarPontuacoes();
    void moverCima();
    void moverBaixo();
    void desenhar();
    void executarEnter();
    void atualizar(sf::Event evento);
    void setMenuInicial(MenuInicial* m);
    void setNomeCadastrado(bool b);
    void setJogadores(Jogador* jog1, Jogador* jog2);
    void adicionarPontuacao(string nome1, float pontuacao1);
    void atualizarRanking();
    void ordenaRanking(vector<pair<string, float>> &vetor);
    void salvarPontuacao();
    void carregarPontuacao();
    void reiniciarEscrita();
    void reiniciarPontuacoesJogadores();
};