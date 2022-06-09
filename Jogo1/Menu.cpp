#include "Menu.h"

Menu::Menu() :
	indiceItemSelecionado(0),
	fonte(),
	menu()
{
	if (!tex.loadFromFile("assets/menu.png"))
	{
		cerr << "Erro ao carregar a textura principal do menu. " << endl;
	}

	sprite.setTexture(tex);

	if (!fonte.loadFromFile("assets/arial.ttf"))
	{
		cerr << "Erro ao carregar fonte. " << endl;
	}
	
	menu[0].setFont(fonte);
	menu[0].setFillColor(Color::White);
	menu[0].setString("Jogar fase 1");
	menu[0].setOrigin(menu[0].getLocalBounds().width/2, menu[0].getLocalBounds().height/2);
	menu[0].setPosition(Vector2f(800, 400));

	menu[1].setFont(fonte);
	menu[1].setFillColor(Color::Black);
	menu[1].setString("Jogar fase 2");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(Vector2f(800, 500));

	menu[2].setFont(fonte);
	menu[2].setFillColor(Color::Black);
	menu[2].setString("Ranking");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(Vector2f(800, 600));

	menu[3].setFont(fonte);
	menu[3].setFillColor(Color::Black);
	menu[3].setString("Sair");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 2, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(Vector2f(800, 700));
}

Menu::~Menu()
{
}

void Menu::moverCima()
{
	if (indiceItemSelecionado - 1 >= 0)
	{
		menu[indiceItemSelecionado].setFillColor(Color::Black);
		indiceItemSelecionado--;
		menu[indiceItemSelecionado].setFillColor(Color::White);
	}
}

void Menu::moverBaixo()
{
	if (indiceItemSelecionado + 1 < MAX_ITENS)
	{
		menu[indiceItemSelecionado].setFillColor(Color::Black);
		indiceItemSelecionado++;
		menu[indiceItemSelecionado].setFillColor(Color::White);
	}
}

Text* Menu::getMenu()
{
	return menu;
}

int Menu::getMaxItens() const
{
	return MAX_ITENS;
}

int Menu::getItemPressionado() const
{
	return indiceItemSelecionado;
}

void Menu::executar()
{
}
