#include "Fase.h"

Fase::Fase()
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