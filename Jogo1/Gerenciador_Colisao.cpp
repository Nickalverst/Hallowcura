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
        float difPosX = (*it)->getPosicao().x - j1->getPosicao().x;
        float difPosY = (*it)->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= SIZE*((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= SIZE*((*it)->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            cout << "Bateu! " << endl;
            //(*it)->atacar();
            // j1->tomarDano(difPosX); tirar vida e dar stagger
            /* Dentro da função tomar dano :
                if (difPosX > 0)
                {
                    cout << "Bateu pela esquerda. " << endl;
                }
                else
                {
                    cout << "Bateu pela direita. " << endl;
                }
            */
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