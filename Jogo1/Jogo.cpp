#include "Jogo.h"

Jogo::Jogo() :
    GG(),
    jogador(Vector2f(500.f, 800.f)),
    fase1(&GG, &jogador),
    fase2(&GG, &jogador),
    menu(),
    estadoAtual("menu"),
    pausado(false)
{
    menu.setGG(&GG);
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
            switch (event.type)
            {
                case Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case Keyboard::Up:
                        menu.moverCima();
                        break;
                    case Keyboard::Down:
                        menu.moverBaixo();
                        break;
                    case Keyboard::Return:
                        switch (menu.getItemPressionado())
                        {
                        case 0:
                            estadoAtual = "fase1";
                            cout << "Apertou jogar fase 1. " << endl;
                            break;
                        case 1:
                            estadoAtual = "fase2";
                            cout << "Apertou jogar fase 2. " << endl;
                            break;
                        case 2:
                            estadoAtual = "ranking";
                            cout << "Ranking. " << endl;
                            break;
                        case 3:
                            estadoAtual = "sair";
                            cout << "Clicou fechar. " << endl;
                            break;
                        }
                        break;
                    case Keyboard::Escape:
                        cout << "ESC: Pausando o jogo..." << endl;
                        pausado = !pausado;
                        break;
                    }
                    break;

                case Event::Closed:
                    GG.getWindow()->close();
                    break;
            }
  
        }

        if (!pausado)
        {
            if (estadoAtual == "fase1")
            {
                fase1.executar();
                GG.desenhar(static_cast<Fase*>(&fase1));
            }
            else if (estadoAtual == "fase2")
            {
                fase2.executar();
                GG.desenhar(static_cast<Fase*>(&fase2));
            }
            else if (estadoAtual == "menu")
            {
                GG.desenhar(&menu);
            }
        }
    }
}

const Jogador* Jogo::getJogador() const
{
    return (&jogador);
}
