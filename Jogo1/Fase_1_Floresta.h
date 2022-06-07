#pragma once
#include "Fase.h"
#include "Zumbi.h"
#include "Olho.h"
#include "Barro.h"

class Fase_1_Floresta :
    public Fase
{
private:

public:
    Fase_1_Floresta(Gerenciador_Grafico* g, Jogador* j);
    ~Fase_1_Floresta();

    virtual void executar();

    void criarEntidades();
};

