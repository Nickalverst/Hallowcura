#include "Plataforma.h"

Plataforma::Plataforma(Vector2f pos, int tamanho)
{
    string intstr = to_string(tamanho);

    if (!tex.loadFromFile("assets/plataforma_" + intstr + "u.png"))
    {
        cerr << "Erro ao carregar a textura do barro. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setPosition(pos);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar()
{
}

void Plataforma::afetarJogador(Jogador* j)
{
}
