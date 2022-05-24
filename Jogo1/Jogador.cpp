#include "Jogador.h"

Jogador::Jogador(Vector2f position) :
    Personagem(position, Vector2f(50.f,50.f), Color::Blue)
{
}

Jogador::~Jogador()
{
}

void Jogador::executar()
{
    if (Keyboard::isKeyPressed(Keyboard::W))
    {

    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {

    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {

    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {

    }
    else if (Keyboard::isKeyPressed(Keyboard::Space))
    {

    }
    else if (Keyboard::isKeyPressed(Keyboard::Enter))
    {

    }
}
