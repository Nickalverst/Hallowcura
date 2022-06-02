#include "Personagem.h"

Personagem::Personagem(Vector2f position):
	Entidade(position, 0.1f, 0.1f, 10.f),
	num_vidas(-1),
	gravidade(1.f),
	alturaChao(720.f)
{
}

Personagem::~Personagem()
{
}
