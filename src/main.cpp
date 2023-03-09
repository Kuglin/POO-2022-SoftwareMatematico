#include <iostream>
#include <vector>
#include <array>

#include "Janela.h"
#include "Plano.h"
#include "Sdl.h"
#include "Renderer.h"
#include "Funcao.h"
#include "FuncoesAuxiliares.h"

using namespace std;

int main(int argc, char const *argv[])
{
    char *title = "TESTE";

    Janela *janela = new Janela(title, 800, 600, "equacoes.txt");
    janela->loop();

}
