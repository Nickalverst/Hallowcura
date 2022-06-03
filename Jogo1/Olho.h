#pragma once
#include "Inimigo.h"
class Olho :
    public Inimigo
{
private:
    float velocidadeVoo;
    float alturaVoo;
public:
    Olho(Vector2f pos);
    ~Olho();

    virtual void executar();
    void baterAsas();
};

