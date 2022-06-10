#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:
    float velocidadePulo;
    float velocidadeCambaleio;
    bool pulando;
    Texture jogador_pulando,
        jogador_andando,
        jogador_morto;

public:
    Jogador(Vector2f position);
    ~Jogador();

    virtual void executar();
    void pular();

    void tomarDano(int dano, float difPosX = 0);

    void corrigirPosicao(Vector2f pos);
};

