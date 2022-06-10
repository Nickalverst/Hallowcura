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

const Vector2f Ente::getTamanho() const
{
	return Vector2f(sprite.getLocalBounds().width*SIZE, sprite.getLocalBounds().height*SIZE);
}

const Vector2f Ente::getPosicao() const
{
	return sprite.getPosition();
}
