#include "Ente.h"

Ente::Ente(Vector2f position, Vector2f size, Color color):
	window(nullptr),
	id(-1)
{
	body.setPosition(position);
	body.setSize(size);
	body.setFillColor(color);
}

Ente::~Ente()
{
}

void Ente::imprimir_se()
{
	window->draw(body);
}

void Ente::setWindow(RenderWindow* w)
{
	window = w;
}
