#include "Jogo.h"

Jogo::Jogo() :
    GG(),
    jogador(Vector2f(500.f, 500.f)),
    fase1()
{
    fase1.setGG(&GG);
    fase1.incluirEntidades(&jogador);
    jogador.setGG(&GG);
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
        jogador.executar();
        GG.desenhar(static_cast<Fase*>(&fase1));
    }
}
