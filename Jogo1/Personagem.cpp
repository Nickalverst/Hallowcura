#include "Personagem.h"

Personagem::Personagem(Vector2f position, Vector2f size, Color color):
	Entidade(position, size, color, 0.1f, 0.1f, 10.f),
	num_vidas(-1),
	gravidade(1.f),
	alturaChao(720.f)
{
}

Personagem::~Personagem()
{
}
