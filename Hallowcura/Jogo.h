#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "ListaEntidades.h"
#include "Fase_1_Floresta.h"
#include "Menu.h"
#include "Inimigo.h"
#include "Fase_2_Ponte.h"

class Jogo
{
private:
	Gerenciador_Grafico GG;
	Jogador jogador;
	Fase_1_Floresta* fase1;
	Fase_2_Ponte* fase2;
	Menu menu;
	string estadoAtual;
	bool pausado, chefaoCriado;

public:
	Jogo();
	~Jogo();

	void executar();
	const Jogador* getJogador() const;
};

