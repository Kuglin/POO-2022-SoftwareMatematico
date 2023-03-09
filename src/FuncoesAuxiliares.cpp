#include "FuncoesAuxiliares.h"

int precedencia(char op){

    if (op == '+' or op == '-')
        return 1;

    else if (op == '*' or op == '/')
        return 2;

    else if (op == '^')
        return 3;

    else if (op == '(' or op == ')')
        return 0;

}

bool verfEmLista(char valor, string valores)
{
    for (int i = 0; i < valores.length(); i++)
        if (valor == valores[i])
            return true;

    return false;

}

stack<string> lerArquivo(string arquivo)
{
    stack<string> linhas;

    ifstream Arquivo(arquivo);

    string linha;

    while (getline(Arquivo, linha))
        linhas.push(linha);

    return linhas;
}