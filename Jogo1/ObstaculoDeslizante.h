#pragma once
#include "Obstaculo.h"
#include "Personagem.h"
class ObstaculoDeslizante :
    public Obstaculo
{
protected:
    float taxaAtrito;

public:
    ObstaculoDeslizante(float a);
    ~ObstaculoDeslizante();

    virtual void executar() = 0;

    virtual void afetarPersonagem(Personagem* p, Vector2f dPos);
    void aplicarDeslize(Personagem* p);
};

