#pragma once
#include "Entidade.h"
class Personagem :
	public Entidade
{
protected:
	int num_vidas;

public:
	Personagem(Vector2f position = Vector2f(0.f, 0.f), Vector2f size = Vector2f(0.f, 0.f), Color color = Color::White);
	~Personagem();
};