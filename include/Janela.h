/**
 * @author Guilherme Eduardo Kuglin
 * @author Felipe Emanuel de Mello Alves Vianna Prasser
 * @author Júlia Montibeler
 * @date 2022, October 24
 * @version 2022, December 17
**/

#ifndef JANELA_H
#define JANELA_H

#include "Sdl.h"
#include "Renderer.h"
#include "Funcao.h"
#include "Plano.h"
#include "FuncoesAuxiliares.h"

#include <SDL2/SDL.h>
#include <stack>

class Janela
{

public:

    Janela(char *title, int w, int h, string arq_funcoes);

    ~Janela();

    SDL_Window *get_sdlWindow();

    int get_width();

    int get_height();

    void loop();

    void limitFrameRate();

private:
    SDL_Window *sdlWindow = nullptr;

    // Largura e Altura
    int width;
    int height;

    // Titulo
    char *title;

    Sdl *sdl;

    Renderer *renderer;
    
    Plano *plano;

    Funcao** funcoes;
    int qnt_funcoes;
};

#endif