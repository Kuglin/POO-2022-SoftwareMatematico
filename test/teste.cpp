/*This source code copyrighted by Lazy Foo' Productions (scale04-scale22)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				}
			}
		}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//escala
			int scale = 20;
			int expansao = 200 * scale;
			int deslocamento_x = 0;
			int deslocamento_y = 0;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				
				SDL_Delay(10);

				const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
				if( currentKeyStates[ SDL_SCANCODE_KP_PLUS ] )
                {
                    scale += 5;
                }
				else if( currentKeyStates[ SDL_SCANCODE_KP_MINUS ] )
                {
                    if (scale > 6)
						scale -= 5;
                }

				else if( currentKeyStates[ SDL_SCANCODE_UP] )
                {	
					if (deslocamento_y < expansao)
					{
						deslocamento_y+=5;
					}  
                }

				else if( currentKeyStates[ SDL_SCANCODE_DOWN] )
                {
                    if (deslocamento_y > -expansao)
					{
						deslocamento_y-=5;
					}  
                }

				else if( currentKeyStates[ SDL_SCANCODE_LEFT] )
                {
                    if (deslocamento_x < expansao)
					{
						deslocamento_x+=5;
					}  
                }

				else if( currentKeyStates[ SDL_SCANCODE_RIGHT] )
                {
                    if (deslocamento_x > -expansao)
					{
						deslocamento_x-=5;
					}  
                }

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer,255,255,255,255);
				SDL_RenderClear( gRenderer );
				
				//Draw blue horizontal line
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );		
				SDL_RenderDrawLine( gRenderer, 0 + deslocamento_x - expansao, SCREEN_HEIGHT / 2 + deslocamento_y, SCREEN_WIDTH + deslocamento_x + expansao, SCREEN_HEIGHT / 2 + deslocamento_y);

				//Draw blue horizontal line
				SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );		
				SDL_RenderDrawLine( gRenderer, SCREEN_WIDTH / 2 + deslocamento_x, 0 + deslocamento_y - expansao, SCREEN_WIDTH / 2 + deslocamento_x, SCREEN_HEIGHT + deslocamento_y + expansao);

				//Grid pontilhado vermelho
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );

				 for (int i = SCREEN_WIDTH/2; i < SCREEN_WIDTH+expansao; i += scale){
				 	for( int j = 0-expansao; j < SCREEN_HEIGHT+expansao; j += 4 )
                 	{
                     	SDL_RenderDrawPoint( gRenderer, i + deslocamento_x, j + deslocamento_y);
                 	}
				 }

				 for (int i = SCREEN_WIDTH/2; i > 0-expansao; i -= scale){
				 	for( int j = 0-expansao; j < SCREEN_HEIGHT+expansao; j += 4 )
                 	{
                     	SDL_RenderDrawPoint( gRenderer, i + deslocamento_x, j + deslocamento_y);
                 	}
				 }

				 for (int i = SCREEN_HEIGHT/2; i < SCREEN_HEIGHT+expansao; i += scale){
				 	for( int j = 0-expansao; j < SCREEN_WIDTH+expansao; j += 4 )
                 	{
                     	SDL_RenderDrawPoint( gRenderer, j + deslocamento_x, i + deslocamento_y );
                 	}
				 }

				for (int i = SCREEN_HEIGHT/2; i > 0-expansao; i -= scale){
				 	for( int j = 0-expansao; j < SCREEN_WIDTH+expansao; j += 4 )
                 	{
                     	SDL_RenderDrawPoint( gRenderer, j + deslocamento_x, i + deslocamento_y);
                 	}
				 }
				
				//Desenhar funcao
				int x_anterior;
				int y_anterior;
				bool aux=false;

				SDL_SetRenderDrawColor( gRenderer, 0000, 0000, 0000, 0000);
				for (int x = -SCREEN_HEIGHT/40; x < SCREEN_HEIGHT/40; x += 1){
					int y = -1*x*x*2+10;
					if ( aux==false ){
						x_anterior = x;
						y_anterior = y;
						aux=true;
					}
					SDL_RenderDrawLine( gRenderer, x_anterior * scale + SCREEN_WIDTH/2 + deslocamento_x, y_anterior * -scale + SCREEN_HEIGHT/2 + deslocamento_y,  x * scale + SCREEN_WIDTH/2 + deslocamento_x, y * -scale + SCREEN_HEIGHT/2 + deslocamento_y);
					x_anterior = x;
					y_anterior = y;
					
				}

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}