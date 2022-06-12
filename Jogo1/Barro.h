#pragma once
#include "ObstaculoDeslizante.h"
class Barro :
    public ObstaculoDeslizante
{
private:

public:
    Barro(Vector2f pos);
    ~Barro();

    virtual void executar();
};

