#include "UFO.h"

UFO::UFO(Vector2f pos, Gerenciador_Colisao* GC, ListaEntidades* LE, Jogador* j) :
    Inimigo(pos),
    laser(nullptr),
    GC(GC),
    LE(LE),
    j1(j)
{
    num_vidas = 300;
    if (!tex.loadFromFile("assets/ovni.png"))
    {
        cerr << "Erro ao carregar a textura do UFO. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));
}

UFO::~UFO()
{
}

void UFO::executar()
{
    //if (laser == nullptr)
        //atirar(j1->getPosicao());
}

Laser* UFO::atirar(Vector2f alvo)
{
    Laser* aux = new Laser(sprite.getPosition(), alvo);
    laser = aux;
    return aux;
}

void UFO::corrigirPosicao(Vector2f p)
{
    sprite.setPosition(p);
}