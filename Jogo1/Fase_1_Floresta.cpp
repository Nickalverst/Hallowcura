#include "Fase_1_Floresta.h"

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g, Jogador* j) :
	Fase(g, j)
{
	// Fundo de tela
	try {
		if (!tex.loadFromFile("assets/floresta.png"))
		{
			throw "Erro ao carregar a textura da fase Floresta. ";
		}
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
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
	// Criar plataformas
	vector<Vector3f> posicaoPlataforma;

	posicaoPlataforma.push_back(Vector3f(1600 / 2, 900 - 32, 125));
	posicaoPlataforma.push_back(Vector3f(200 * 4, 153 * 4, 15));
	posicaoPlataforma.push_back(Vector3f(62  * 4, 153 * 4, 14));
	posicaoPlataforma.push_back(Vector3f(337 * 4, 153 * 4, 14));
	posicaoPlataforma.push_back(Vector3f(128 * 4, 89  * 4, 12));
	posicaoPlataforma.push_back(Vector3f(272 * 4, 89  * 4, 12));
	posicaoPlataforma.push_back(Vector3f(200 * 4, 89  * 4, 11));

	for (int i = 0; i < (int) posicaoPlataforma.size(); i++)
	{
		Plataforma* aux = new Plataforma(GG, posicaoPlataforma[i]);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}

	int n_obstaculos = (rand() % 4) + 3;

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

	cout << Inimigo::getContadorInimigos() << endl;
}