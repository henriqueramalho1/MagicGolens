#include "stdafx.h"
#include "Orbe.h"

Orbe::Orbe(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Arremessavel(ID, tam, p, v, caminhoTextura, t, j)
{
}

Orbe::~Orbe()
{
}

void Orbe::atualizar()
{
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void Orbe::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro != naocolidivel && IdOutro != jogador && IdOutro != porta && IdOutro != espinho && IdOutro != fogo && IdOutro != orb)
	{
		destruir = true;
	}

}

void Orbe::salvar() {
	ofstream Gravador("salvar/Orbe.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << endl;

	Gravador.close();
}