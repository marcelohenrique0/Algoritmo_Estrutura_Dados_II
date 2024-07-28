#include <stdio.h>
#include <stdlib.h>

int contagem_recursiva = 0;
int contagem_de_saida_r = 0;
int contagem_de_atribuicao = 11;
int contagem_de_soma = 0;

int f(int n){
    if (n == 0){
        return 1;
    }
contagem_recursiva += 1;
contagem_de_saida_r += 1;
contagem_de_atribuicao += 3;
contagem_de_soma += 1;

    return f(n-1) + 1/ f(n-1);
}

int main (){
    int t=20;
    int resultado = f(t);
    printf("Resultado: %d\n", resultado);
    printf("Contagem de chamadas recursivas: %d\n", contagem_recursiva);
    printf("Contagem de saidas recursivas: %d\n", contagem_de_saida_r);
    printf("Contagem de atribuicoes: %d\n", contagem_de_atribuicao);
    printf("Contagem de somas: %d\n", contagem_de_soma);
}