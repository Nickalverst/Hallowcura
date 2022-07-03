#include "Gerenciador_Colisao.h"
using Gerenciadores::Gerenciador_Colisao;
#include "Fase.h"

Gerenciador_Colisao::Gerenciador_Colisao(Jogador* j1) :
    LIs(),
    LPs(),
    LOs(),
    j1(j1)
{
}

Gerenciador_Colisao::~Gerenciador_Colisao()
{
}

void Gerenciador_Colisao::Colisao(Fase* f)
{
    // Colisões com inimigos
    for (int i = 0; i < (int) LIs.size(); i++)
    {
        float difPosX = LIs[i]->getPosicao().x - j1->getPosicao().x;
        float difPosY = LIs[i]->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= (LIs[i]->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= (LIs[i]->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            if (j1->getAtacando())
            {
                j1->atacar(LIs[i], -difPosX);
                cout << "Vida restante: " << LIs[i]->getVida() << endl;
                if (LIs[i]->getVida() <= 0)
                {
                    f->removerEntidade(static_cast<Entidade*>(LIs[i]));
                    LIs.erase(LIs.begin() + i);
                    cout << "Contador de inimigos: " << Inimigo::getContadorInimigos() << endl;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                LIs[i]->atacar(j1, difPosX);
            }
        }
    }

    // Colisões de obstáculos
    for (list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++)
    {
        // Com o jogador
        float difPosX = (*it)->getPosicao().x - j1->getPosicao().x;
        float difPosY = (*it)->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= ((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= ((*it)->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            (*it)->afetarPersonagem(static_cast<Personagem*>(j1), Vector2f(difPosX, difPosY));
        }
        
        // Com inimigos
        for (int j = 0; j < (int) LIs.size(); j++)
        {
            float difPosX = (*it)->getPosicao().x - LIs[j]->getPosicao().x;
            float difPosY = (*it)->getPosicao().y - LIs[j]->getPosicao().y;
            if (abs(difPosX) <= ((*it)->getTamanho().x / 2 + LIs[j]->getTamanho().x / 2) &&
                abs(difPosY) <= ((*it)->getTamanho().y / 2 + LIs[j]->getTamanho().y / 2))
            {
                (*it)->afetarPersonagem(static_cast<Personagem*>(LIs[j]), Vector2f(difPosX, difPosY));
                if (LIs[j]->getVida() <= 0)
                {
                    f->removerEntidade(static_cast<Entidade*>(LIs[j]));
                    LIs.erase(LIs.begin() + j);
                }
            }
        }
    }

    // Colisões com projéteis
    for (int i = 0; i < (int) LPs.size(); i)
    {
        float difPosX = LPs[i]->getPosicao().x - j1->getPosicao().x;
        float difPosY = LPs[i]->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= (LPs[i]->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= (LPs[i]->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            cout << "Colisão com laser detectada. " << endl;
            j1->operator--(10);
            f->removerEntidade(static_cast<Entidade*>(LPs[i]));
            LPs.erase(LPs.begin() + i);

            cout << "Tamanho da lista de laser: " << LPs.size() << endl;
        }
        else
        {
            i++;
        }
    }
}

void Gerenciador_Colisao::inserirInimigo(Inimigo* ini)
{
    LIs.push_back(ini);
}

void Gerenciador_Colisao::inserirObstaculo(Obstaculo* obs)
{
    LOs.push_back(obs);
}

void Gerenciador_Colisao::inserirProjetil(Laser* las)
{
    LPs.push_back(las);
}