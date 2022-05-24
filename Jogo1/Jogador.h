#pragma once
#include "Entidade.h"
class Jogador :
    public Entidade
{
private:

public:
    Jogador();
    ~Jogador();

    virtual void executar();
};

