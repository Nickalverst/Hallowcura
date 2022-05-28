#pragma once
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Fase.h"

class Gerenciador_Grafico
{
private:
	RenderWindow window;

public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	void desenhar(Entidade* e);
	void desenhar(Fase* f);
	void desenhar(RectangleShape b);

	RenderWindow* getWindow() { return &window; };

	const bool isOpen() const;
	bool pollEvent(Event e);
	void close();
};

