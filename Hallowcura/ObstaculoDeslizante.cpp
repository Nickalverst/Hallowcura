#include "ObstaculoDeslizante.h"

ObstaculoDeslizante::ObstaculoDeslizante(float a):
	Obstaculo(),
	taxaAtrito(a)
{
}

ObstaculoDeslizante::~ObstaculoDeslizante()
{
	taxaAtrito = 0.f;
}

void ObstaculoDeslizante::afetarPersonagem(Personagem* p, Vector2f deltaPos)
{
	aplicarDeslize(p);
}

void ObstaculoDeslizante::aplicarDeslize(Personagem* p)
{
	p->aplicarDeslize(taxaAtrito);
}
