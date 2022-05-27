#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico():
	window(VideoMode(1280, 720), "Game title!")
{
	window.setVerticalSyncEnabled(true);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	
}

void Gerenciador_Grafico::desenhar(ListaEntidades* le)
{
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

void Gerenciador_Grafico::clear()
{
	window.clear();
}

void Gerenciador_Grafico::display()
{
	window.display();
}
