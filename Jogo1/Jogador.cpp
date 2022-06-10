#include "Jogador.h"

Jogador::Jogador(Vector2f position) :
    Personagem(position),
    velocidadePulo(17.5f),
    velocidadeCambaleio(5.f),
    pulando(false)
{
    if (!tex.loadFromFile("assets/jogador_idle.png"))
    {
        cerr << "Erro ao carregar a textura principal do jogador. " << endl;
    }

    if (!jogador_pulando.loadFromFile("assets/jogador_pulando.png") ||
        !jogador_andando.loadFromFile("assets/jogador_andando.png") ||
        !jogador_morto.loadFromFile("assets/jogador_morto.png"))
    {
        cerr << "Erro ao carregar texturas do jogador. " << endl;
    }

    num_vidas = 100;
    sprite.setTexture(tex);
    sprite.setOrigin(Vector2f((float) tex.getSize().x/2, (float) tex.getSize().y / 2));
    sprite.scale(Vector2f(SIZE, SIZE));
}

Jogador::~Jogador()
{
}

void Jogador::executar()
{
    sprite.setTexture(tex);
    // Pulo
    if (Keyboard::isKeyPressed(Keyboard::W) ||
        Keyboard::isKeyPressed(Keyboard::Up))
    {
        if (!pulando) pular();
    }

    // Movimento para a esquerda
    if (Keyboard::isKeyPressed(Keyboard::A) ||
        Keyboard::isKeyPressed(Keyboard::Left))
    {
        if (olhandoDireita)
        {
            olhandoDireita = false;
            sprite.setScale(Vector2f(-SIZE, SIZE));
        }

        sprite.setTexture(jogador_andando);
        velocidade.x -= aceleracao;
    }
    else if (velocidade.x < 0.f && velocidade.x + desaceleracao < 0.f)
    {
        velocidade.x += desaceleracao;
    }

    // Movimento para a direita
    if (Keyboard::isKeyPressed(Keyboard::D) ||
        Keyboard::isKeyPressed(Keyboard::Right))
    {
        if (!olhandoDireita)
        {
            olhandoDireita = true;
            sprite.setScale(Vector2f(SIZE, SIZE));
        }

        sprite.setTexture(jogador_andando);
        velocidade.x += aceleracao;
    }
    else if (velocidade.x > 0.f && velocidade.x - desaceleracao > 0.f)
    {
        velocidade.x -= desaceleracao;
    }

    if (Keyboard::isKeyPressed(Keyboard::F))
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
        sprite.setTexture(tex);
    }

    sprite.move(velocidade);

    velocidade.y += gravidade;

    if (pulando) sprite.setTexture(jogador_pulando);
}

void Jogador::pular()
{
    sprite.setTexture(jogador_pulando);
    velocidade.y = -velocidadePulo;
    pulando = true;
}

void Jogador::tomarDano(int dano, float difPosX)
{
    if (difPosX > 0) velocidade.x = -velocidadeCambaleio;
    else if (difPosX < 0) velocidade.x = velocidadeCambaleio; // Velocidade oposta ao inimigo
    operator--(dano);
}

void Jogador::corrigirPosicao(Vector2f pos)
{
    if (velocidade.y > 0)
    {
        sprite.setPosition(pos);
        velocidade.y = 0;
        pulando = false;
    }
}
