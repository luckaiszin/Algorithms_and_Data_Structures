#include <iostream>

using namespace std;

/**
 * CONCEITO: Tree Recursion (Recursão em Árvore)
 * Este tipo de recursão ocorre quando uma função faz DUAS ou MAIS chamadas 
 * a si mesma dentro do mesmo bloco de execução.
 */
int fibonacci(int n) {

    // 1. CASO BASE: É o "freio" da recursão.
    // Sem isso, a árvore cresceria infinitamente até estourar a memória (Stack Overflow).
    if (n == 0 || n == 1) { 
        return 1;
    }
    
    // 2. PASSO RECURSIVO (Onde a "Árvore" ramifica):
    // Aqui a função "se divide" em duas. Para resolver fibonacci(n), 
    // o computador precisa primeiro resolver as duas sub-árvores abaixo.
    
    // Imagine que cada chamada gera dois novos "galhos":
    //             fib(n)
    //            /      \
    //      fib(n-1)    fib(n-2)
    
    return fibonacci(n - 1) + fibonacci(n - 2); 
    
    // IMPORTANTE: O computador resolve primeiro toda a ramificação da esquerda 
    // (n-1) para só depois começar a resolver a da direita (n-2).
}

int main() {
    // Ao chamar fibonacci(7), você está criando uma árvore com dezenas de nós.
    // A complexidade aqui é exponencial: O(2^n).
    int x = fibonacci(7);

    cout << "Resultado: " << x << endl;

    return 0;
}