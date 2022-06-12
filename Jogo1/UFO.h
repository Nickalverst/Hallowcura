#pragma once
#include "Inimigo.h"
#include "Laser.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisao.h"

using namespace Gerenciadores;

class UFO :
    public Inimigo
{
private:
    ListaEntidades* LE;
    Gerenciador_Colisao* GC;
    Laser* laser;
    Jogador* j1;
public:
    UFO(Vector2f pos, Gerenciador_Colisao* GC, ListaEntidades* LE, Jogador* j);
    ~UFO();

    virtual void executar();
    Laser* atirar(Vector2f alvo);
    virtual void corrigirPosicao(Vector2f p);

    Laser* getLaser() const { return laser; }
};
