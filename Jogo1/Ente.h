#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
#include <iostream>
using namespace std;

class Gerenciador_Grafico;

class Ente
{
protected:
	Gerenciador_Grafico* GG;
	int id;
	RectangleShape body;

public:
	Ente(Vector2f position = Vector2f(0.f, 0.f), Vector2f size = Vector2f(0.f, 0.f), Color color = Color::White);
	~Ente();
	virtual void executar() = 0;
	void imprimir_se();

	void setGG(Gerenciador_Grafico* g);
};

