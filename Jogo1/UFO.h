#pragma once
#include "Inimigo.h"
class UFO :
    public Inimigo
{
private:

public:
    UFO(Vector2f pos);
    ~UFO();

    virtual void executar();
};

