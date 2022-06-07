#include "Fase_1_Floresta.h"
#include <cstdlib>
#include <time.h>
#include <stack>

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g, Jogador* j) :
	Fase(g, j)
{
	// Fundo de tela
	if (!tex.loadFromFile("assets/floresta.png"))
	{
		cerr << "Erro ao carregar a textura da fase. " << endl;
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
	GC.Colisao();
}

void Fase_1_Floresta::criarEntidades()
{
	// Quantidades dos inimigos
	srand((unsigned int) time(0));
	int n_zumbis = (rand() % 3) + 3;
	int n_olhos = (rand() % 3) + 3;
	int n_obstaculos = (rand() % 5) + 3;

	// Poss�veis posi��es de spawn do zumbi
	vector<Vector2f> posicoesZumbi;
	
	posicoesZumbi.push_back(Vector2f(700, 800));
	posicoesZumbi.push_back(Vector2f(100, 800));
	posicoesZumbi.push_back(Vector2f(300, 800));
	posicoesZumbi.push_back(Vector2f(1100, 800));
	posicoesZumbi.push_back(Vector2f(500, 800));
	posicoesZumbi.push_back(Vector2f(900, 800));

	// Poss�veis posi��es de spawn do olho
	vector<Vector2f> posicoesOlho;

	posicoesOlho.push_back(Vector2f(300, 300));
	posicoesOlho.push_back(Vector2f(500, 300));
	posicoesOlho.push_back(Vector2f(700, 300));
	posicoesOlho.push_back(Vector2f(900, 300));
	posicoesOlho.push_back(Vector2f(1100, 300));
	posicoesOlho.push_back(Vector2f(1300, 300));

	// Poss�veis posi��es de spawn do olho
	vector<Vector2f> posicoesObstaculos;

	posicoesObstaculos.push_back(Vector2f(300, 900 - 42));
	posicoesObstaculos.push_back(Vector2f(500, 900 - 42));
	posicoesObstaculos.push_back(Vector2f(700, 900 - 42));
	posicoesObstaculos.push_back(Vector2f(900, 900 - 42));
	posicoesObstaculos.push_back(Vector2f(1100, 900 - 42));
	posicoesObstaculos.push_back(Vector2f(1300, 900 - 42));

	cout << "N�mero de zumbis: " << n_zumbis << ". N�mero de olhos: " << n_olhos << endl;

	// Criar zumbis
	for (int i = 0; i < n_zumbis; i++)
	{	
		int pos = rand() % posicoesZumbi.size();
		Zumbi* aux = new Zumbi(posicoesZumbi[pos]);
		aux->setGG(GG);
		posicoesZumbi.erase(posicoesZumbi.begin() + pos);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirInimigo(static_cast<Inimigo*>(aux));
	}

	// Criar olhos alados
	for (int i = 0; i < n_olhos; i++)
	{
		int pos = rand() % posicoesZumbi.size();
		Olho* aux = new Olho(posicoesOlho[pos]);
		aux->setGG(GG);
		posicoesOlho.erase(posicoesOlho.begin() + pos);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirInimigo(static_cast<Inimigo*>(aux));
		
		// Para teste do disparo: 
		cout << "Mandando atirar... " << endl;
		Laser* tiro = aux->atirar(jogador->getPosicao());
		LE.inserir(static_cast<Entidade*>(tiro));
		tiro->setGG(GG);
		GC.inserirProjetil(tiro);
	}

	// Criar obst�culos
	for (int i = 0; i < n_obstaculos; i++)
	{
		int pos = rand() % posicoesObstaculos.size();
		Barro* aux = new Barro(posicoesObstaculos[pos]);
		aux->setGG(GG);
		posicoesObstaculos.erase(posicoesObstaculos.begin() + pos);
		LE.inserir(static_cast<Entidade*>(aux));
		GC.inserirObstaculo(static_cast<Obstaculo*>(aux));
	}
}