/*
Author: Guilherme, Felipe, Júlia
Date: October,24 , 2022
Version: November, 7, 2022  
*/

#include "Sdl.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

Sdl* Sdl::sdl= nullptr;

//Construtor
Sdl::Sdl(){

    //Iniciar sistema de video
    //Se retornar menor que 0 exibirá um erro
    if( SDL_Init(SDL_INIT_VIDEO) < 0)
        cout << "SDL não pode ser iniciado: " << SDL_GetError();

    else
        cout << "Sistemas de video inicializados\n";
}

//Destrutor
Sdl::~Sdl()
{
    //Fechar SDL
    SDL_Quit();
}

Sdl *Sdl::criar()
{
    if (sdl==nullptr)
        sdl = new Sdl();
    return sdl;
}

//Loop
void Sdl::RunLoop()
{
    while(isRunning)
    {
        //processar funcoes
        handleEvents();
        SDL_Delay(100);
    }
}

//Parar Loop
void Sdl::stopLoop()
{
    isRunning = false;
    SDL_Quit();
}

int Sdl::handleEvents()
{
    while( SDL_PollEvent( &eventHandler ) != 0 )
    {
        //User requests quit
        if( eventHandler.type == SDL_QUIT )
        {
            return 0;

        }
    }
    return 1;
}
