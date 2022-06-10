#include "Fase.h"

Fase::Fase(Gerenciador_Grafico* g, Jogador* j):
	Ente(),
	LE(),
	GG(g),
	GC(j),
	jogador(j)
{
	criarEntidades();
}

Fase::~Fase()
{
}

void Fase::imprimirEntidades()
{
	LE.imprimir();
}

void Fase::incluirEntidade(Entidade* e)
{
	LE.inserir(e);
}

void Fase::removerEntidade(Entidade* e)
{
	LE.remover(e);
}

void Fase::criarEntidades()
{
	// Quantidades dos inimigos
	srand((unsigned int)time(0));
	int n_zumbis = (rand() % 3) + 3;
	int n_olhos = (rand() % 3) + 3;

	// Possíveis posições de spawn do zumbi
	vector<Vector2f> posicoesZumbi;
	for (int i = 200; i < 1600; i += 100)
	{
		posicoesZumbi.push_back(Vector2f((float)i, 400));
		//posicoesZumbi.push_back(Vector2f((float)i, 400));
	}

	// Possíveis posições de spawn do olho
	vector<Vector2f> posicoesOlho;
	for (int i = 100; i < 1600; i += 100)
	{
		posicoesOlho.push_back(Vector2f((float)i, 200));
	}

	cout << "Número de zumbis: " << n_zumbis << ". Número de olhos: " << n_olhos << endl;

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
}
