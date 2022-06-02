#include "Ente.h"
#include "Gerenciador_Grafico.h"

Ente::Ente(Vector2f position):
	GG(nullptr),
	id(-1)
{
	sprite.setPosition(position);
}

Ente::~Ente()
{
}

void Ente::imprimir_se()
{
	GG->desenhar(sprite);
}

void Ente::setGG(Gerenciador_Grafico* g)
{
	GG = g;
}
