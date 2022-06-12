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

public:
    UFO(Vector2f pos);
    ~UFO();

    virtual void executar();
    Laser* atirar(Vector2f alvo);
    virtual void corrigirPosicao(Vector2f p);
};
