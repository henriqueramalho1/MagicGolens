#include "stdafx.h"
#include "Leaderboard.h"
#include "MenuInicial.h"

bool cmp(pair<string, float>& a, pair<string, float>& b)
{
	return a.second > b.second;
}

Leaderboard::Leaderboard(GerenciadorEstado* Ge, GerenciadorGrafico* Gg, string caminhoBackground, sf::RenderWindow* j) :
	Menu(Ge, Gg, caminhoBackground, j),
	opcoes(),
	textbox(30, sf::Color::White, false, j),
	ranking(),
	leader(),
	posicoes(),
	pontuacoes(),
	nomeCadastrado(false)
{
	MenuIni = NULL;
	j1 = NULL;
	j2 = NULL;
	carregarPontuacao();
	inicializarLeaderboard();
	inicializarRanking();
}

Leaderboard::~Leaderboard()
{
	j1 = NULL;
	j2 = NULL;
	salvarPontuacao();
}

void Leaderboard::inicializarLeaderboard()
{
	if (!fonte.loadFromFile("font/chineseRocks.ttf"))
	{
		cout << "ERRO: Nao foi possivel carregar a fonte para o menu" << endl;
		exit(222);
	}

	opcoes[0].setFont(fonte);
	opcoes[0].setFillColor(sf::Color(0, 144, 150));
	opcoes[0].setString("Salvar pontuação");
	opcoes[0].setOrigin(opcoes[0].getLocalBounds().width / 2, opcoes[0].getLocalBounds().height / 2);
	opcoes[0].setPosition(sf::Vector2f(1280 / 3.f * 2, 720.f / 8 * 4));

	opcoes[1].setFont(fonte);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setString("Menu principal");
	opcoes[1].setOrigin(opcoes[1].getLocalBounds().width / 2, opcoes[1].getLocalBounds().height / 2);
	opcoes[1].setPosition(sf::Vector2f(1280 / 3.f * 2, 720.f / 8 * 5));
}

void Leaderboard::inicializarRanking()
{
	if (ranking.empty())
	{
		ranking.push_back(pair<string, float>("XXXX", 0.f));
		ranking.push_back(pair<string, float>("XXXX", 0.f));
		ranking.push_back(pair<string, float>("XXXX", 0.f));
		ranking.push_back(pair<string, float>("XXXX", 0.f));
		ranking.push_back(pair<string, float>("XXXX", 0.f));
	}
	inicializarNomes();
	inicializarPosicoes();
	inicializarPontuacoes();
	atualizarRanking();
}

void Leaderboard::inicializarNomes()
{
	leader[0].setFont(fonte);
	leader[0].setFillColor(sf::Color(0, 144, 150));
	leader[0].setString(ranking[0].first);
	leader[0].setPosition(sf::Vector2f(1280 / 3.f * 1, 720.f / 8 * 3) + sf::Vector2f(-50.f, -50.f));

	leader[1].setFont(fonte);
	leader[1].setFillColor(sf::Color(0, 144, 150));
	leader[1].setString(ranking[1].first);
	leader[1].setPosition(sf::Vector2f(1280 / 3.f * 1, 720.f / 8 * 4) + sf::Vector2f(-50.f, -50.f));

	leader[2].setFont(fonte);
	leader[2].setFillColor(sf::Color(0, 144, 150));
	leader[2].setString(ranking[2].first);
	leader[2].setPosition(sf::Vector2f(1280 / 3.f * 1, 720.f / 8 * 5) + sf::Vector2f(-50.f, -50.f));

	leader[3].setFont(fonte);
	leader[3].setFillColor(sf::Color(0, 144, 150));
	leader[3].setString(ranking[3].first);
	leader[3].setPosition(sf::Vector2f(1280 / 3.f * 1, 720.f / 8 * 6) + sf::Vector2f(-50.f, -50.f));

	leader[4].setFont(fonte);
	leader[4].setFillColor(sf::Color(0, 144, 150));
	leader[4].setString(ranking[4].first);
	leader[4].setPosition(sf::Vector2f(1280 / 3.f * 1, 720.f / 8 * 7) + sf::Vector2f(-50.f, -50.f));
}

