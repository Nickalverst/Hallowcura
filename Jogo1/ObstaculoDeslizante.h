#pragma once
#include "Obstaculo.h"
class ObstaculoDeslizante :
    public Obstaculo
{
protected:
    float taxaAtrito;

public:
    ObstaculoDeslizante(float a);
    ~ObstaculoDeslizante();

    virtual void executar() = 0;
};

