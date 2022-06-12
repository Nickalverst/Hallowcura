#pragma once
#include "Ente.h"

class Entidade :
	public Ente
{
protected:
	Vector2f velocidade;
	float aceleracao;
	float desaceleracao;
	float velocidadeMaxima;
	bool olhandoDireita;

public:
	Entidade(Vector2f position = Vector2f(0.f, 0.f), float ac = 0.1f, float dc = 0.1f, float vm = 1.f);
	virtual ~Entidade();
	virtual void executar() = 0;
};