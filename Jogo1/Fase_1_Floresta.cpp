#include "Fase_1_Floresta.h"
#include <cstdlib>
#include <time.h>
#include <stack>

Fase_1_Floresta::Fase_1_Floresta(Gerenciador_Grafico* g, Jogador* j) :
	Fase(j),
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

	// Possíveis posições de spawn do zumbi
	stack<Vector2f> posicoesZumbi;
	
	posicoesZumbi.push(Vector2f(700, 800));
	posicoesZumbi.push(Vector2f(100, 800));
	posicoesZumbi.push(Vector2f(300, 800));
	posicoesZumbi.push(Vector2f(1100, 800));
	posicoesZumbi.push(Vector2f(500, 800));
	posicoesZumbi.push(Vector2f(900, 800));
	

	// Possíveis posições de spawn do olho
	stack<Vector2f> posicoesOlho;
	posicoesOlho.push(Vector2f(300, 300));
	posicoesOlho.push(Vector2f(500, 300));
	posicoesOlho.push(Vector2f(700, 300));
	posicoesOlho.push(Vector2f(900, 300));
	posicoesOlho.push(Vector2f(1100, 300));
	posicoesOlho.push(Vector2f(1300, 300));

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
		Olho* aux = new Olho(posicoesOlho.top());
		aux->setGG(GG);
		posicoesOlho.pop();
		LE.inserir(static_cast<Entidade*>(aux));
		//GC.inserir(static_cast<Inimigo*>(aux));
	}
}