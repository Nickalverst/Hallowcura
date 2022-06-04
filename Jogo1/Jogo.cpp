#include "Jogo.h"

Jogo::Jogo() :
    GG(),
    jogador(Vector2f(500.f, 800.f)),
    fase1(&GG, &jogador)
{
    fase1.setGG(&GG);
    jogador.setGG(&GG);

    fase1.incluirEntidades(&jogador);
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (GG.getWindow()->isOpen())
    {
        Event event;
        while (GG.getWindow()->pollEvent(event))
        {
            if (event.type == Event::Closed)
                GG.getWindow()->close();
        }

        fase1.executar();
        GG.desenhar(static_cast<Fase*>(&fase1));
    }
}

const Jogador* Jogo::getJogador() const
{
    return (&jogador);
}
