#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:
    float velocidadePulo;
    bool pulando;
    Texture jogador_pulando,
        jogador_andando,
        jogador_morto;

public:
    Jogador(Vector2f position);
    ~Jogador();

    virtual void executar();
    void pular();
};

