#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
private:
	Lista<Entidade> LEs;
	int tamanho;

public:
	ListaEntidades();
	~ListaEntidades();

	void inserir(Entidade* e);
	void remover(Entidade* e);

	void imprimir();

	const int getTamanho() const;
};

