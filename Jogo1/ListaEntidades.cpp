#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():
	LEs(),
	tamanho(0)
{
}

ListaEntidades::~ListaEntidades()
{
	LEs.limpar();
}

void ListaEntidades::inserir(Entidade* e)
{
	if (e != nullptr)
	{
		LEs.incluaInfo(e);
		tamanho++;
	}
	else
	{
		cerr << "Erro: ponteiro para entidade � nulo." << endl;
	}
}

void ListaEntidades::remover(Entidade* e)
{
	// Iterator? Esta fun��o ser� usada para remover objetos que forem destru�dos
}

void ListaEntidades::imprimir()
{
	Elemento<Entidade>* pElAux = LEs.getPrimeiro();
	Entidade* pEntAux = nullptr;
	while (nullptr != pElAux)
	{
		pEntAux = pElAux->getInfo();
		pEntAux->imprimir_se(); // O problema est� aqui.
		pElAux = pElAux->getProximo();
	}
}

const int ListaEntidades::getTamanho() const
{
	return tamanho;
}
