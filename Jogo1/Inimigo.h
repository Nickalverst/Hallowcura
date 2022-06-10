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
    static int contador_inimigos;
    
public:
    Inimigo(Vector2f position);
    ~Inimigo();

    virtual void executar() = 0;
    void atacar(Jogador* j, float difPosX);
    static const int getContadorInimigos();
};