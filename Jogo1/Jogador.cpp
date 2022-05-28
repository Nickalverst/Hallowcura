#include "Jogador.h"

Jogador::Jogador(Vector2f position) :
    Personagem(position, Vector2f(50.f, 50.f), Color::Blue),
    velocidadePulo(15.f),
    pulando(false)
{
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

    body.move(velocidade);

    /// LOCAL TEMPORÁRIO ///
    float gravity = 1.f;
    float groundHeight = 720;//(float)window->getSize().y;
    /// LOCAL TEMPORÁRIO ///

    // Gravidade
    if (body.getPosition().y + body.getSize().y < groundHeight) // Objeto está no ar
    {
        velocidade.y += gravity;
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
