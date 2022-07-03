#pragma once
#include "ObstaculoDeslizante.h"
class Oleo :
    public ObstaculoDeslizante
{
private:

public:
    Oleo(Vector2f pos);
    ~Oleo();

    virtual void executar();
};