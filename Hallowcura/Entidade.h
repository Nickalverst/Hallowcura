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
	Entidade(Vector2f position = Vector2f(0.f, 0.f));
	virtual ~Entidade();
	virtual void executar() = 0;
};