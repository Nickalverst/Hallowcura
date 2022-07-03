#pragma once
#include "Entidade.h"
class Personagem :
	public Entidade
{
protected:
	int num_vidas;
	float gravidade;
	float velocidadeCambaleio;
	int dano;

public:
	Personagem(Vector2f position);
	virtual ~Personagem();

	void operator--(int dano);
	void operator++(int vida);
	void aplicarDeslize(float taxa);

	virtual void executar() = 0;
	virtual void corrigirPosicao(Vector2f pos) = 0;

	void atacar(Personagem* p, float difPosX);
	void tomarDano(int dano, float difPosX = 0);
	void teleporteParedes();

	const int getVida() const { return num_vidas; }
};