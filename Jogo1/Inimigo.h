#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
private:

public:
    Inimigo(Vector2f position);
    ~Inimigo();

    virtual void executar() = 0;
};