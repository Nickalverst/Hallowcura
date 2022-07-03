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
	// Criar plataformas
	vector<Vector3f> posicaoPlataforma;

	posicaoPlataforma.push_back(Vector3f(1600 / 2, 900 - 32, 225));
	posicaoPlataforma.push_back(Vector3f(1600 / 2, 153 * SIZE, 23));
	posicaoPlataforma.push_back(Vector3f(72 * SIZE, 153 * SIZE, 23));
	posicaoPlataforma.push_back(Vector3f(328 * SIZE, 153 * SIZE, 23));
	posicaoPlataforma.push_back(Vector3f(24 * SIZE, 105 * SIZE, 21));
	posicaoPlataforma.push_back(Vector3f(136 * SIZE, 105 * SIZE, 21));
	posicaoPlataforma.push_back(Vector3f(264 * SIZE, 105 * SIZE, 21));
	posicaoPlataforma.push_back(Vector3f(376 * SIZE, 105 * SIZE, 21));

	for (int i = 0; i < (int) posicaoPlataforma.size(); i++)
	{
		Plataforma* aux = new Plataforma(posicaoPlataforma[i]);
		aux->setGG(GG);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}

	int n_obstaculos = (rand() % 4) + 3;

	// Criar barros
	for (int i = 0; i < n_obstaculos; i++)
	{
		int pos = rand() % posicoesObstaculos.size();
		Oleo* aux = new Oleo(posicoesObstaculos[pos]);
		aux->setGG(GG);
		posicoesObstaculos.erase(posicoesObstaculos.begin() + pos);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}
}

void Fase_2_Ponte::criarChefao()
{
	cout << "Criando chefe" << endl;
	OVNI* aux = new OVNI(Vector2f(1600 / 2, 100));
	aux->setGG(GG);
	LE.inserir(static_cast<Entidade*>(aux));
	GC.inserirInimigo(static_cast<Inimigo*>(aux));
	
	// Atirar uma vez
	Laser* tiro = aux->atirar(jogador->getPosicao());
	LE.inserir(static_cast<Entidade*>(tiro));
	tiro->setGG(GG);
	GC.inserirProjetil(tiro);

	Zumbi* a2 = new Zumbi(Vector2f(5000, 5000));
	LE.inserir(static_cast<Entidade*>(a2));
	a2->setGG(GG);
	GC.inserirInimigo(static_cast<Inimigo*>(a2));
}
