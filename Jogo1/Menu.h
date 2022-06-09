#pragma once
#define MAX_ITENS 4

#include "Ente.h"
class Menu :
    public Ente
{
private:
    int indiceItemSelecionado;
    Font fonte;
    Text menu[MAX_ITENS];

public:
    Menu();
    ~Menu();

    void moverCima();
    void moverBaixo();

    Text* getMenu();
    int getMaxItens() const;

    int getItemPressionado() const;

    virtual void executar();
};

