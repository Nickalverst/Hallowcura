#include "Zumbi.h"

Zumbi::Zumbi(Vector2f pos):
	Inimigo(pos),
    raioPatrulha(300),
    pontoInicial(pos.x)
{
    if (!tex.loadFromFile("assets/zumbi_andando.png"))
    {
        cerr << "Erro ao carregar a textura do zumbi. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float) tex.getSize().x / 2, (float) tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));

    velocidadeMaxima = 1.f;
    velocidade.x = velocidadeMaxima;
}

Zumbi::~Zumbi()
{
}

void Zumbi::executar()
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

    // Gravidade
    if (sprite.getPosition().y + sprite.getLocalBounds().height < alturaChao) // Objeto está no ar
    {
        velocidade.y += gravidade;
    }
    else // Objeto está no chão
    {
        sprite.setPosition(Vector2f(sprite.getPosition().x, alturaChao - sprite.getLocalBounds().height));
        velocidade.y = 0.0f;
    }

    sprite.move(velocidade);
}