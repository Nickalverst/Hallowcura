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
		cerr << "Erro: ponteiro para entidade é nulo." << endl;
	}
}

void ListaEntidades::remover(Entidade* e)
{
	Elemento<Entidade>* itr = LEs.getPrimeiro();
	if (e != nullptr)
	{
		while (itr != LEs.getUltimo() && itr->getProximo()->getProximo() != nullptr)
		{
			if (itr->getProximo()->getInfo() == e)
			{
				Elemento<Entidade>* aux = itr->getProximo()->getProximo();
				delete(itr->getProximo());
				delete(e);
				itr->setProximo(aux);
					
				return;
			}

			itr = itr->getProximo();
		}
	}
	else
	{
		cerr << "Erro: ponteiro para entidade é nulo." << endl;
	}
}

void ListaEntidades::imprimir()
{
	Elemento<Entidade>* pElAux = LEs.getPrimeiro();
	Entidade* pEntAux = nullptr;
	while (nullptr != pElAux)
	{
		pEntAux = pElAux->getInfo();
		pEntAux->imprimir_se();
		pElAux = pElAux->getProximo();
	}
}

void ListaEntidades::executar()
{
	Elemento<Entidade>* pElAux = LEs.getPrimeiro();
	Entidade* pEntAux = nullptr;
	while (nullptr != pElAux)
	{
		pEntAux = pElAux->getInfo();
		pEntAux->executar();
		pElAux = pElAux->getProximo();
	}
}

const int ListaEntidades::getTamanho() const
{
	return tamanho;
}
