#pragma once
#include "Obstaculo.h"
#include "Gerenciador_Grafico.h"

class Plataforma :
    public Obstaculo
{
private:

public:
    Plataforma(Vector3f pos);
    ~Plataforma();

    void executar();
    virtual void afetarPersonagem(Personagem* p, Vector2f dPos);
};