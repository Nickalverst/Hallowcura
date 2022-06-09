#pragma once

#include <string.h>
#include <iostream>
using namespace std;

template<class TE>
class Elemento
{
private:
    Elemento<TE>* pProx;
    TE* pInfo;

public:
    Elemento();
    ~Elemento();

    void setProximo(Elemento<TE>* pp);
    Elemento<TE>* getProximo() const;

    void setInfo(TE* pi);
    TE* getInfo() const;
};

template<class TE>
Elemento<TE>::Elemento()
{
    pProx = nullptr;
    pInfo = nullptr;
}

template<class TE>
Elemento<TE>::~Elemento()
{
    pProx = nullptr;
    pInfo = nullptr;
}

template<class TE>
void Elemento<TE>::setProximo(Elemento<TE>* pp)
{
    if (pp != nullptr)
    {
        pProx = pp;
    }
    else
    {
        cerr << "Erro: ponteiro nulo. Origem da mensagem: setProximo de \"Elemento.h\". " << endl;
    }
}

template<class TE>
Elemento<TE>* Elemento<TE>::getProximo() const
{
    return pProx;
}

template<class TE>
void Elemento<TE>::setInfo(TE* pi)
{
    if (pi != nullptr)
    {
        pInfo = pi;
    }
    else
    {
        cerr << "Erro: ponteiro nulo. Origem da mensagem: setInfo de \"Elemento.h\". " << endl;
    }
}

template<class TE>
TE* Elemento<TE>::getInfo() const
{
    return pInfo;
}
