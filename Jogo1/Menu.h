#pragma once
#include "Ente.h"
#include <vector>
#include "Gerenciador_Grafico.h"
class Menu :
    public Ente
{
private:
    vector<const char*> opcoes;
    vector<Text> texto;
    vector<Vector2f> posicaoTexto;
    vector<size_t> tamanhoTexto;
    Gerenciador_Grafico* GG;
    Fase* fase1;
    bool pressionada;
    bool aux;
    bool enter;
    Font fonte;

    int selecao;

    
public:
    Menu(Gerenciador_Grafico* GG, Fase* fase1);
    ~Menu();
    virtual void executar();
    void desenharMenu();

    void selectUp();


    void menuEscolha();

    void escolherFase();
    void listarRanking();
    void sairJogo();




};

