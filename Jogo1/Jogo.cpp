#include "Jogo.h"

Jogo::Jogo() :
    GG(),
    window(VideoMode(1280, 720), "Game title!"),
    jogador(Vector2f(500.f, 500.f))
{
    jogador.setWindow(&window);
    window.setVerticalSyncEnabled(true);
    executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Desenhar
        jogador.imprimir_se();
        jogador.executar();

        window.display();
    }
}
