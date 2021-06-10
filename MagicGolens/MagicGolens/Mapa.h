#pragma once
using namespace IdsCol;
class Mapa
{
private:

	sf::Vector2i mapa[30][30];
	sf::Vector2i contador;

public:

	//Construtora e Destrutora
	Mapa(const char* caminho = "");
	~Mapa();

	//Funcoes
	void carregarMapa(const char* caminho);
	int getInfoXMapa(int i, int j);
	int getInfoYMapa(int i, int j);
	sf::Vector2i getInfoMapa(int i, int j);
};
