#include "Personagem.h"

Personagem::Personagem(Vector2f position):
	Entidade(position, 0.1f, 0.1f, 10.f),
	num_vidas(-1),
	gravidade(.5f),
	alturaChao(SIZE*213.f),
	velocidadeCambaleio(5.f),
	dano(5)
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

void Personagem::atacar(Personagem* p, float difPosX)
{
	p->tomarDano(dano, difPosX);
}

void Personagem::tomarDano(int dano, float difPosX)
{
	if (difPosX > 0) velocidade.x = -velocidadeCambaleio;
	else if (difPosX < 0) velocidade.x = velocidadeCambaleio; // Velocidade oposta ao inimigo
	operator--(dano);
}

void Personagem::teleporteParedes()
{
	if (getPosicao().x > 1600)
	{
		corrigirPosicao(Vector2f(0, getPosicao().y));
	}
	else if (getPosicao().x < 0)
	{
		corrigirPosicao(Vector2f(1600, getPosicao().y));
	}
}
