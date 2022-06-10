#pragma once
#include "Inimigo.h"
#include "Laser.h"

class Olho :
    public Inimigo
{
private:
    float velocidadeVoo;
    float alturaVoo;
    Laser* laser;
public:
    Olho(Vector2f pos);
    ~Olho();

    virtual void executar();
    virtual void corrigirPosicao(Vector2f pos);
    void baterAsas();
    Laser* atirar(Vector2f alvo);
    const Laser* getLaser() const;
};

