#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
#include <iostream>
using namespace std;

#define SIZE 4.0f

class Gerenciador_Grafico;

class Ente
{
protected:
	Gerenciador_Grafico* GG;
	Texture tex;
	Sprite sprite;

public:
	Ente(Vector2f position = Vector2f(0.f, 0.f));
	virtual ~Ente();
	virtual void executar() = 0;
	void imprimir_se();

	void setGG(Gerenciador_Grafico* g);
	const Vector2f getTamanho() const;
	const Vector2f getPosicao() const;
};
