#include "Inimigo.h"

Inimigo::Inimigo(Vector2f position):
	Personagem(position),
	raioPatrulha(),
	pontoInicial()
{
	dano = 5;
	contador_inimigos++;
}

Inimigo::~Inimigo()
{
	cout << "decrementando esse negocio" << endl;
	contador_inimigos--;
}

const int Inimigo::getContadorInimigos()
{
	return contador_inimigos;
}

int Inimigo::contador_inimigos(0);
