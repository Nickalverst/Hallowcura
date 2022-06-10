#include "UFO.h"

UFO::UFO(Vector2f pos, Gerenciador_Colisao* GC, ListaEntidades* LE, Jogador* j):
	Inimigo(pos), 
    laser(nullptr),
    GC(GC),
    LE(LE),
    j1(j)
{
    if (!tex.loadFromFile("assets/UFO.png"))
    {
        cerr << "Erro ao carregar a textura do UFO. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

UFO::~UFO()
{
}

void UFO::executar()
{ 
    if (laser == nullptr)
        atirar(j1->getPosicao());
    
}

 void UFO::atirar(Vector2f alvo)
{
        Laser* aux = new Laser(sprite.getPosition(), j1->getPosicao());
        laser = aux;
        aux->setGG(GG);
        LE->inserir(static_cast <Entidade*> (aux));
        GC->inserirProjetil(static_cast <Laser*> (aux));
        cout << "atirando" << endl;
}

 bool UFO::getLaser() 
{   if(laser==nullptr)
        return true;
    return false;
}