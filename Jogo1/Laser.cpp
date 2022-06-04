#include "Laser.h"
#include <cmath>

Laser::Laser(Vector2f pos, Vector2f a):
	Entidade(pos),
	alvo(a)
{
	if (!tex.loadFromFile("assets/laser.png"))
	{
		cerr << "Erro ao carregar a textura do zumbi. " << endl;
	}

	sprite.setTexture(tex);
	sprite.setOrigin(Vector2f((float)tex.getSize().x / 2, (float)tex.getSize().y));
	sprite.scale(Vector2f(SIZE, SIZE));

	velocidadeMaxima = 5.f;
	
	Vector2f direcao = a - pos;
	float norma = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
	direcao /= norma;
	velocidade = direcao * velocidadeMaxima;
	float angulo = atan(direcao.y / direcao.x) * (180.0 / (2*acos(0.f))); // 2 * acos(0) = pi
	cout << "Angulo: " << angulo << endl;
	sprite.setRotation(angulo);
}

Laser::~Laser()
{
}

void Laser::executar()
{
	sprite.move(velocidade);
}
