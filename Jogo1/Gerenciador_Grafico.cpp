#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico():
	window(VideoMode(1280, 720), "Game title!")
{
	window.setVerticalSyncEnabled(true);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	
}

void Gerenciador_Grafico::desenhar(Entidade* e)
{
	e->imprimir_se();
}

void Gerenciador_Grafico::desenhar(Fase* f)
{
	window.clear();

	f->imprimir_se();
	
	f->imprimirEntidades(); // O problema está aqui

	window.display();
}

void Gerenciador_Grafico::desenhar(RectangleShape body)
{
	window.draw(body);
}

const bool Gerenciador_Grafico::isOpen() const
{
	return window.isOpen();
}

bool Gerenciador_Grafico::pollEvent(Event e)
{
	return window.pollEvent(e);
}

void Gerenciador_Grafico::close()
{
	window.close();
}