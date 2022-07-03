#pragma once
#include "Obstaculo.h"

class ArmadilhaUrso :
    public Obstaculo
{
private:

public:
    ArmadilhaUrso(Vector2f pos);
    ~ArmadilhaUrso();

    virtual void executar();
    virtual void afetarPersonagem(Personagem* p, Vector2f dPos);
};

