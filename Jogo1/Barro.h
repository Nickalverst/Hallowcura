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
    virtual void afetarPersonagem(Personagem* p, Vector2f deltaPos);
};

