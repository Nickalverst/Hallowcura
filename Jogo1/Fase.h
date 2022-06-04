#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"

class Fase:
	public Ente
{
protected:
	ListaEntidades LE;
	Jogador* jogador;

public:
	Fase(Jogador* j);
	~Fase();

	void imprimirEntidades();
	virtual void executar() = 0;
	void incluirEntidades(Entidade* e);
};

