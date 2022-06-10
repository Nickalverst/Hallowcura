#pragma once
#include "Obstaculo.h"
#include "Jogador.h"
class ObstaculoDeslizante :
    public Obstaculo
{
protected:
    float taxaAtrito;

public:
    ObstaculoDeslizante(float a);
    ~ObstaculoDeslizante();

    virtual void executar() = 0;

    virtual void afetarJogador(Jogador* j, Vector2f deltaPos);
    void aplicarDeslize(Jogador* j);
};

