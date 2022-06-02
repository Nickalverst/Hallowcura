#include "Zumbi.h"

Zumbi::Zumbi():
	Inimigo(Vector2f(250.f, 250.f), Vector2f(30.f, 80.f), Color::Red)
{
    if (!tex.loadFromFile("assets/zumbi.png"))
    {
        cerr << "Erro ao carregar a textura do jogador. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f(tex.getSize().x / 2, tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Zumbi::~Zumbi()
{
}

void Zumbi::executar()
{
    // Gravidade
    if (sprite.getPosition().y + sprite.getLocalBounds().height < alturaChao) // Objeto está no ar
    {
        cout << "posicao y: " << sprite.getPosition().y << endl;
        velocidade.y += gravidade;
    }
    else // Objeto está no chão
    {
        velocidade.y = 0;
    }

    sprite.move(velocidade);
}