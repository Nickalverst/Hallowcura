#include "Obstaculo.h"

Obstaculo::Obstaculo(int dano) :
	Entidade(),
	dano(dano)
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::afetarJogador(Jogador* j)
{
	j->tomarDano(dano);
}
