#include "UFO.h"

UFO::UFO(Vector2f pos):
    Inimigo(pos)
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
}
