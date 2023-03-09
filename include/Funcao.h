/**
 * @author Guilherme Eduardo Kuglin
 * @date 2022, December 11
 * @version 2022, December 17
**/

#ifndef FUNCAO_H
#define FUNCAO_H

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

class Funcao
{
    public:

        Funcao();
        Funcao(string funcaoStr);
        float resolverPosfix(float x);
        string notacaoInfixa;
        
    private:

        string notacaoPosfixa;
        string convPosfix();
};


#endif