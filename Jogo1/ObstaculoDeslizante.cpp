#include "ObstaculoDeslizante.h"

ObstaculoDeslizante::ObstaculoDeslizante(float a):
	taxaAtrito(a)
{
}

ObstaculoDeslizante::~ObstaculoDeslizante()
{
	taxaAtrito = 0.f;
}
