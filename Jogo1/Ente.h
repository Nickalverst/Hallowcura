#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Ente
{
protected:
	RenderWindow* window;
	int id;
	RectangleShape body;

public:
	Ente(Vector2f position = Vector2f(0.f, 0.f), Vector2f size = Vector2f(0.f, 0.f), Color color = Color::White);
	~Ente();
	virtual void executar() = 0;
	void imprimir_se();

	void setWindow(RenderWindow* w);
};

