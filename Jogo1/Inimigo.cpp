#include "Inimigo.h"

Inimigo::Inimigo(Vector2f position):
	Personagem(position),
	raioPatrulha(),
	pontoInicial(),
	dano(1)
{
	contador_inimigos++;
}

Inimigo::~Inimigo()
{
	contador_inimigos--;
}

void Inimigo::atacar(Jogador* j, float difPosX)
{
	j->tomarDano(dano, difPosX);
}

const int Inimigo::getContadorInimigos()
{
	return contador_inimigos;
}

int Inimigo::contador_inimigos(0);
