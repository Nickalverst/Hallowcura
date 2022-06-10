#include "Fase_2_Ponte.h"

Fase_2_Ponte::Fase_2_Ponte(Gerenciador_Grafico* g, Jogador* j):
	Fase(g, j)
{
	// Fundo de tela
	if (!tex.loadFromFile("assets/ponte.png"))
	{
		cerr << "Erro ao carregar a textura da fase Ponte. " << endl;
	}

	sprite.setTexture(tex);
	sprite.scale(Vector2f(SIZE, SIZE));
}

Fase_2_Ponte::~Fase_2_Ponte()
{
}

void Fase_2_Ponte::executar()
{
	LE.executar();
	GC.Colisao(this);
}
