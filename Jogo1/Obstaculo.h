#pragma once
#include "Entidade.h"
class Obstaculo :
    public Entidade
{
protected:
    int dano;
public:
    Obstaculo();
    ~Obstaculo();

    virtual void executar() = 0;
};

