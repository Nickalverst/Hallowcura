#pragma once
class Entidade
{
protected:
	int x, y;

public:
	Entidade();
	~Entidade();
	virtual void executar() = 0;
};

