#include "stdafx.h"
#include "Chefao.h"

Chefao::Chefao(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, float tamCristal):
	GolemGelo(ID, tam, p, v, caminhoTextura, t, j, tamCristal)
{
	hp = 1000;
	setViradoDir(false);
}

Chefao::~Chefao()
{
}

void Chefao::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro == orb)
	{
		hp -= 100;
		if (hp <= 0)
			destruir = true;
	}
}

void Chefao::arremessarCristal()
{
	CristalGelo* pCristal = NULL;

	float velx;
	float vely;
	vely = -300 - static_cast<float>(rand() % 150);
	velx = -300 - static_cast<float>(rand() % 300);
	pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f) * tamanhoCristal, posicao, sf::Vector2f(velx, vely), "text/cristal.png", dt, janela);
	LEntidades->incluirEntidade(pCristal);
	GColisoes->adicionarEntidade(pCristal);

}

void Chefao::salvar()
{
	ofstream Gravador("salvar/Chefao.txt", ios::trunc);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x + 25.f << ' ' <<
		dimensoes.y + 15.f << ' ' << viradoDir << ' ' << hp << ' ' << nivel << ' ' << limite << ' ' << cooldown << ' ' << podeAtirar << ' ' << tamanhoCristal;

	Gravador.close();
}


