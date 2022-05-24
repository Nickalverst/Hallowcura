#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"

class Jogo
{
private:
	RenderWindow window;
	Jogador jogador;

public:
	Jogo();
	~Jogo();

	void executar();
};

