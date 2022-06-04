#include "Fase.h"

Fase::Fase(Jogador* j):
	Ente(),
	LE(),
	jogador(j)
{
}

Fase::~Fase()
{
}

void Fase::imprimirEntidades()
{
	LE.imprimir();
}

void Fase::incluirEntidades(Entidade* e)
{
	LE.inserir(e);
}
