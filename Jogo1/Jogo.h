#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Gerenciador_Grafico.h"

class Jogo
{
private:
	Gerenciador_Grafico GG;
	RenderWindow window;
	Jogador jogador;

public:
	Jogo();
	~Jogo();

	void executar();
};

