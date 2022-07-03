#pragma once
#include "Inimigo.h"
class Zumbi :
    public Inimigo
{
private:

public:
    Zumbi(Vector2f pos);
    ~Zumbi();

    virtual void executar();
    virtual void corrigirPosicao(Vector2f pos);
};

