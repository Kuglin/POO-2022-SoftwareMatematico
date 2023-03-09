/*
Author: Guilherme
Date: December, 9, 2022
Version: December, 9, 2022  
*/

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <fstream> 

using namespace std;

bool verfEmLista(char valor, string valores)
{
    for (int i = 0; i < valores.length(); i++)
        if (valor == valores[i])
            return true;

    return false;

}

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

string exibirPilha(stack<char> pilha){

    stack<char> tempPilha (pilha);
    string pilhaStr = "";
    while (!tempPilha.empty())
    {
        pilhaStr += tempPilha.top();
        tempPilha.pop();
    }
    return pilhaStr;
}

string convPrefix(string infix)
{
    string prefix = "";
    stack<char> pilha;

    for (int i = 0 ; i < infix.length(); i++)
    {   

        if (verfEmLista(infix[i], "0123456789x")){
            prefix += infix[i];
        }

        else if (infix[i] == '(')
            pilha.push(infix[i]);

        else if (infix[i] == ')') {
            while ( (pilha.top() != '(')){
                prefix += pilha.top();
                pilha.pop();
            }
            pilha.pop();
        }

        else if (verfEmLista(infix[i], "+-*/^")){
            
            prefix += " ";
            
            if (pilha.size() == 0)
                pilha.push(infix[i]);

            else {

                if (precedencia(infix[i]) > precedencia(pilha.top()))
                    pilha.push(infix[i]);

                else if (precedencia(infix[i]) == precedencia(pilha.top()))
                    pilha.push(infix[i]);

                else if (precedencia(infix[i]) < precedencia(pilha.top())){
                    while (pilha.size() > 0 and precedencia(infix[i]) < precedencia(pilha.top())) {
                        prefix += pilha.top();
                        pilha.pop();
                    }

                    pilha.push(infix[i]);
                }
            }
        }
    }
    while (pilha.size() > 0){
        prefix += pilha.top();
        pilha.pop();
    }

    return prefix;

}

int resolverInfix(string infix, int x)
{
    stack<string> pilha;
    string s = "";

    for (int i = 0; i < infix.length(); i++)
    {

        if (verfEmLista(infix[i], "0123456789")){
            s += infix[i];
        }

        else if (infix[i] == 'x')
            pilha.push(to_string(x));

        else if (infix[i] == ' ' && s != ""){
            pilha.push(s);  
            s = "";
        }

        else if (infix[i] != ' ')
        {   

            if (s != ""){
                pilha.push(s); 
                s = "";
            }

            int valor1 = stoi(pilha.top());
            pilha.pop();
            int valor2 = stoi(pilha.top());
            pilha.pop();

            if (infix[i] == '+')
                pilha.push(to_string(valor1 + valor2));
            
            else if (infix[i] == '-')
                pilha.push(to_string(valor1 - valor2));

            else if (infix[i] == '*')
                pilha.push(to_string(valor1 * valor2));

            else if (infix[i] == '/')
                pilha.push(to_string(valor1 / valor2));

            else if (infix[i] == '^')
                pilha.push(to_string(pow(valor1, valor2)));
        }
    }

    return stoi(pilha.top());
}

stack<string> lerArquivo(string arquivo)
{
    stack<string> linhas;

    ifstream Arquivo("equacoes.txt");

    string linha;

    while (getline (Arquivo, linha))
        linhas.push(linha);

    return linhas;
}


int main(int argc, char const *argv[])
{
    string infix = "x+(12*(4))";
    
    string prefix = convPrefix(infix);

    stack<string> equacoes = lerArquivo("equacoes.txt");

    int x = 2;

    while (!equacoes.empty()){
        string pol = convPrefix(equacoes.top());
        cout << resolverInfix(pol, x) << "\n";
        equacoes.pop();
    }

    return 0;
}