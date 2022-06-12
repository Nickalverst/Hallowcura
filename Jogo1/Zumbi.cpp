#include "Zumbi.h"

Zumbi::Zumbi(Vector2f pos) :
    Inimigo(pos)
{
    num_vidas = 30;
    raioPatrulha = 300;
    pontoInicial = pos.x;

    if (!tex.loadFromFile("assets/zumbi_andando.png"))
    {
        cerr << "Erro ao carregar a textura do zumbi. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float) tex.getSize().x / 2, (float) tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));

    velocidadeMaxima = 1.f;
    velocidade.x = velocidadeMaxima;
}

Zumbi::~Zumbi()
{
}

void Zumbi::executar()
{
    if (sprite.getPosition().x < pontoInicial || getPosicao().x < getTamanho().x)
    {
        if (!olhandoDireita)
        {
            olhandoDireita = true;
            sprite.setScale(Vector2f(SIZE, SIZE));
        }
        velocidade.x += aceleracao;
        //velocidade.x = velocidadeMaxima;
    }
    else if (sprite.getPosition().x > pontoInicial + raioPatrulha || getPosicao().x > 1600 - getTamanho().x / 2)
    {
        if (olhandoDireita)
        {
            olhandoDireita = false;
            sprite.setScale(Vector2f(-SIZE, SIZE));
        }

        velocidade.x -= aceleracao; // -velocidadeMaxima;
    }

    velocidade.y += gravidade;

    sprite.move(velocidade);
    teleporteParedes();
}

void Zumbi::corrigirPosicao(Vector2f pos)
{
    if (velocidade.y > 0)
    {
        sprite.setPosition(pos);
        velocidade.y = 0;
    }
}