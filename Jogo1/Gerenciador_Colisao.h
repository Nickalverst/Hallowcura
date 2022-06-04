#pragma once
#include <vector>
#include <list>
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"

class Gerenciador_Colisao
{
private:
    vector<Inimigo*> LIs;
    list<Obstaculo*> LOs;
    Jogador* j1;

public:
    Gerenciador_Colisao(Jogador* j1);
    ~Gerenciador_Colisao();

    void Colisao();

    void inserirInimigo(Inimigo* ini);
    void inserirObstaculo(Obstaculo* obs);
};

