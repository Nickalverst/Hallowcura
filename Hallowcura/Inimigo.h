#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo :
    public Personagem
{
protected:
    float raioPatrulha;
    float pontoInicial;
    static int contador_inimigos;
    
public:
    Inimigo(Vector2f position);
    virtual ~Inimigo();

    virtual void executar() = 0;
    static const int getContadorInimigos();
};