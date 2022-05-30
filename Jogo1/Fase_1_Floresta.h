#pragma once
#include "Fase.h"
#include "Zumbi.h"

class Fase_1_Floresta :
    public Fase
{
private:
    Gerenciador_Grafico* GG;
    Zumbi zumbi;

public:
    Fase_1_Floresta(Gerenciador_Grafico* g);
    ~Fase_1_Floresta();

    virtual void executar();
};

