#pragma once
#include "Ente.h"

class Entidade :
	public Ente
{
protected:
	int x, y;

public:
	Entidade(Vector2f position = Vector2f(0.f, 0.f), Vector2f size = Vector2f(0.f, 0.f), Color color = Color::White);
	~Entidade();
	virtual void executar() = 0;
};