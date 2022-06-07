#include "Inimigo.h"

Inimigo::Inimigo(Vector2f position):
	Personagem(position),
	dano(1)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::atacar(Jogador* j, float difPosX)
{
	j->tomarDano(difPosX, dano);
}
