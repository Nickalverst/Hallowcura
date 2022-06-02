#include "Entidade.h"

Entidade::Entidade(Vector2f position, float ac, float dc, float vm):
	Ente(position),
	x((int)position.x),
	y((int)position.y),
	velocidade(Vector2f(0.f, 0.f)),
	aceleracao(ac),
	desaceleracao(dc),
	velocidadeMaxima(vm),
	olhandoDireita(true)
{
	
}

Entidade::~Entidade()
{
}
