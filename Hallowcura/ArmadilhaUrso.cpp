#include "ArmadilhaUrso.h"

ArmadilhaUrso::ArmadilhaUrso(Vector2f pos):
	Obstaculo(dano = 1)
{
    if (!tex.loadFromFile("assets/armadilhaUrso.png"))
    {
        cerr << "Erro ao carregar a textura da armadilha de urso. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE*1.5, SIZE*1.5));
	sprite.setPosition(Vector2f(pos.x, pos.y -18));
}

ArmadilhaUrso::~ArmadilhaUrso()
{
}

void ArmadilhaUrso::executar()
{
}

void ArmadilhaUrso::afetarPersonagem(Personagem* p, Vector2f deltaPos)
{
	p->operator--(dano);
}