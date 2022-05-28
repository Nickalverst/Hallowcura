#pragma once
#include "Ente.h"
#include "ListaEntidades.h"

class Fase:
	public Ente
{
protected:
	ListaEntidades LE;

public:
	Fase();
	~Fase();

	void imprimirEntidades();
	virtual void executar() = 0;
	void incluirEntidades(Entidade* e);
};

