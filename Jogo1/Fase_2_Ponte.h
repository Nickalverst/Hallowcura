#pragma once
#include "Fase.h"
#include "UFO.h"
class Fase_2_Ponte :
    public Fase
{
private:
    Jogador* j;
public:
    Fase_2_Ponte(Gerenciador_Grafico* g, Jogador* j);
    ~Fase_2_Ponte();

    virtual void executar();
    
    void criarEntidades();
};

