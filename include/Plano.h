/**
 * @author Guilherme Eduardo Kuglin
 * @author Júlia Montibeler
 * @date 2022, October 24
 * @version 2022, December 17
**/

#ifndef PLANO_H
#define PLANO_H

#include <SDL2/SDL.h>
#include <string>
#include "Renderer.h"
#include "Funcao.h"

using namespace std;

class Plano
{
private:

    int escala = 40;
    int expansao = 4000;
    int deslocamento_x = 0;
    int deslocamento_y = 0;
    int height;
    int width;
    Renderer *renderer;
    
public:

    Plano(int height, int widht, Renderer *renderer);

    void desenharPlano();

    void aproximar();

    void afastar();

    void moverEsquerda();

    void moverDireita();

    void moverCima();

    void moverBaixo();

    void desenharFuncao(Funcao *funcao);
};

#endif
