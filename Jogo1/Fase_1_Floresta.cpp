#include "Fase_1_Floresta.h"

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g) :
	Fase(),
	GG(g),
	zumbi()
{
	zumbi.setGG(GG);
	LE.inserir(static_cast<Entidade*>(&zumbi));
}

Fase_1_Floresta::~Fase_1_Floresta()
{
}

void Fase_1_Floresta::executar()
{
	LE.executar();
}
