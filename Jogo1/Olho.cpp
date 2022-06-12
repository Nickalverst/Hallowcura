#include "Olho.h"

Olho::Olho(Vector2f pos) :
	Inimigo(pos),
    velocidadeVoo(5),
    alturaVoo(pos.y)
{
    num_vidas = 15;
    raioPatrulha = 300;
    pontoInicial = pos.x;

    if (!tex.loadFromFile("assets/olho_idle.png"))
    {
        cerr << "Erro ao carregar a textura do olho. " << endl;
    }

    gravidade = 0.15f;
    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));

    velocidadeMaxima = 1.f;
    velocidade.x = velocidadeMaxima;
}

Olho::~Olho()
{
}

void Olho::executar()
{
    if (sprite.getPosition().x < pontoInicial)
    {
        if (!olhandoDireita)
        {
            olhandoDireita = true;
            sprite.setScale(Vector2f(SIZE, SIZE));
        }

        velocidade.x = velocidadeMaxima;
    }
    else if (sprite.getPosition().x > pontoInicial + raioPatrulha)
    {
        if (olhandoDireita)
        {
            olhandoDireita = false;
            sprite.setScale(Vector2f(-SIZE, SIZE));
        }

        velocidade.x = -velocidadeMaxima;
    }

    velocidade.y += gravidade;

    if (sprite.getPosition().y + sprite.getLocalBounds().height > alturaVoo)
    {
        baterAsas();
    }

    sprite.move(velocidade);
    teleporteParedes();
}

void Olho::corrigirPosicao(Vector2f pos)
{
    if (velocidade.y > 0)
    {
        sprite.setPosition(pos);
        baterAsas();
    }
}

void Olho::baterAsas()
{
    velocidade.y = -velocidadeVoo;
}

Laser* Olho::atirar(Vector2f alvo)
{
    Laser* aux = new Laser(sprite.getPosition(), alvo);
    return aux;
}