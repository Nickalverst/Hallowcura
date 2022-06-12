#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{
private:
    float velocidadePulo;
    bool pulando, atacando;
    Texture jogador_pulando,
        jogador_andando,
        jogador_morto,
        jogador_atacando;

public:
    Jogador(Vector2f position);
    ~Jogador();

    virtual void executar();
    void pular();

    void corrigirPosicao(Vector2f pos);
    const bool getAtacando() const { return atacando; }
    void setVida(int vida) { num_vidas = vida; }
};

