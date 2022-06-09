#pragma once
#include "Obstaculo.h"
class Plataforma :
    public Obstaculo
{
private:
public:
    Plataforma(Vector2f pos, int tamanho);
    ~Plataforma();

    void executar();
};

