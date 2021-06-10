#include "stdafx.h"
#include "Estalactite.h"

Estalactite::Estalactite(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, Jogador* jog1, Jogador* jog2):
	Obstaculo(ID,tam, p, v, caminhoTextura, t, j),
	caindo(false)
{
	j1 = jog1;
	j2 = jog2;
	sprite.setOrigin(corpo.getSize() / 2.f);
}

Estalactite::~Estalactite()
{
}

void Estalactite::atualizar()
{
	devoCair();

	if(caindo)
		velocidade.y += 9.81f / 2;
		posicao += velocidade * (*dt);
		sprite.setPosition(posicao);
}

void Estalactite::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	destruir = true;
}

void Estalactite::devoCair()
{
	if (j2 != NULL)
	{
		if (((j1->getPosicao().x > posicao.x - 100.f && j1->getPosicao().x < posicao.x + 100.f) && j1->getPosicao().y > posicao.y + 100.f) || ((j2->getPosicao().x > posicao.x - 100.f && j2->getPosicao().x < posicao.x + 100.f) && j2->getPosicao().y > posicao.y + 100.f))
		{
			caindo = true;
		}
	}
	else
	{
		if((j1->getPosicao().x > posicao.x - 100.f && j1->getPosicao().x < posicao.x + 100.f) && (j1->getPosicao().y > posicao.y + 100.f && j1->getPosicao().y < posicao.y + 1000.f))
		caindo = true;
	}
}

void Estalactite::salvar() {
	ofstream Gravador("salvar/Estalactite.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x << ' ' <<
		dimensoes.y << ' ' << viradoDir << ' ' << caindo << endl;

	Gravador.close();
}

void Estalactite::setCaindo(bool ca)
{
	caindo = ca;
}
