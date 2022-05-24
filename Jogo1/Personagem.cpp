#include "Personagem.h"

Personagem::Personagem(Vector2f position, Vector2f size, Color color):
	Entidade(position, size, color),
	num_vidas(-1)
{
}

Personagem::~Personagem()
{
}
