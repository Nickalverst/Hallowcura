#include "Menu.h"

Menu::Menu(Gerenciador_Grafico* GG, Fase* fase1):
    GG(GG),
    fase1(fase1)
{
    if (!tex.loadFromFile("assets/a.png"))
    {
        cerr << "Erro ao carregar a textura do menu. " << endl;
    }

    sprite.setTexture(tex);
    sprite.scale(Vector2f(SIZE, SIZE));
    
    fonte.loadFromFile("assets/ethn.otf");
    
    pressionada = false;
    enter = false;
    aux = true;
	
    opcoes = { "JOGAR", "RANKING", "SAIR" };
    texto.resize(3);
    posicaoTexto = { {800,200},{800,400},{800,600} };
   
    tamanhoTexto = { 20 , 20 , 20 };
    selecao = 0; 
    for (size_t i=0; i < texto.size(); i++)
    {
        texto[i].setFont(fonte);
        texto[i].setString(opcoes[i]);
        texto[i].setCharacterSize(tamanhoTexto[i]);
        texto[i].setFillColor(Color::Blue);
        texto[selecao].setOutlineThickness(0);
        texto[i].setPosition(posicaoTexto[i]);
    }
    texto[selecao].setOutlineThickness(4);
    

}

Menu::~Menu()
{
}

void Menu::executar()
{
   if (aux == true) {
        desenharMenu();
        
    }
   menuEscolha();
}

void Menu::desenharMenu()
{
    int i;
    imprimir_se();
   for(i=0;i<3;i++)
    {
          GG->desenhar(texto[i]);
    }
}

void Menu::selectUp()
{
}

void Menu::menuEscolha()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressionada)
    {
        if (selecao < 2)
        {
            ++selecao;
            pressionada = true;
            texto[selecao].setOutlineThickness(4);
            texto[selecao - 1].setOutlineThickness(0);
            pressionada = false;
            enter = false;

        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressionada)
    {
        if (selecao > 0)
        {
            --selecao;
            pressionada = true;
            texto[selecao].setOutlineThickness(4);
            texto[selecao + 1].setOutlineThickness(0);
            pressionada = false;
            enter = false;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&& !enter)
    {   
        enter = false;
        cout << "escolha enter" << opcoes[selecao] << endl;
        if (selecao == 0)
        {
            escolherFase();
        }
        else if (selecao == 1)
        {
            listarRanking();
        }
        else if (selecao == 2)
        {
            sairJogo();
        }
      //  switch (selecao+1)
      //  {
     //   case 1:
     //   {
     //       
     //       cout << "escolher Fase" << endl;
    //        break;
    //    }
   //     case 2:
   //     {
   //         
    //        break;
   //     }
   //     case 3:
   //     {
   //         sairJogo();
 //           break;
  //      }
   //     default:
    //        break;
    //    }
    }
   
}

void Menu::escolherFase()
{
    //enter = false;
        opcoes = { "fase1", "fase2", "voltar" };
        for (size_t i = 0; i < texto.size(); i++)
        {
            texto[i].setFont(fonte);
            texto[i].setString(opcoes[i]);
            texto[i].setCharacterSize(tamanhoTexto[i]);
            texto[i].setFillColor(Color::Red);
            texto[selecao].setOutlineThickness(0);
            texto[i].setPosition(posicaoTexto[i]);
        }
        texto[selecao].setOutlineThickness(4);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enter)
        {
            enter = true;
            cout << "escolha enter" << opcoes[selecao] << endl;
        }
        switch (selecao + 1)
        {
        case 1:
        { 
            while((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)==false))
            {
                fase1->executar();
                GG->desenhar(static_cast<Fase*>(fase1));
            }
            //cout << "executou a fase1" << endl;
            break;
        }
        case 2:
        {
            //passar a fase 2 floresta;
            break;
        }
        default:
            break;
        }
    }

void Menu::listarRanking()
{
	//printar a lista de lideres 
	//voltar ao menu
}

void Menu::sairJogo()
{
    GG->close();
}
