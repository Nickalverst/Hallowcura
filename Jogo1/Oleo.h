#pragma once
#include "ObstaculoDeslizante.h"
class Oleo :
    public ObstaculoDeslizante
{
private:

public:
    Oleo();
    ~Oleo();

    virtual void executar();
};

