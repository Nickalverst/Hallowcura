#include "Olho.h"

Olho::Olho(Vector2f pos) :
	Inimigo(pos),
    velocidadeVoo(10),
    alturaVoo(pos.y),
    laser()
{
    raioPatrulha = 300;
    pontoInicial = pos.x;

    if (!tex.loadFromFile("assets/olho_idle.png"))
    {
        cerr << "Erro ao carregar a textura do olho. " << endl;
    }

    gravidade = 0.25f;
    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y));
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

Laser* Olho::atirar(Vector2f alvo)
{
    Laser* aux = new Laser(sprite.getPosition(), alvo);
    laser = aux;
    return aux;
}

const Laser* Olho::getLaser() const
{
    return laser;
}
