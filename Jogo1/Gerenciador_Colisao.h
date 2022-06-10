#pragma once
#include <vector>
#include <list>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "ObstaculoDeslizante.h"
#include "Jogador.h"
#include "Laser.h"
class Fase;

namespace Gerenciadores
{
    class Gerenciador_Colisao
    {
    private:
        vector<Inimigo*> LIs;
        vector<Laser*> LPs;
        list<Obstaculo*> LOs;
        Jogador* j1;

    public:
        Gerenciador_Colisao(Jogador* j1);
        ~Gerenciador_Colisao();

        void Colisao(Fase* f);

        void inserirInimigo(Inimigo* ini);
        void inserirObstaculo(Obstaculo* obs);
        void inserirProjetil(Laser* las);
    };
}
