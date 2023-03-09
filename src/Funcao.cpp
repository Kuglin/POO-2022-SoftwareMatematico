#include "Funcao.h"
#include "FuncoesAuxiliares.h"
#include <math.h>

Funcao::Funcao(){}

Funcao::Funcao(string funcaoStr)
{
    notacaoInfixa = funcaoStr;

    notacaoPosfixa = convPosfix();
}

string Funcao::convPosfix()
{
    string posfix = "";
    stack<char> pilha;

    for (int i = 0 ; i < notacaoInfixa.length(); i++)
    {   
        
        if (verfEmLista(notacaoInfixa[i], "0123456789x")){
            posfix += notacaoInfixa[i];
        }

        else if (notacaoInfixa[i] == '(')
            pilha.push(notacaoInfixa[i]);

        else if (notacaoInfixa[i] == ')') {
            while ( (pilha.top() != '(')){
                posfix += pilha.top();
                pilha.pop();
            }
            pilha.pop();
        }

        else if (verfEmLista(notacaoInfixa[i], "+-*/^")){
            posfix += " ";
            
            if (pilha.size() == 0){
                if (notacaoInfixa[i] == '-' && !(verfEmLista(notacaoInfixa[i-1],"0123456789x")))
                    posfix += "0 ";
                pilha.push(notacaoInfixa[i]);
            }

            else {

                if (precedencia(notacaoInfixa[i]) >= precedencia(pilha.top())){

                    if (notacaoInfixa[i] == '-' && !(verfEmLista(notacaoInfixa[i-1],"0123456789x")))
                        posfix += "0 ";

                    pilha.push(notacaoInfixa[i]);
                }

                else if (precedencia(notacaoInfixa[i]) < precedencia(pilha.top())){
                    while (pilha.size() > 0 and precedencia(notacaoInfixa[i]) < precedencia(pilha.top())) {
                        posfix += pilha.top();
                        pilha.pop();
                    }

                    pilha.push(notacaoInfixa[i]);
                }
            }
        }
    }
    while (pilha.size() > 0){
        posfix += pilha.top();
        pilha.pop();
    }

    cout << posfix << "\n";
    return posfix;
}

float Funcao::resolverPosfix(float x){
    stack<string> pilha;
    string s = "";

    for (int i = 0; i < notacaoPosfixa.length(); i++)
    {
        if (verfEmLista(notacaoPosfixa[i], "0123456789")){
            s += notacaoPosfixa[i];
        }

        else if (notacaoPosfixa[i] == 'x')
            pilha.push(to_string(x));

        else if (notacaoPosfixa[i] == ' ' && s != ""){
            pilha.push(s);  
            s = "";
        }

        else if (notacaoPosfixa[i] != ' ')
        {   

            if (s != ""){
                pilha.push(s); 
                s = "";
            }

            float valor1 = stof(pilha.top());
            pilha.pop();
            float valor2 = stof(pilha.top());
            pilha.pop();

            if (notacaoPosfixa[i] == '+'){
                pilha.push(to_string(valor2 + valor1));
            }
            
            else if (notacaoPosfixa[i] == '-'){
                pilha.push(to_string(valor2 - valor1));
                }

            else if (notacaoPosfixa[i] == '*')
                pilha.push(to_string(valor2 * valor1));

            else if (notacaoPosfixa[i] == '/')
                pilha.push(to_string(valor2 / valor1));

            else if (notacaoPosfixa[i] == '^')
                pilha.push(to_string(pow(valor2, valor1)));
        }
    }
    if (s != ""){
        pilha.push(s); 
    }
    return stof(pilha.top());

}