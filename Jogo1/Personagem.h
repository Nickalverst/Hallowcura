#pragma once
#include "Entidade.h"
class Personagem :
	public Entidade
{
protected:
	int num_vidas;
	float gravidade;
	float alturaChao;

public:
	Personagem(Vector2f position = Vector2f(0.f, 0.f));
	~Personagem();

	virtual void executar() = 0;
};