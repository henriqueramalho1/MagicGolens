#include "stdafx.h"
#include "Textbox.h"

Textbox::Textbox() :
	textbox(),
	text(),
	selecionado(false),
	temLimite(true),
	nomeLido(false),
	limite(15),
	fonte(),
	janela()
{
}

Textbox::Textbox(int tam, sf::Color cor, bool sel, sf::RenderWindow* j) :
	textbox(),
	text(),
	selecionado(false),
	temLimite(true),
	nomeLido(false),
	limite(8),
	fonte(),
	janela(j)
{
	fonte.loadFromFile("font/chineseRocks.ttf");
	textbox.setFont(fonte);
	textbox.setCharacterSize(tam);
	textbox.setFillColor(cor);
	textbox.setOrigin(textbox.getLocalBounds().width / 2, textbox.getLocalBounds().height / 2);
	textbox.setPosition(sf::Vector2f(1280.f / 2 + 210.f, 720 / 3.f));
	selecionado = sel;

	if (selecionado)
		textbox.setString("_");
	else
		textbox.setString("");
}

Textbox::~Textbox()
{
}

void Textbox::entrada(int tipoChar)
{
	if (tipoChar != 8 && tipoChar != 13 && tipoChar != 27)
	{
		text += static_cast<char>(tipoChar);
	}
	else if (tipoChar == 8)
	{
		if (text.length() > 0)
		{
			excluirUltimoCaracter();
		}
	}
	textbox.setString(text + "_");
	atualizaPosicao();
}

void Textbox::excluirUltimoCaracter()
{
	string t = text;
	string novo = "";

	for (int i = 0; i < t.length() - 1; i++)
	{
		novo += t[i];
	}

	text = "";
	text = novo;

	textbox.setString(text);
	atualizaPosicao();
}

void Textbox::setSelecionado(bool b)
{
	if (b && !selecionado)
	{
		string t = textbox.getString();
		t += "_";
		textbox.setString(t);
	}

	if (b && selecionado)
	{
		finalizarRecebimento();
	}

	selecionado = b;

	if (!selecionado)
	{
		string t = text;
		string novo = "";

		for (int i = 0; i < t.length(); i++)
		{
			novo += t[i];
		}

		textbox.setString(novo);
	}
}

void Textbox::finalizarRecebimento()
{
	setColor(sf::Color(255, 255, 255));

	string t = text;
	string novo = "";

	for (int i = 0; i < t.length(); i++)
	{
		novo += t[i];
	}

	text = novo;

	textbox.setString(text);

	text = "";

	nomeLido = true;
}

bool Textbox::estaSelecionado()
{
	return selecionado;
}

bool Textbox::nomeEnviado()
{
	return nomeLido;
}

string Textbox::getString()
{
	return textbox.getString();
}

void Textbox::desenhar()
{
	janela->draw(textbox);
}

void Textbox::atualizaPosicao()
{
	textbox.setOrigin(textbox.getLocalBounds().width / 2, textbox.getLocalBounds().height / 2);
}

void Textbox::setColor(sf::Color cor)
{
	textbox.setFillColor(cor);
}

void Textbox::receberNome(sf::Event e)
{
	if (selecionado)
	{
		int tipoChar = e.text.unicode;
		if ((tipoChar >= 96 && tipoChar <= 122) || tipoChar == 8)
		{
			if (temLimite)
			{
				if (text.length() <= limite)
				{
					entrada(tipoChar);
					cout << static_cast<char>(tipoChar) << endl;
				}
				else if (text.length() > limite && tipoChar == 8)
				{
					cout << "excluindo" << endl;
					excluirUltimoCaracter();
				}
			}
		}
	}
}

void Textbox::limpar()
{
	textbox.setString("");
	text = "";
}

void Textbox::setNomeEnviado(bool b)
{
	nomeLido = b;
}
