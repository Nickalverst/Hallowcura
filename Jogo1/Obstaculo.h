#pragma once
#include "Entidade.h"
class Obstaculo :
    public Entidade
{
protected:

public:
    Obstaculo();
    ~Obstaculo();

    virtual void executar() = 0;
};

