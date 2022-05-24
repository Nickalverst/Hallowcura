#pragma once
#include "Ente.h"

class Entidade :
	public Ente
{
protected:
	int x, y;
	Vector2f velocidade;
	float aceleracao;
	float desaceleracao;
	float velocidadeMaxima;

public:
	Entidade(Vector2f position = Vector2f(0.f, 0.f), Vector2f size = Vector2f(0.f, 0.f), Color color = Color::White, float ac = 0.1f, float dc = 0.1f, float vm = 1.f);
	~Entidade();
	virtual void executar() = 0;
};