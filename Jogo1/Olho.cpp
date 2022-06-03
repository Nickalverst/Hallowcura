#include "Olho.h"

Olho::Olho(Vector2f pos) :
	Inimigo(pos),
    velocidadeVoo(15),
    alturaVoo(500)
{
    if (!tex.loadFromFile("assets/olho_idle.png"))
    {
        cerr << "Erro ao carregar a textura do zumbi. " << endl;
    }

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
        cout << "Tamanho y da textura: " << sprite.getPosition().y << endl;
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