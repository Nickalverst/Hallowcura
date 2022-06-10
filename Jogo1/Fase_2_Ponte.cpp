#include "Fase_2_Ponte.h"

Fase_2_Ponte::Fase_2_Ponte(Gerenciador_Grafico* g, Jogador* j):
	Fase(g, j),
	j(j)
{
	// Fundo de tela
	if (!tex.loadFromFile("assets/ponte.png"))
	{
		cerr << "Erro ao carregar a textura da fase Ponte. " << endl;
	}

	sprite.setTexture(tex);
	sprite.scale(Vector2f(SIZE, SIZE));
	criarEntidades();
}

Fase_2_Ponte::~Fase_2_Ponte()
{
}

void Fase_2_Ponte::executar()
{
	LE.executar();
	GC.Colisao(this);
}

void Fase_2_Ponte::criarEntidades()
{
	// UFO
	
	{
		Vector2f pos = Vector2f(800, 200);
		UFO* aux = new UFO(pos, &GC, &LE, j);
		aux->setGG(GG);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirInimigo(static_cast<Inimigo*>(aux));
	}
}
