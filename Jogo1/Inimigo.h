#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
private:

public:
    Inimigo(Vector2f position, Vector2f size, Color c);
    ~Inimigo();

    virtual void executar() = 0;
};