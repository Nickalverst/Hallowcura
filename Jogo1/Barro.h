#pragma once
#include "ObstaculoDeslizante.h"
class Barro :
    public ObstaculoDeslizante
{
private:

public:
    Barro();
    ~Barro();

    virtual void executar();
};

