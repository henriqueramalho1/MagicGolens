#include "stdafx.h"
#include "GolemGelo.h"

GolemGelo::GolemGelo(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, float tamCristal) :
	Inimigo(ID, tam, p, v, caminhoTextura, t, j),
	Atirador(3),
	tamanhoCristal(tamCristal)
{
}

GolemGelo::~GolemGelo()
{
}

void GolemGelo::atualizar()
{
	cooldown += *dt;

	possoAtirar(cooldown);

	if (podeAtirar)
	{
		arremessarCristal();
		cooldown = 0.f;
		podeAtirar = false;
	}

	velocidade.y += 9.81f;
	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}

void GolemGelo::desenhar()
{
	janela->draw(corpo);
}

void GolemGelo::colidir(IdsColidiveis IdOutro, sf::Vector2f posicaoOutro, sf::Vector2f dimensoesOutro, Entidade* e)
{
	if (IdOutro == jogador)
	{
		if (nivel <= 5)
		{
			limite -= 0.4f;
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

void GolemGelo::arremessarCristal()
{
	CristalGelo* pCristal = NULL;


	if (viradoDir)
		pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f) * tamanhoCristal, posicao, sf::Vector2f(300.f, -300.f), "text/cristal.png", dt, janela);
	else
		pCristal = new CristalGelo(cristal, sf::Vector2f(28.f, 28.f) * tamanhoCristal, posicao, sf::Vector2f(-300.f, -300.f), "text/cristal.png", dt, janela);
	

	LEntidades->incluirEntidade(pCristal);
	GColisoes->adicionarEntidade(pCristal);
}

void GolemGelo::salvar() {
	ofstream Gravador("salvar/GolemGelo.txt", ios::app);

	if (!Gravador) {
		cerr << "Arquivo nao foi aberto" << endl;
		exit(12344);
	}

	Gravador << posicao.x << ' ' << posicao.y << ' ' << velocidade.x << ' ' << velocidade.y << ' ' << dimensoes.x+25.f << ' ' <<
		dimensoes.y+15.f << ' ' << viradoDir << ' ' << hp << ' ' << nivel << ' ' << limite << ' ' << cooldown << ' ' << podeAtirar << ' ' << tamanhoCristal << endl;

	Gravador.close();
}

void GolemGelo::setTamanhoCristal(float tamcri)
{
	tamanhoCristal = tamcri;
}

