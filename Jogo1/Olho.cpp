#include "Olho.h"

Olho::Olho(Vector2f pos) :
	Inimigo(pos),
    velocidadeVoo(10),
    alturaVoo(pos.y)
{
    if (!tex.loadFromFile("assets/olho_idle.png"))
    {
        cerr << "Erro ao carregar a textura do zumbi. " << endl;
    }

    gravidade = 0.25f;
    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Olho::~Olho()
{
}

void Olho::executar()
{
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

    if (sprite.getPosition().y + sprite.getLocalBounds().height > alturaVoo)
    {
        baterAsas();
    }

    sprite.move(velocidade);
}

void Olho::baterAsas()
{
    //sprite.setTexture(jogador_pulando);
    velocidade.y = -velocidadeVoo;
}