void Leaderboard::inicializarPosicoes()
{
	posicoes[0].setFont(fonte);
	posicoes[0].setFillColor(sf::Color::White);
	posicoes[0].setString("1");
	posicoes[0].setPosition(leader[0].getPosition() + sf::Vector2f(-50.f, 0.f));

	posicoes[1].setFont(fonte);
	posicoes[1].setFillColor(sf::Color::White);
	posicoes[1].setString("2");
	posicoes[1].setPosition(leader[1].getPosition() + sf::Vector2f(-50.f, 0.f));

	posicoes[2].setFont(fonte);
	posicoes[2].setFillColor(sf::Color::White);
	posicoes[2].setString("3");
	posicoes[2].setPosition(leader[2].getPosition() + sf::Vector2f(-50.f, 0.f));

	posicoes[3].setFont(fonte);
	posicoes[3].setFillColor(sf::Color::White);
	posicoes[3].setString("4");
	posicoes[3].setPosition(leader[3].getPosition() + sf::Vector2f(-50.f, 0.f));

	posicoes[4].setFont(fonte);
	posicoes[4].setFillColor(sf::Color::White);
	posicoes[4].setString("5");
	posicoes[4].setPosition(leader[4].getPosition() + sf::Vector2f(-50.f, 0.f));
}

void Leaderboard::inicializarPontuacoes()
{
	pontuacoes[0].setFont(fonte);
	pontuacoes[0].setFillColor(sf::Color::White);
	pontuacoes[0].setString(to_string(static_cast<int>(ranking[0].second)));
	pontuacoes[0].setPosition(leader[0].getPosition() + sf::Vector2f(200.f, 0.f));

	pontuacoes[1].setFont(fonte);
	pontuacoes[1].setFillColor(sf::Color::White);
	pontuacoes[1].setString(to_string(static_cast<int>(ranking[1].second)));
	pontuacoes[1].setPosition(leader[1].getPosition() + sf::Vector2f(200.f, 0.f));

	pontuacoes[2].setFont(fonte);
	pontuacoes[2].setFillColor(sf::Color::White);
	pontuacoes[2].setString(to_string(static_cast<int>(ranking[2].second)));
	pontuacoes[2].setPosition(leader[2].getPosition() + sf::Vector2f(200.f, 0.f));

	pontuacoes[3].setFont(fonte);
	pontuacoes[3].setFillColor(sf::Color::White);
	pontuacoes[3].setString(to_string(static_cast<int>(ranking[3].second)));
	pontuacoes[3].setPosition(leader[3].getPosition() + sf::Vector2f(200.f, 0.f));

	pontuacoes[4].setFont(fonte);
	pontuacoes[4].setFillColor(sf::Color::White);
	pontuacoes[4].setString(to_string(static_cast<int>(ranking[4].second)));
	pontuacoes[4].setPosition(leader[4].getPosition() + sf::Vector2f(200.f, 0.f));
}

