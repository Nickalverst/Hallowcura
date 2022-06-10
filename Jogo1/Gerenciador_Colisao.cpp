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
    for (vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++)
    {
        float difPosX = (*it)->getPosicao().x - j1->getPosicao().x;
        float difPosY = (*it)->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= SIZE*((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= SIZE*((*it)->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            (*it)->atacar(j1, difPosX);
        }
    }

    // Colisões com obstáculos
    for (list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++)
    {
        float difPosX = (*it)->getPosicao().x - j1->getPosicao().x;
        float difPosY = (*it)->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= SIZE * ((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= SIZE * ((*it)->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            (*it)->afetarJogador(j1);
        }
    }

    // Colisões com projéteis
    for (vector<Laser*>::iterator it = LPs.begin(); it != LPs.end(); it++)
    {
        float difPosX = (*it)->getPosicao().x - j1->getPosicao().x;
        float difPosY = (*it)->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= SIZE * ((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= SIZE * ((*it)->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            j1->operator--(10);
            f->removerEntidade(static_cast<Entidade*>(*it));
            cout << "Colisão com projétil detectada. " << endl;
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