#include "Oleo.h"

Oleo::Oleo(Vector2f pos):
	ObstaculoDeslizante(1.05f)
{
    sprite.setPosition(pos);
    if (!tex.loadFromFile("assets/oleo.png"))
    {
        cerr << "Erro ao carregar a textura do oleo. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Oleo::~Oleo()
{
}

void Oleo::executar()
{
}
