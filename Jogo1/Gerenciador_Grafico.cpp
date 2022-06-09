#include "Gerenciador_Grafico.h"
// explicar namespaces
Gerenciador_Grafico::Gerenciador_Grafico():
	window(VideoMode(1600, 900), "Game title!")
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
	
	f->imprimirEntidades();

	window.display();
}

void Gerenciador_Grafico::desenhar(Menu* m)
{
	window.clear();

	m->imprimir_se();

	Text *t = m->getMenu();
	for (int i = 0; i < m->getMaxItens(); i++)
	{
		window.draw(t[i]);
	}

	window.display();
}

void Gerenciador_Grafico::desenhar(RectangleShape body)
{
	window.draw(body);
}

void Gerenciador_Grafico::desenhar(Sprite s)
{
	window.draw(s);
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