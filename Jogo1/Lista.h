#pragma once
#include "Elemento.h"
#include <iostream>
using namespace std;

template<class TL>
class Lista
{
private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

public:
    Lista();
    ~Lista();

    void limpar();

    bool incluaElemento(Elemento<TL>* pElemento);
    bool incluaInfo(TL* pInfo);

    Elemento<TL>* getPrimeiro() const;
    Elemento<TL>* getUltimo() const;
};

template<class TL>
Lista<TL>::Lista():
    pPrimeiro(nullptr),
    pUltimo(nullptr)
{
}

template<class TL>
Lista<TL>::~Lista()
{
    limpar();
}

template<class TL>
void Lista<TL>::limpar()
{
    Elemento<TL>* pAux1 = pPrimeiro;
    Elemento<TL>* pAux2 = nullptr;

    while (pAux1 != nullptr)
    {
        pAux2 = pAux1->getProximo();
        if (pAux1 != nullptr)
        {
            if (pAux1->getInfo() != nullptr)
            {
                delete(pAux1->getInfo());
                pAux1->setInfo(nullptr);
            }
            delete(pAux1);
            pAux1 = nullptr;
        }
        pAux1 = pAux2;
    }

    pPrimeiro = nullptr;
    pUltimo = nullptr;
}

template<class TL>
bool Lista<TL>::incluaElemento(Elemento<TL>* pElemento)
{
    if (nullptr != pElemento)
    {
        if (nullptr == pPrimeiro)
        {
            pPrimeiro = pElemento;
            pUltimo = pElemento;
        }
        else
        {
            pUltimo->setProximo(pElemento);
            pUltimo = pElemento;
        }

        return true;
    }
    else
    {
        cerr << "Erro: tentativa de inserção de elemento nulo na lista. Origem da mensagem: \"Lista.h\". " << endl;
        return false;
    }
}

template<class TL>
bool Lista<TL>::incluaInfo(TL* pInfo)
{
    if (nullptr != pInfo)
    {
        Elemento<TL>* pElemento = nullptr;
        pElemento = new Elemento<TL>();
        pElemento->setInfo(pInfo);
        incluaElemento(pElemento);
        return true;
    }
    else
    {
        cerr << "Erro: tentativa de inclusão de conteúdo nulo na lista. Origem da mensagem: \"Lista.h\". " << endl;
        return false;
    }
}

template<class TL>
Elemento<TL>* Lista<TL>::getPrimeiro() const
{
    return pPrimeiro;
}

template<class TL>
Elemento<TL>* Lista<TL>::getUltimo() const
{
    return pUltimo;
}
