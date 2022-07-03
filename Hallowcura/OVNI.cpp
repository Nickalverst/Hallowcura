#include "OVNI.h"

OVNI::OVNI(Vector2f pos) :
    Inimigo(pos)
{
    num_vidas = 300;
    if (!tex.loadFromFile("assets/ovni.png"))
    {
        cerr << "Erro ao carregar a textura do OVNI. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));
}

OVNI::~OVNI()
{
}

void OVNI::executar()
{
}

Laser* OVNI::atirar(Vector2f alvo)
{
    Laser* aux = new Laser(sprite.getPosition(), alvo);
    return aux;
}

void OVNI::corrigirPosicao(Vector2f p)
{
    sprite.setPosition(p);
}