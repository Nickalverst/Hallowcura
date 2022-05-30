#pragma once
#include "Inimigo.h"
class Zumbi :
    public Inimigo
{
private:

public:
    Zumbi();
    ~Zumbi();

    virtual void executar();
};

