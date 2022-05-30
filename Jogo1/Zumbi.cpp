#include "Zumbi.h"

Zumbi::Zumbi():
	Inimigo(Vector2f(250.f, 250.f), Vector2f(30.f, 80.f), Color::Red)
{
}

Zumbi::~Zumbi()
{
}

void Zumbi::executar()
{
    // Gravidade
    if (body.getPosition().y + body.getSize().y < alturaChao) // Objeto est� no ar
    {
        velocidade.y += gravidade;
    }
    else // Objeto est� no ch�o
    {
        velocidade.y = 0;
    }

    body.move(velocidade);
}