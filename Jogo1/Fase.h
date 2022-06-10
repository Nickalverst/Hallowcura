#pragma once
#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Gerenciador_Colisao.h"
#include "ArmadilhaUrso.h"
#include "Zumbi.h"
#include "Olho.h"
#include <cstdlib>
#include <time.h>
using namespace Gerenciadores;

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
	void incluirEntidade(Entidade* e);
	void removerEntidade(Entidade* e);
	void criarEntidades();
};

