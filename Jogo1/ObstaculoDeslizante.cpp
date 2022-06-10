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

void ObstaculoDeslizante::afetarJogador(Jogador* j)
{
	aplicarDeslize(j);
}

void ObstaculoDeslizante::aplicarDeslize(Jogador* j)
{
	j->aplicarDeslize(taxaAtrito);
}
