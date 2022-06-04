#pragma once
#include "Entidade.h"

class Laser :
    public Entidade
{
private:
    Vector2f alvo;
public:
    Laser(Vector2f pos, Vector2f a);
    ~Laser();

    virtual void executar();
};

