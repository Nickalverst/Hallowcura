#pragma once
#include "Entidade.h"
#include "Jogador.h"

class Obstaculo :
    public Entidade
{
protected:
    int dano;
public:
    Obstaculo(int dano = 0);
    ~Obstaculo();

    virtual void executar() = 0;
    virtual void afetarJogador(Jogador* j) = 0;
};