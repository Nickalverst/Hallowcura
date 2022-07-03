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

	sprite.scale(Vector2f(SIZE, SIZE));
	sprite.setTexture(tex);

	if (!fonte.loadFromFile("assets/arial.ttf"))
	{
		cerr << "Erro ao carregar fonte. " << endl;
	}
	
	menu[0].setFont(fonte);
	menu[0].setFillColor(Color::White);
	menu[0].setString("Jogar fase 1");
	menu[0].setOrigin(menu[0].getLocalBounds().width/2, menu[0].getLocalBounds().height/2);
	menu[0].setPosition(Vector2f(800, 350));

	menu[1].setFont(fonte);
	menu[1].setFillColor(Color::Red);
	menu[1].setString("Jogar fase 2");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(Vector2f(800, 450));

	menu[2].setFont(fonte);
	menu[2].setFillColor(Color::Red);
	menu[2].setString("Ranking");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(Vector2f(800, 550));

	menu[3].setFont(fonte);
	menu[3].setFillColor(Color::Red);
	menu[3].setString("Sair");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 2, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(Vector2f(800, 650));
}

Menu::~Menu()
{
}

void Menu::moverCima()
{
	if (indiceItemSelecionado - 1 >= 0)
	{
		menu[indiceItemSelecionado].setFillColor(Color::Red);
		indiceItemSelecionado--;
		menu[indiceItemSelecionado].setFillColor(Color::White);
	}
}

void Menu::moverBaixo()
{
	if (indiceItemSelecionado + 1 < MAX_ITENS)
	{
		menu[indiceItemSelecionado].setFillColor(Color::Red);
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

Text* Menu::getRanking()
{

	for (int i = 0; i < 5; i++)
	{
		string intstr = to_string((int)i);
		ranking[i].setFont(fonte);
		ranking[i].setFillColor(Color::White);
		ranking[i].setString("cPP" + intstr);
		ranking[i].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
		ranking[i].setPosition(Vector2f(200, 100 + 100*i));

		string aux = to_string((int)i*20);
		ranking[i + 5].setFont(fonte);
		ranking[i + 5].setFillColor(Color::White);
		ranking[i + 5].setString("pontuação: 000");
		ranking[i + 5].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
		ranking[i + 5].setPosition(Vector2f(500, 100 + 100 * i));
	}
	return &ranking[0];
}