#pragma once
#include "Entidade.h"
class Personagem :
	public Entidade
{
protected:
	int num_vidas;
	float gravidade;
	float alturaChao;
	float velocidadeCambaleio;
	int dano;

public:
	Personagem(Vector2f position = Vector2f(0.f, 0.f));
	virtual ~Personagem();

	void operator--(int dano);
	void operator++(int vida);
	void aplicarDeslize(float taxa);

	virtual void executar() = 0;
	virtual void corrigirPosicao(Vector2f pos) = 0;
	void atacar(Personagem* p, float difPosX);
	void tomarDano(int dano, float difPosX = 0);
	const int getVida() const { return num_vidas; }
};