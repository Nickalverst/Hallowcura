#include "Fase_1_Floresta.h"

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g, Jogador* j) :
	Fase(g, j)
{
	// Fundo de tela
	if (!tex.loadFromFile("assets/floresta.png"))
	{
		cerr << "Erro ao carregar a textura da fase Floresta. " << endl;
	}

	sprite.setTexture(tex);
	sprite.scale(Vector2f(SIZE, SIZE));

	criarEntidades();
}

Fase_1_Floresta::~Fase_1_Floresta()
{
}

void Fase_1_Floresta::executar()
{
	LE.executar();
	GC.Colisao(this);
}

void Fase_1_Floresta::criarEntidades()
{
	int n_obstaculos = (rand() % 5) + 3;

	// Possíveis posições de spawn dos obstaculos
	vector<Vector2f> posicoesObstaculos;
	for (int i = 200; i < 1600; i += 100)
	{
		posicoesObstaculos.push_back(Vector2f((float)i, 900 - 42));
	}

	// Criar barros
	for (int i = 0; i < n_obstaculos; i++)
	{
		int pos = rand() % posicoesObstaculos.size();
		Barro* aux = new Barro(posicoesObstaculos[pos]);
		aux->setGG(GG);
		posicoesObstaculos.erase(posicoesObstaculos.begin() + pos);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}

	// Criar armadilhas de urso
	for (int i = 0; i < n_obstaculos; i++)
	{
		int pos = rand() % posicoesObstaculos.size();
		ArmadilhaUrso* aux = new ArmadilhaUrso(posicoesObstaculos[pos]);
		aux->setGG(GG);
		posicoesObstaculos.erase(posicoesObstaculos.begin() + pos);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}
}