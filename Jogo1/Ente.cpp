#include "Ente.h"
#include "Gerenciador_Grafico.h"
Ente::Ente(Vector2f position, Vector2f size, Color color):
	GG(nullptr),
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
	GG->desenhar(body);
}

void Ente::setGG(Gerenciador_Grafico* g)
{
	GG = g;
}
