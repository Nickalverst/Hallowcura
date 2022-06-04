#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Gerenciador_Colisao.h"

class Fase:
	public Ente
{
protected:
	ListaEntidades LE;
	Gerenciador_Grafico* GG;
	Gerenciador_Colisao GC;
	Jogador* jogador;

public:
	Fase(Gerenciador_Grafico* g, Jogador* j);
	~Fase();

	void imprimirEntidades();
	virtual void executar() = 0;
	void incluirEntidades(Entidade* e);
};

