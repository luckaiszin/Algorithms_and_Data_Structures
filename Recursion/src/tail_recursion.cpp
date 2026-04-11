#include <iostream>

using namespace std;

/// Ocorre quando a chamada recursiva é a última operação da função. 
/// O resultado da chamada recursiva é retornado diretamente, sem cálculos adicionais no "caminho de volta".
/// É essencial para entender como compiladores otimizam a memória,
/// transformando a recursão em algo tão eficiente quanto um loop (iterativo).

long long factorial_helper(int n, long long acc){
    if (n <= 1) {
        return acc;
    }
    // Não há nenhuma operação pendente após a chamada recursiva
    return factorial_helper(n - 1, n * acc);
}

long long factorial(int n) { /// Função Wrapper
    return factorial_helper(n, 1); /// Função Auxíliar
}

int main() {
    int num = 5;
    cout << "Fatorial de " << num << " e: " << factorial(num) << endl;
    return 0;
}

/*
[ MAIN ]
   │
   └───> factorial(2)  <── (Função Wrapper)
           │
           └───> factorial_helper(n=2, acc=1)
                   │
                   │   PASSO 1:
                   │   - Condição (2 <= 1) é Falsa.
                   │   - Novo acumulador: (2 * 1) = 2.
                   │   - Chamada: factorial_helper(1, 2)
                   │
                   └───> factorial_helper(n=1, acc=2)
                           │
                           │   PASSO 2:
                           │   - Condição (1 <= 1) é Verdadeira.
                           │   - RETORNA acc (valor 2).
                           │
[ RESULTADO: 2 ] <─────────┘
*/