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

	void operator--(int dano);
	void operator++(int vida);
	void aplicarDeslize(float taxa);

	virtual void executar() = 0;
	virtual void corrigirPosicao(Vector2f pos) = 0;
};