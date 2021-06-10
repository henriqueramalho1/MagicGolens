#include "stdafx.h"
#include "Mago.h"

Mago::Mago(IdsColidiveis ID, sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, string caminhoTextura, float* t, sf::RenderWindow* j, string caminhoCongelado) :
	Jogador(ID, tam, p, v, caminhoTextura, t, j, caminhoCongelado)
{
}

Mago::~Mago() {}

void Mago::atualizar()
{
	cooldown += *dt;
	possoAtirar(cooldown);

	cooldownGelo += *dt;
	descongelado(cooldownGelo);

	if (!congelado) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			velocidade.x = 600.f / lentidao;
			corpo.setScale(sf::Vector2f(1.f, 1.f));
			viradoDir = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			velocidade.x = -600.f / lentidao;
			corpo.setScale(sf::Vector2f(-1.f, 1.f));
			viradoDir = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular)
		{
			podePular = false;
			velocidade.y = -sqrt(250.0f * 98.0f * alturaPulo);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && podeAtirar) {
			podeAtirar = false;
			Orbe* pOrbe = NULL;

			if (viradoDir)
				pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(800.f, 0.f), "text/orbe.png", dt, janela);
			else
				pOrbe = new Orbe(orb, sf::Vector2f(28.f, 28.f), posicao, sf::Vector2f(-800.f, 0.f), "text/orbe.png", dt, janela);

			GColisoes->adicionarEntidade(pOrbe);
			LEntidades->incluirEntidade(pOrbe);

			cooldown = 0.f;
		}
		velocidade.x *= 0.9f;
	}

	velocidade.y += 98.1f;

	posicao += velocidade * (*dt);
	corpo.setPosition(posicao);
}
