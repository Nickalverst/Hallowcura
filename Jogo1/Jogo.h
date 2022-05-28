#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "ListaEntidades.h"
#include "Fase_1_Floresta.h"

class Jogo
{
private:
	Gerenciador_Grafico GG;
	Jogador jogador;
	Fase_1_Floresta fase1;

public:
	Jogo();
	~Jogo();

	void executar();
};