void Leaderboard::moverCima()
{
	if (itemSelecionado - 1 >= 0)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado--;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void Leaderboard::moverBaixo()
{
	if (itemSelecionado + 1 <= 1)
	{
		opcoes[itemSelecionado].setFillColor(sf::Color::White);
		itemSelecionado++;
		opcoes[itemSelecionado].setFillColor(sf::Color(0, 144, 150));
	}
}

void Leaderboard::desenhar()
{
	janela->draw(background);

	for (int i = 0; i < 2; i++)
	{
		janela->draw(opcoes[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		janela->draw(leader[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		janela->draw(posicoes[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		janela->draw(pontuacoes[i]);
	}

	textbox.desenhar();
}

void Leaderboard::executarEnter()
{
	switch (itemSelecionado)
	{
	case 0:
		if (!textbox.estaSelecionado()) {
			textbox.setColor(sf::Color(0, 144, 150));
		}
		if (!textbox.nomeEnviado())
		{
			textbox.setSelecionado(true);
		}
		if (textbox.nomeEnviado() && !nomeCadastrado)
		{
			float pontuacaoFinal = j1->getPontuacao();

			if (j2 != NULL)
				pontuacaoFinal += j2->getPontuacao();

			adicionarPontuacao(textbox.getString(), pontuacaoFinal);
			textbox.setSelecionado(false);
			textbox.limpar();
			nomeCadastrado = true;
		}

		break;

	case 1:
		GGrafico->setMenu(MenuIni);
		reiniciarEscrita();
		reiniciarPontuacoesJogadores();
		break;
	}
}

void Leaderboard::atualizar(sf::Event evento)
{
	if (textbox.estaSelecionado() && !nomeCadastrado)
	{
		switch (evento.type)
		{
		case sf::Event::TextEntered:
			if (textbox.estaSelecionado())
				textbox.receberNome(evento);
			break;
		}
	}

	switch (evento.type)
	{
	case sf::Event::KeyReleased:
		switch (evento.key.code)
		{
		case sf::Keyboard::Up:
			moverCima();
			break;

		case sf::Keyboard::Down:
			moverBaixo();
			break;

		case sf::Keyboard::Return:
			executarEnter();
			break;

		case sf::Keyboard::Escape:
			textbox.setSelecionado(false);
			break;
		}
	}


}

void Leaderboard::setMenuInicial(MenuInicial* m)
{
	if (m != NULL)
		MenuIni = m;
	else
	{
		cout << "ERRO: Leaderboard nao recebeu devidamente o menu inicial" << endl;
		exit(890);
	}
}

void Leaderboard::setNomeCadastrado(bool b)
{
	nomeCadastrado = b;
}

void Leaderboard::setJogadores(Jogador* jog1, Jogador* jog2)
{
	j1 = jog1;
	j2 = jog2;
}

void Leaderboard::adicionarPontuacao(string nome1, float pontuacao1)
{
	ranking.push_back(pair<string, float>(nome1, pontuacao1));

	atualizarRanking();
}

void Leaderboard::atualizarRanking()
{
	ordenaRanking(ranking);

	for (int i = 0; i < 5; i++)
	{
		leader[i].setString(ranking[i].first);
		pontuacoes[i].setString(to_string(static_cast<int>(ranking[i].second)));
	}
}

void Leaderboard::ordenaRanking(vector<pair<string, float>>& vetor)
{
	sort(vetor.begin(), vetor.end(), cmp);
}

void Leaderboard::salvarPontuacao()
{
	ofstream Gravador("salvar/leaderboard.txt", ios::out);

	if (!Gravador)
	{
		cout << "ERRO: Nao foi possivel abrir o leaderboard.txt" << endl;
		exit(78);
	}

	for (int i = 0; i < ranking.size(); i++)
	{
		Gravador << ranking[i].first << ' ' << ranking[i].second << endl;
	}

	Gravador.close();

}

void Leaderboard::carregarPontuacao()
{
	ifstream Recuperador("salvar/leaderboard.txt", ios::in);

	if (!Recuperador)
	{
		cout << "ERRO: Nao foi possivel abrir o leaderboard.txt" << endl;
		exit(78);
	}

	while (!Recuperador.eof())
	{
		float pontuacao;
		string nome;

		Recuperador >> nome >> pontuacao;

		if (nome != "")
		{
			pair<string, float> par(nome, pontuacao);
			ranking.push_back(par);
		}
	}



	Recuperador.close();
}

void Leaderboard::reiniciarEscrita()
{
	nomeCadastrado = false;
	textbox.setNomeEnviado(false);
}

void Leaderboard::reiniciarPontuacoesJogadores()
{
	j1->reiniciarPontuacao();

	if (j2 != NULL)
		j2->reiniciarPontuacao();

	j1 = NULL;
	j2 = NULL;
}
