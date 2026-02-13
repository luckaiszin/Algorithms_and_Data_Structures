#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// Conceito Geral

struct livro {

    char nome[20];
    char autor[20];
};

void exemple1(){

    struct livro l1 = {"Fausto","Goethe"};
    printf("Livro: %s\n",l1.nome); // Acesso direto
    printf("Autor: %s\n",l1.autor);

}

/// Uso de typedef

typedef struct {

    char nome[20];
    int ano;
} filme;

/// Ponteiro para Struct

void exemple2(){

    filme f1 = {"Avatar", 2010};
    filme *pf1 = &f1;

    // Acesso via variável direta
    printf("Nome: %s\n",f1.nome);

    // Acesso via ponteiro (Operador Seta)
    printf("Ano: %d\n",pf1->ano);

    /*
    * NOTA DE PERFORMANCE:
    * Se você passa uma struct por variável direta para uma função, o C tira uma "xerox" dela. 
    * Se a struct tiver 1MB, você gasta 1MB de RAM a mais na pilha (stack).
    *
    * Se você passa por ponteiro, você gasta apenas o tamanho do endereço (geralmente 8 bytes), 
    * não importa se a struct tem 1KB ou 1GB. O ponteiro é apenas o "índice" para o dado real.
    */
}

/// Array de struct

typedef struct {
    char pais[20];
    int score;
} jogador;

int pontuacaoTotal(jogador J[], int tamanho){

    int soma = 0;
    jogador *j = J;

    for(int i = 0; i < tamanho; i++){
        soma += (j + i)->score;
    }

    return soma;
}

void exemple3(){

    int score_total;
    int tam;

    jogador jogadores[5] = {
        {"Brasil", 120},
        {"Dinamarca",84},
        {"Uruguai",56}
    };

    tam = sizeof(jogadores)/sizeof(jogadores[0]);
    score_total = pontuacaoTotal(jogadores, tam);
    printf("Pontuacao Total: %d\n", score_total);
}

// Exercício: Um racional é qualquer número da forma p/q, sendo p um inteiro e q um inteiro não nulo.  
// É conveniente representar um racional por um registro

/*
Vamos convencionar que o campo q de todo racional é estritamente positivo e 
que o máximo divisor comum dos campos p e q é 1.  Escreva funções

reduz, que receba inteiros a e b e devolva o racional que representa a/b;
neg, que receba um racional x e devolva o racional −x;
soma, que receba racionais x e y e devolva o racional que representa a soma de x e y;
produ, que receba racionais x e y e devolva o racional que representa o produto de x por y;
quoci, que receba racionais x e y e devolva o racional que representa o quociente de x por y.

*/

typedef struct{
    int p,q;
} racional;

int mdc(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

racional reduz(int a, int b) {
    racional r;
    if (b == 0) {
        printf("Erro: Denominador nulo!\n");
        exit(1);
    }
    
    // Regra: q deve ser estritamente positivo
    if (b < 0) {
        a = -a;
        b = -b;
    }
    
    int comum = mdc(a, b);
    r.p = a / comum;
    r.q = b / comum;
    return r;
}

racional neg(racional x) {
    // Apenas inverte o sinal do numerador e simplifica (opcional, já que x já deve estar simplificado)
    return reduz(-x.p, x.q);
}

racional soma(racional x, racional y) {
    // Fórmula: a/b + c/d = (ad + bc) / bd
    int num = (x.p * y.q) + (y.p * x.q);
    int den = x.q * y.q;
    return reduz(num, den);
}

racional produ(racional x, racional y) {
    // Fórmula: (a/b) * (c/d) = (ac) / (bd)
    return reduz(x.p * y.p, x.q * y.q);
}

racional quoci(racional x, racional y) {
    // Fórmula: (a/b) / (c/d) = (ad) / (bc)
    return reduz(x.p * y.q, x.q * y.p);
}



int main(void){
    exemple3();
    return 0;
}