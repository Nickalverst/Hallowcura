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
    // Colis�es com inimigos
    for (int i = 0; i < LIs.size(); i++)
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
                cout << LIs[i]->getID() << endl;
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
                if (j1->getVida() <= 0)
                {
                    //f->removerEntidade(static_cast<Entidade*>(j1));
                }
            }
        }
    }

    // Colis�es de obst�culos
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
        
        int j = 0;
        // Com inimigos
        for (vector<Inimigo*>::iterator itIn = LIs.begin(); itIn != LIs.end(); itIn++, j++)
        {
            float difPosX = (*it)->getPosicao().x - (*itIn)->getPosicao().x;
            float difPosY = (*it)->getPosicao().y - (*itIn)->getPosicao().y;
            if (abs(difPosX) <= ((*it)->getTamanho().x / 2 + (*itIn)->getTamanho().x / 2) &&
                abs(difPosY) <= ((*it)->getTamanho().y / 2 + (*itIn)->getTamanho().y / 2))
            {
                (*it)->afetarPersonagem(static_cast<Personagem*>(*itIn), Vector2f(difPosX, difPosY));
                /*if ((*itIn)->getVida() <= 0)
                {
                    f->removerEntidade(static_cast<Entidade*>(*itIn));
                    LIs.erase(LIs.begin() + j);
                }*/
            }
        }
    }

    // Colis�es com proj�teis
    for (vector<Laser*>::iterator it = LPs.begin(); it != LPs.end(); it++)
    {
        float difPosX = (*it)->getPosicao().x - j1->getPosicao().x;
        float difPosY = (*it)->getPosicao().y - j1->getPosicao().y;
        if (abs(difPosX) <= ((*it)->getTamanho().x / 2 + j1->getTamanho().x / 2) &&
            abs(difPosY) <= ((*it)->getTamanho().y / 2 + j1->getTamanho().y / 2))
        {
            cout << "Colis�o com laser detectada. " << endl;
            j1->operator--(10);
            f->removerEntidade(static_cast<Entidade*>(*it));
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