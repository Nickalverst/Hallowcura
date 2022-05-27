#pragma once
#include "ListaEntidades.h"
#include "Entidade.h"

class Gerenciador_Grafico
{
private:
	RenderWindow window;

public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	void desenhar(ListaEntidades* le);

	const bool isOpen() const;

	bool pollEvent(Event e);
	void close();
	void clear();
	void display();
};

