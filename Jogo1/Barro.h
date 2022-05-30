#pragma once
#include "Obstaculo.h"
class Barro :
    public Obstaculo
{
private:

public:
    Barro();
    ~Barro();

    virtual void executar();
};

