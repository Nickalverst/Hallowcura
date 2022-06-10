#include "Personagem.h"

Personagem::Personagem(Vector2f position):
	Entidade(position, 0.1f, 0.1f, 10.f),
	num_vidas(-1),
	gravidade(.5f),
	alturaChao(SIZE*213.f)
{
}

Personagem::~Personagem()
{
}

void Personagem::operator--(int dano)
{
	num_vidas -= dano;
}

void Personagem::operator++(int vida)
{
	num_vidas += vida;
}

void Personagem::aplicarDeslize(float taxa)
{
	velocidade.x *= taxa;
}