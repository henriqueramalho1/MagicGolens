#include "stdafx.h"
#include "GolemPedra.h"

GolemPedra::GolemPedra(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j) :
	Inimigo(ID, tam, p, v, caminhoTextura, t, j),
	crescimento(1.2f),
	cura(100.f)
{
}

GolemPedra::~GolemPedra()
{
}

void GolemPedra::atualizar()
{
	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemPedra::desenhar()
{
	janela->draw(corpo);
}

void GolemPedra::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro == jogador)
	{
		if (nivel <= 3)
		{
			hp += static_cast<int> (cura);
			dimensoes *= crescimento;
			corpo.scale(sf::Vector2f(crescimento, crescimento));
			nivel++;
		}
	}

	if (IdOutro == orb)
	{
		hp -= 100;
		if (hp <= 0)
			destruir = true;
	}
}

void GolemPedra::salvar() {
	ofstream Gravador("salvar/GolemPedra.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x+25.f << ' ' <<
		dimensoes.y+15.f << ' ' << viradoDir << ' ' << hp << ' ' << nivel << ' ' << crescimento << ' ' << cura << endl;

	Gravador.close();
}

void GolemPedra::setCrescimento(float cre)
{
	crescimento = cre;
}

void GolemPedra::setCura(float cur)
{
	cura = cur;
}
