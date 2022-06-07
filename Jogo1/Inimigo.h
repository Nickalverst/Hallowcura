#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
protected:
    float raioPatrulha;
    float pontoInicial;

public:
    Inimigo(Vector2f position);
    ~Inimigo();

    virtual void executar() = 0;
};