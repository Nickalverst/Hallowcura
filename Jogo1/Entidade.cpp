#include "Entidade.h"

Entidade::Entidade(Vector2f position):
	Ente(position),
	velocidade(Vector2f(0.f, 0.f)),
	aceleracao(0.1f),
	desaceleracao(0.1f),
	velocidadeMaxima(10.f),
	olhandoDireita(true)
{
}

Entidade::~Entidade()
{
}
