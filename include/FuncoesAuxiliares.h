/**
 * @author Guilherme Eduardo Kuglin
 * @date 2022, December 11
 * @version 2022, December 17
**/

#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include <string>
#include <stack>
#include <fstream>

using namespace std;

int precedencia(char op);

bool verfEmLista(char valor, string valores);

stack<string> lerArquivo(string arquivo);

#endif