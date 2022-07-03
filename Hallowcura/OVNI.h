#pragma once
#include "Inimigo.h"
#include "Laser.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisao.h"

using namespace Gerenciadores;

class OVNI :
    public Inimigo
{
private:

public:
    OVNI(Vector2f pos);
    ~OVNI();

    virtual void executar();
    Laser* atirar(Vector2f alvo);
    virtual void corrigirPosicao(Vector2f p);
};
