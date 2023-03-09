#include "Plano.h"
#include <SDL2/SDL.h>

using namespace std;

void Plano::desenharPlano (int height, int width, Renderer *renderer)
{       
    // Grid pontilhado
    renderer->changeColor(60, 60, 60, 255);

    for (int i = width/2 + deslocamento_x; i < width; i += escala)
    {   
        for (int j = 0; j < height; j += 4)
        {   
            
            renderer->drawPoint(i, j);
        }
    }

    for (int i = width/2 + deslocamento_x; i > 0; i -= escala)
    {
        for (int j = 0; j < width; j += 5)
        {
            renderer->drawPoint(i, j);
        }
    }

    for (int i = height/2 + deslocamento_y; i < height ; i += escala)
    {
        for (int j = 0; j < width; j += 5)
        {
            renderer->drawPoint(j, i);
        }
    }

    for (int i = height/2 + deslocamento_y; i > 0; i -= escala)
    {
        for (int j = 0; j < width; j += 4)
        {
            renderer->drawPoint(j, i);
        }
    }

    //Linha Vertical
    renderer->changeColor(255, 255, 255, 255);
    renderer->drawLine(0, height / 2 + deslocamento_y, width, height / 2 + deslocamento_y);

    // Linha Horizontal
    renderer->changeColor(255, 255, 255, 255);
    renderer->drawLine(width / 2 + deslocamento_x, 0, width / 2 + deslocamento_x, height);


}

void Plano::desenharFuncao(Funcao *funcao, int height, int width, Renderer *renderer)
{   
    float x_anterior = NULL;
    float y_anterior = NULL;
    float y;
    bool aux = true;

    renderer->changeColor(255,0,0,0);
    
    for (float x = -height/(escala); x < height/(escala); x+=0.01)
    {
        y = funcao->resolverPosfix(x);

        if (aux){
            x_anterior = x;
            y_anterior = y;
            aux = false;
        }

        if (y > height){
            aux = true;
        }

        else {
            renderer->drawLine(
            x_anterior * escala + width/2 + deslocamento_x,
            y_anterior * -escala + height/2 + deslocamento_y,
            x * escala + width/2 + deslocamento_x,
            y * -escala + height/2 + deslocamento_y);
        }

        x_anterior = x;
        y_anterior = y;
                
    }
}

void Plano::aproximar() {
    if (escala < 100) {
        escala += 5;
    }
}

void Plano::afastar() {
    if (escala > 20) {
        escala -= 5;
    }
}

void Plano::moverDireita() {
    if (deslocamento_x < expansao)
    {
        deslocamento_x += escala;
    }
}

void Plano::moverEsquerda() {
    if (deslocamento_x > -expansao) 
    {
        deslocamento_x -= escala;
    }
}

void Plano::moverBaixo() {
    if (deslocamento_y > -expansao) 
    {
        deslocamento_y -= escala;
    }
}

void Plano::moverCima() {
    if (deslocamento_y < expansao) 
    {
        deslocamento_y += escala;
    }
}
