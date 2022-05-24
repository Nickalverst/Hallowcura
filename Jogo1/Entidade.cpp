#include "Entidade.h"

Entidade::Entidade(Vector2f position, Vector2f size, Color color):
	Ente(position, size, color),
	x((int)position.x),
	y((int)position.y)
{
	
}

Entidade::~Entidade()
{
}
