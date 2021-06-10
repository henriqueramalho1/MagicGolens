#include "stdafx.h"
#include "Mapa.h"
#include<fstream>

Mapa::Mapa(const char* caminho):
	contador(sf::Vector2i(0,0)),
	mapa()
{
	carregarMapa(caminho);
}

Mapa::~Mapa() {
}

void Mapa::carregarMapa(const char* caminho) {
	std::ifstream openfile(caminho);
	if (openfile.is_open()) {
		while (!openfile.eof())
		{
			string str;
			openfile >> str;
			char x = str[0], y = str[2];
			mapa[contador.x][contador.y] = sf::Vector2i(x - '0', y - '0');
			if (openfile.peek() == '\n')
			{
				contador.x = 0;
				contador.y++;
			}
			else
				contador.x++;
		}

		contador.y++;
	}
}

int Mapa::getInfoXMapa(int i, int j) {
	return mapa[i][j].x;
}

int Mapa::getInfoYMapa(int i, int j) {
	return mapa[i][j].y;
}

sf::Vector2i Mapa::getInfoMapa(int i, int j)
{
	return mapa[i][j];
}