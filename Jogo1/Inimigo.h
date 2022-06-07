#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo :
    public Personagem
{
protected:
    float raioPatrulha;
    float pontoInicial;
    int dano;

public:
    Inimigo(Vector2f position);
    ~Inimigo();

    virtual void executar() = 0;
    void atacar(Jogador* j, float difPosX);
};