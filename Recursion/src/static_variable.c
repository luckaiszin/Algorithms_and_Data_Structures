#include <stdio.h>

int fatorial(int n) {
    /**
     * 1. ALOCAÇÃO ÚNICA: Diferente de 'int n', a variável 'chamadas' não é criada na Stack (Pilha).
     * Ela é alocada no 'Data Segment' quando o programa inicia.
     * * 2. INICIALIZAÇÃO ÚNICA: A linha abaixo só é executada de fato na PRIMEIRA chamada.
     * Nas chamadas recursivas subsequentes, o computador pula a inicialização e usa o valor 
     * que já está lá na memória global.
     */
    static int chamadas = 0; 

    /**
     * 3. PERSISTÊNCIA: Quando fazemos 'chamadas++', estamos alterando um endereço de memória 
     * fixo. Se fatorial(5) chama fatorial(4), a segunda chamada verá o valor '1' que a 
     * primeira deixou, e o transformará em '2'.
     */
    chamadas++;

    // Aqui imprimimos o estado da variável que 'sobrevive' entre as chamadas
    printf("Chamada nº %d | Endereço de 'n' (Stack): %p | Calculando: %d\n", chamadas, (void*)&n, n);

    // Caso Base: A recursão começa a "voltar" (desempilhar)
    if (n <= 1) {
        return 1;
    }

    /**
     * 4. RECURSÃO: Cada vez que chamamos 'fatorial' novamente, um novo 'n' surge na Stack,
     * mas TODOS os níveis da recursão apontam para a MESMA variável 'chamadas' no Data Segment.
     */
    return n * fatorial(n - 1);
}

int main() {
    // Primeira execução: o contador vai de 0 a 5.
    printf("--- Primeira Execução ---\n");
    int resultado = fatorial(5);
    printf("Resultado Final: %d\n", resultado);

    /**
     * 5. O PERIGO: Se chamarmos a função de novo, 'chamadas' NÃO volta a ser 0!
     * Ela terminou a execução anterior valendo 5 e continuará dali.
     */
    printf("\n--- Segunda Execução (O contador não reseta!) ---\n");
    fatorial(2); 

    return 0;
}