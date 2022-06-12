#include "Oleo.h"

Oleo::Oleo(Vector2f pos):
	ObstaculoDeslizante(1.01f)
{
    sprite.setPosition(pos);
    if (!tex.loadFromFile("assets/oleo.png"))
    {
        cerr << "Erro ao carregar a textura do barro. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Oleo::~Oleo()
{
}

void Oleo::executar()
{
}
