#include "Entidade.h"

Entidade::Entidade(Vector2f position, Vector2f size, Color color, float ac, float dc, float vm):
	Ente(position, size, color),
	x((int)position.x),
	y((int)position.y),
	velocidade(Vector2f(0.f, 0.f)),
	aceleracao(ac),
	desaceleracao(dc),
	velocidadeMaxima(vm)
{
	
}

Entidade::~Entidade()
{
}
