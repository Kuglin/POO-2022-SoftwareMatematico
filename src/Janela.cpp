/*
Author: Guilherme, Felipe
Date: November, 7, 2022
Version: November, 7, 2022
*/

#include "Janela.h"
#include <SDL2/SDL.h>

// Construtor
Janela::Janela(char *titulo, int w, int h, string arq_funcoes)
{
    sdl = Sdl::criar();

    title = title;
    width = w;
    height = h;

    sdlWindow = SDL_CreateWindow(titulo, 0, 0, w, h, SDL_WINDOW_SHOWN);
    renderer = new Renderer(sdlWindow);
    plano = new Plano(width, height, renderer);

    stack<string> funcoesTxt = lerArquivo(arq_funcoes);
    qnt_funcoes = funcoesTxt.size();

    funcoes = new Funcao*[qnt_funcoes];

    for (int i = 0; i < qnt_funcoes; i++)
    {
        funcoes[i] = new Funcao(funcoesTxt.top());
        funcoesTxt.pop();
    }
}

// Destrutor
Janela::~Janela()
{

    SDL_DestroyWindow(sdlWindow);
}

// Retornar janela sdl
SDL_Window *Janela::get_sdlWindow()
{
    return sdlWindow;
}

int Janela::get_height()
{
    return height;
}

int Janela::get_width()
{
    return width;
}

void Janela::limitFrameRate()
{
    //

}

void Janela::loop()
{   

    while (true)
    {   

        plano->desenharPlano();
        renderer->clear();

        if( sdl->currentKeyStates[ SDL_SCANCODE_KP_PLUS ] )
        {
            plano->aproximar();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_KP_MINUS ] )
        {
            plano->afastar();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_UP] )
        {
            plano->moverCima();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_DOWN] )
        {
            plano->moverBaixo();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_LEFT] )
        {
            plano->moverDireita();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_RIGHT] )
        {
            plano->moverEsquerda();
        }
        if( sdl->handleEvents() == 0)
            break;

        plano->desenharPlano();

        
        for (int i = 0; i < qnt_funcoes; i++)
            plano->desenharFuncao(funcoes[i]);
        
        renderer->changeColor(255, 255, 255, 255);
        renderer->update();
        
    }

}