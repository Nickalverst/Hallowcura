#include "Zumbi.h"

Zumbi::Zumbi():
	Inimigo(Vector2f(250.f, 250.f))
{
    if (!tex.loadFromFile("assets/zumbi_andando.png"))
    {
        cerr << "Erro ao carregar a textura do zumbi. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float) tex.getSize().x / 2, (float) tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Zumbi::~Zumbi()
{
}

void Zumbi::executar()
{
    // Gravidade
    if (sprite.getPosition().y + sprite.getLocalBounds().height < alturaChao) // Objeto est� no ar
    {
        cout << "posicao y: " << sprite.getPosition().y << endl;
        velocidade.y += gravidade;
    }
    else // Objeto est� no ch�o
    {
        velocidade.y = 0;
    }

    sprite.move(velocidade);
}