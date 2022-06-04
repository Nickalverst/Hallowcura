#include "Fase.h"

Fase::Fase(Gerenciador_Grafico* g, Jogador* j):
	Ente(),
	LE(),
	GG(g),
	GC(j),
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
