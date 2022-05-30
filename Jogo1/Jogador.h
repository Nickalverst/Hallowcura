#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:
    float velocidadePulo;
    bool pulando;

public:
    Jogador(Vector2f position);
    ~Jogador();

    virtual void executar();
    void pular();
};

