#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:

public:
    Jogador(Vector2f position);
    ~Jogador();

    virtual void executar();

};
