#include "Fase_1_Floresta.h"

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g) :
	Fase(),
	GG(g),
	zumbi()
{
	/*if (!tex.loadFromFile("assets/fase1.png"))
	{
		cerr << "Erro ao carregar a textura da fase. " << endl;
	}

	sprite.setTexture(tex[0]);
	sprite.setOrigin(Vector2f(tex.getSize().x / 2, tex.getSize().y));
	sprite.scale(Vector2f(SIZE, SIZE));*/

	zumbi.setGG(GG);
	LE.inserir(static_cast<Entidade*>(&zumbi));
}

Fase_1_Floresta::~Fase_1_Floresta()
{
}

void Fase_1_Floresta::executar()
{
	LE.executar();
}
