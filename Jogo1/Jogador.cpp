#include "Jogador.h"

Jogador::Jogador(Vector2f position) :
    Personagem(position),
    velocidadePulo(15.f),
    pulando(false)
{
    if (!tex.loadFromFile("assets/jogador_idle.png"))
    {
        cerr << "Erro ao carregar a textura do jogador. " << endl;
    }

    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float) tex.getSize().x/2, (float) tex.getSize().y));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Jogador::~Jogador()
{
}

void Jogador::executar()
{
    // Pulo
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        if (!pulando) pular();
    }

    // Movimento para a esquerda
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        if (olhandoDireita)
        {
            olhandoDireita = false;
            sprite.setScale(Vector2f(-SIZE, SIZE));
        }
        velocidade.x -= aceleracao;
    }
    else if (velocidade.x < 0.f && velocidade.x + desaceleracao < 0.f)
    {
        velocidade.x += desaceleracao;
    }

    // Movimento para baixo
    if (Keyboard::isKeyPressed(Keyboard::S))
    {

    }

    // Movimento para a direita
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        if (!olhandoDireita)
        {
            olhandoDireita = true;
            sprite.setScale(Vector2f(SIZE, SIZE));
        }
        velocidade.x += aceleracao;
    }
    else if (velocidade.x > 0.f && velocidade.x - desaceleracao > 0.f)
    {
        velocidade.x -= desaceleracao;
    }

    if (Keyboard::isKeyPressed(Keyboard::Space))
    {

    }
    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {

    }

    if (abs(velocidade.x) > velocidadeMaxima)
    {
        (velocidade.x > 0) ? velocidade.x = velocidadeMaxima : velocidade.x = -velocidadeMaxima;
    }

    if (abs(velocidade.x) < desaceleracao)
    {
        velocidade.x = 0;
    }

    cout << "Velocidade horizontal do jogador: " << velocidade.x << endl;

    sprite.move(velocidade);

    // Gravidade
    if (sprite.getPosition().y + sprite.getLocalBounds().height < alturaChao) // Objeto está no ar
    {
        velocidade.y += gravidade;
    }
    else // Objeto está no chão
    {
        velocidade.y = 0;
        pulando = false;
    }
}

void Jogador::pular()
{
    velocidade.y = -velocidadePulo;
    pulando = true;
}
