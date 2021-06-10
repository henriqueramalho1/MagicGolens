#pragma once
#include "stdafx.h"
#include <sstream>

class Textbox

{
private:

	sf::Text textbox;
	sf::Font fonte;
	std::string text;
	bool selecionado;
	bool temLimite;
	bool nomeLido;
	int limite;
	sf::RenderWindow* janela;

public:

	//Construtora e Destrutora
	Textbox();
	Textbox(int tam, sf::Color cor, bool sel, sf::RenderWindow* j);
	~Textbox();

	//Funcoes
	void entrada(int tipoChar);
	void excluirUltimoCaracter();
	void setSelecionado(bool b);
	void finalizarRecebimento();
	bool estaSelecionado();
	bool nomeEnviado();
	string getString();
	void desenhar();
	void atualizaPosicao();
	void setColor(sf::Color cor);
	void receberNome(sf::Event e);
	void limpar();
	void setNomeEnviado(bool b);
};

