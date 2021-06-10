#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Id(ID),
	posicao(p),
	velocidade(v),
	textura(),
	sprite(),
	corpo(tam),
	dimensoes(tam),
	destruir(false),
	viradoDir(true)
{
	textura.loadFromFile(caminhoTextura);
	sprite.setTexture(textura);
	sprite.setPosition(p);
	corpo.setTexture(sprite.getTexture());
	corpo.setOrigin(corpo.getSize() / 2.f);
	janela = j;
	dt = t;
	if (Id == jogador || Id == golemPedra || Id == golemFogo || Id == golemGelo || Id == boss)
	{
		dimensoes.x = dimensoes.x - 25.f;
		dimensoes.y = dimensoes.y - 15.f;
	}
}

Entidade::~Entidade()
{
}

void Entidade::setPosicao(sf::Vector2f p)
{
	posicao = p;
	corpo.setPosition(posicao);
}

void Entidade::setVelocidadeX(float x)
{
	velocidade.x = x;
}

void Entidade::setVelocidadeY(float y)
{
	velocidade.y = y;
}

void Entidade::virar()
{
	corpo.scale(sf::Vector2f(-1.f, 1.f));
	velocidade.x = velocidade.x * (-1);
	if (viradoDir)
		viradoDir = false;
	else
		viradoDir = true;
}

sf::Vector2f Entidade::getPosicao()
{
	return posicao;
}

sf::Vector2f Entidade::getDimensoes()
{
	return dimensoes;
}

const IdsColidiveis Entidade::getId()
{
	return Id;
}

bool Entidade::destruirEntidade() const
{
	return destruir;
}

bool Entidade::getViradoDir()
{
	return viradoDir;
}

void Entidade::setViradoDir(bool v)
{
	if (!viradoDir && !v)
		corpo.scale(sf::Vector2f(-1.f, 1.f));

	viradoDir = v;

}

void Entidade::limparSalvamento()	//Limpa os arquivos que servem para guardar informacoes dos objetos, para que novas informaçoes sejam colocadas.
{
	ofstream Gravador;
	string caminhos[7] = {"salvar/Jogador.txt", "salvar/GolemPedra.txt", "salvar/GolemFogo.txt", "salvar/GolemGelo.txt", "salvar/Orbe.txt", "salvar/CristalGelo.txt", "salvar/Estalactite.txt"};

	for (int i = 0; i < 7; i++) {
		Gravador.open(caminhos[i], ios::trunc);
		if (!Gravador)
			exit(12344);
		Gravador << "";
		Gravador.close();
	}
}
