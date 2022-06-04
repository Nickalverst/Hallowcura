#pragma once
#include "Inimigo.h"
class Zumbi :
    public Inimigo
{
private:
    float raioPatrulha;
    float pontoInicial;

public:
    Zumbi(Vector2f pos);
    ~Zumbi();

    virtual void executar();
};

