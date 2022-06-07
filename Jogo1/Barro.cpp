#include "Barro.h"

Barro::Barro(Vector2f pos) :
	ObstaculoDeslizante(0.95f)
{
    sprite.setPosition(pos);
    if (!tex.loadFromFile("assets/barro.png"))
    {
        cerr << "Erro ao carregar a textura do barro. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Barro::~Barro()
{
}

void Barro::executar()
{
}
