#include "Fase_1_Floresta.h"
#include <cstdlib>
#include <time.h>
#include <stack>

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g) :
	Fase(),
	GG(g)
{
	// Fundo de tela
	if (!tex.loadFromFile("assets/floresta.png"))
	{
		cerr << "Erro ao carregar a textura da fase. " << endl;
	}

	sprite.setTexture(tex);

	criarEntidades();
}

Fase_1_Floresta::~Fase_1_Floresta()
{
}

void Fase_1_Floresta::executar()
{
	LE.executar();
}

void Fase_1_Floresta::criarEntidades()
{
	// Quantidades dos inimigos
	srand(time(0));
	int n_zumbis = (rand() % 6 / 2) + 3;
	int n_olhos = (rand() % 6 / 2) + 3;

	// Poss�veis posi��es de spawn do zumbi
	stack<Vector2f> posicoesZumbi;
	posicoesZumbi.push(Vector2f(50, 150));
	posicoesZumbi.push(Vector2f(100, 150));
	posicoesZumbi.push(Vector2f(150, 150));
	posicoesZumbi.push(Vector2f(200, 150));
	posicoesZumbi.push(Vector2f(250, 150));
	posicoesZumbi.push(Vector2f(300, 150));

	// Poss�veis posi��es de spawn do olho
	stack<Vector2f> posicoesOlho;
	posicoesOlho.push(Vector2f(350, 500));
	posicoesOlho.push(Vector2f(200, 500));
	posicoesOlho.push(Vector2f(400, 500));
	posicoesOlho.push(Vector2f(600, 500));
	posicoesOlho.push(Vector2f(750, 500));
	posicoesOlho.push(Vector2f(800, 500));

	cout << "Zumbis: " << n_zumbis << ". Olhos: " << n_olhos << endl;

	for (int i = 0; i < n_zumbis; i++)
	{	
		Zumbi* aux = new Zumbi(posicoesZumbi.top());
		aux->setGG(GG);
		posicoesZumbi.pop();
		LE.inserir(static_cast<Entidade*>(aux));
		//GC.inserir(static_cast<Inimigo*>(aux));
	}

	// Criar OlhoAlado
	for (int i = 0; i < n_olhos; i++)
	{
		// escolher position na lista de posicoes de olho aleatoriamente
		Olho* aux = new Olho(posicoesOlho.top());
		aux->setGG(GG);
		posicoesOlho.pop();
		LE.inserir(static_cast<Entidade*>(aux));
		//GC.inserir(static_cast<Inimigo*>(aux));
	}
}