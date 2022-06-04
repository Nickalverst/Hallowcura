#include "Gerenciador_Colisao.h"

Gerenciador_Colisao::Gerenciador_Colisao(Jogador* j1)
{
    this->j1 = j1;
}

Gerenciador_Colisao::~Gerenciador_Colisao()
{
}

void Gerenciador_Colisao::Colisao()
{
    for (vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++)
    {
        if (abs((*it)->getPosicao().x - j1->getPosicao().x) <= ((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) /*&&
            abs((*it)->getPosicao().y - j1->getPosicao().y) <= ((*it)->getTamanho().y + j1->getTamanho().y)*/)
        {
            cout << "Diferença de posicoes: " << abs((*it)->getPosicao().x - j1->getPosicao().x) <<
                "\nTamanho do sprite: " << (*it)->getTamanho().x << endl;
            cout << "Bateu! " << endl;
            
            if (((*it)->getPosicao().x - (*it)->getTamanho().x / 2) <= (j1->getPosicao().x + j1->getTamanho().x / 2) &&
                ((*it)->getPosicao().x + (*it)->getTamanho().x / 2) >= ((j1->getPosicao().x) - j1->getTamanho().x / 2) &&
                ((*it)->getPosicao().y - (*it)->getTamanho().y / 2) <= (j1->getPosicao().y + j1->getTamanho().y / 2) &&
                ((*it)->getPosicao().y + (*it)->getTamanho().y / 2) >= (j1->getPosicao().y - j1->getTamanho().y / 2))
            {
                cout << "Bateu! 2" << endl;
            }
        }
    }

    for (list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++)
    {
        //compara x e y dos obstaculos/inimigos
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