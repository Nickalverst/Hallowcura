#include "Plataforma.h"

Plataforma::Plataforma(Gerenciador_Grafico* GG, Vector3f pos):
    Obstaculo(0)
{
    setGG(GG);
    string intstr = to_string((int)pos.z);

    sprite.setPosition(Vector2f(pos.x, pos.y));
    if (!tex.loadFromFile("assets/plataforma_" + intstr + "u.png"))
    {
        cerr << "Erro ao carregar a textura do barro. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Plataforma::~Plataforma()
{
}

void Plataforma::executar()
{
}

void Plataforma::afetarJogador(Jogador* j, Vector2f deltaPos)
{
    if (deltaPos.y > 0)
    {
        j->corrigirPosicao(Vector2f(j->getPosicao().x, getPosicao().y - (j->getTamanho().y / 2 + getTamanho().y / 2)));
    }
}
