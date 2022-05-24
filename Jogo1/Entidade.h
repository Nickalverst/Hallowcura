#pragma once
#include "Ente.h"
class Entidade :
	public Ente
{
protected:
	int x, y;

public:
	Entidade();
	~Entidade();
	virtual void executar() = 0;
};

