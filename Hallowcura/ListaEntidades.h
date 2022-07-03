#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
private:
	Lista<Entidade> LEs;

public:
	ListaEntidades();
	~ListaEntidades();

	void inserir(Entidade* e);
	void remover(Entidade* e);

	void imprimir();
	void executar();
};

