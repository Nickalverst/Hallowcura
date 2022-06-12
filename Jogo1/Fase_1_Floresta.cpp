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

	posicaoPlataforma.push_back(Vector3f(1600 / 2, 900 - 32, 25));
	posicaoPlataforma.push_back(Vector3f(200 * 4, 153 * 4, 5));
	posicaoPlataforma.push_back(Vector3f(62  * 4, 153 * 4, 4));
	posicaoPlataforma.push_back(Vector3f(337 * 4, 153 * 4, 4));
	posicaoPlataforma.push_back(Vector3f(128 * 4, 89  * 4, 2));
	posicaoPlataforma.push_back(Vector3f(272 * 4, 89  * 4, 2));
	posicaoPlataforma.push_back(Vector3f(200 * 4, 89  * 4, 1));

	for (int i = 0; i < (int) posicaoPlataforma.size(); i++)
	{
		Plataforma* aux = new Plataforma(GG, posicaoPlataforma[i]);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}

	int n_obstaculos = (rand() % 5) + 3;

	// Possíveis posições de spawn dos obstaculos
	vector<Vector2f> posicoesObstaculos;
	for (int i = 200; i < 1600; i += 100)
	{
		posicoesObstaculos.push_back(Vector2f((float)i, 900 - 55));
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

	cout << Inimigo::getContadorInimigos() << endl;
}