#include "stdafx.h"
#include "CristalGelo.h"

CristalGelo::CristalGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j):
Arremessavel(ID, tam, p, v, caminhoTextura, t, j)
{
}

CristalGelo::~CristalGelo()
{
}

void CristalGelo::atualizar()
{
	velocidade.y += 9.81f / 2;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void CristalGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro != naocolidivel && IdOutro != golemGelo && IdOutro != porta && IdOutro != boss)
	{
		destruir = true;
	}

}

void CristalGelo::salvar() {
	ofstream Gravador("salvar/CristalGelo.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << endl;

	Gravador.close();
}