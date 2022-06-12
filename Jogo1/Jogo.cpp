#include "Jogo.h"

Jogo::Jogo() :
    GG(),
    jogador(Vector2f(50.f, 800.f)),
    fase1(nullptr),
    fase2(nullptr),
    menu(),
    estadoAtual("menu"),
    pausado(false),
    chefaoCriado(false)
{
    menu.setGG(&GG);
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
                            fase1 = new Fase_1_Floresta(&GG, &jogador);
                            estadoAtual = "fase1";
                            cout << "Apertou jogar fase 1. " << endl;
                            break;
                        case 1:
                            fase2 = new Fase_2_Ponte(&GG, &jogador);
                            estadoAtual = "fase2";
                            cout << "Apertou jogar fase 2. " << endl;
                            break;
                        case 2:
                            estadoAtual = "ranking";
                            cout << "Ranking. " << endl;
                            break;
                        case 3:
                            cout << "SAIR: Encerrando... " << endl;
                            exit(0);
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
            if (estadoAtual == "menu")
            {
                GG.desenhar(&menu);
            }
            else if (estadoAtual == "fase1")
            {
                fase1->executar();
                GG.desenhar(static_cast<Fase*>(fase1));
                if (Inimigo::getContadorInimigos() == 0)
                {
                    fase2 = new Fase_2_Ponte(&GG, &jogador);
                    estadoAtual = "fase2";
                    //delete(fase1);
                }
            }
            else if (estadoAtual == "fase2")
            {
                fase2->executar();
                GG.desenhar(static_cast<Fase*>(fase2));
                if (Inimigo::getContadorInimigos() == 0 && !chefaoCriado)
                {
                    fase2->criarChefao();
                    chefaoCriado = true;

                }
                else if (Inimigo::getContadorInimigos() == 1 && chefaoCriado)
                {
                    estadoAtual = "menu";
                }
            }
        }
    }
}

const Jogador* Jogo::getJogador() const
{
    return (&jogador);
}
