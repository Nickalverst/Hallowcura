#include "Gerenciador_Grafico.h"

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

	RectangleShape rec;
	rec.setSize(Vector2f(5, 5));
	rec.setPosition(500.f, 800.f);
	rec.setFillColor(Color::Blue);
	window.draw(rec);

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