#include <stdio.h>

// Na memória RAM, os valores são organizados como uma sequência de Bytes(8 bits cada). 
// Variáveis do tipo int requerem um armazenamento de 4 Bytes(32 bits) de forma que pode
// armazenar valores entre -2.147.483.648(signal + 2^31) até 2.147.483.647(2^31 -1).
// Ou unsigned: 0 até 4.294.967.295(2^32 -1).
// Diferentes tipos de variáveis armazenam em diferentes números de Bytes.

/*
     * VISUALIZAÇÃO NA MEMÓRIA RAM (LITTLE ENDIAN):
     * Supondo que o sistema reservou o endereço inicial 0x100 para a variável 'x'
     * * -------------------------------------------------------------------------
     * Endereço Memória | Conteúdo (1 Byte) | Descrição
     * -------------------------------------------------------------------------
     * 0x100            | [ 00001010 ]      | Byte 1: LSB (Valor 10 ou 0x0A) -> "Little" primeiro!
     * 0x101            | [ 00000000 ]      | Byte 2: (Valor 0 ou 0x00)
     * 0x102            | [ 00000000 ]      | Byte 3: (Valor 0 ou 0x00)
     * 0x103            | [ 00000000 ]      | Byte 4: MSB (Valor 0 ou 0x00)
     * -------------------------------------------------------------------------
     * * EXPLICAÇÃO DO FLUXO:
     * 1. O identificador 'x' é apenas um rótulo para o endereço base (0x100).
     * 2. Quando o código pede 'x', o processador olha o tipo (int = 4 bytes).
     * 3. Ele lê do 0x100 até o 0x103.
     * 4. Como ele sabe que é Little Endian, ele remonta os bytes de trás para frente
     * na cabeça dele: [0x103][0x102][0x101][0x100] -> 0x0000000A = 10.
*/

void example1(){     // introdução de ponteiros

    int age = 24;
    int *p_age = &age;

    printf("value of variable age: %d\n\n",age);
    printf("Adress of value age: %p\n",&age);
    printf("Value of pointer age: %p\n",p_age);
    printf("Size of int value: %d bytes\n\n",sizeof(age));

    int new_value = 35;
    int *p_new_value = &new_value;

    printf("Adress of new value: %p\n",&new_value);
    printf("Value of pointer new value: %p\n",&new_value);

}

/* Passagem por endereço*/

void swap(int *p1, int *p2){ 

    // Dereferenciação: que vai até o endereço do ponteiro e tem acesso aos seus valores.
    int x = *p1;
    *p1 = *p2;
    *p2 = x;
}

// Apenas em C++
/* Passagem por referência
 void swap(int &p1, int &p2) { 
    int x = p1;
    p1 = p2;
    p2 = x;
}
*/

int example2(){

    int a = 10;
    int b = 20;

    swap(&a,&b);

    printf("a: %d\n",a);
    printf("b: %d",b);
}

/* Equivalência Ponteiros-Arrays */

void example3(){

/* * ============================================================================
    * CONCEITOS: EQUIVALÊNCIA PONTEIRO-ARRAY & ARRAY DECAY
    * ============================================================================
    * * 1. ARRAY DECAY (Decaimento de Array):
    * Em C, o nome de um array (ex: 'v') decai para um ponteiro que aponta 
    * para o seu primeiro elemento (&v[0]) em quase todas as expressões.
    * * 2. ARITMÉTICA DE PONTEIROS:
    * Ao fazer *(ptr + i), o compilador calcula o endereço real como:
    * Endereço Final = ptr + (i * sizeof(tipo_do_dado))
    * Isso garante que o "salto" na memória caia exatamente no próximo elemento.
    * * 3. AÇÚCAR SINTÁTICO (Syntactic Sugar):
    * A notação de colchetes ptr[i] é apenas uma forma amigável de escrever 
    * *(ptr + i). O compilador as trata como identidades absolutas.
    * * 4. EQUIVALÊNCIA UNIVERSAL:
    * A expressão a[b] é rigorosamente traduzida como *(a + b).
    * Devido à comutatividade da soma (a + b == b + a), tecnicamente 
    * v[3] é o mesmo que 3[v], embora '3[v]' seja péssima prática.
 */

    int v[5] = {11,23,36,47,59};
    printf("Size of array: %d\n",sizeof(v));

    int *ptr = v;
    int first_element = *ptr;
    int second_element = *(ptr + 1);

    for(int i = 0;i<5;i++){
        printf("%d_element: %d\n",i,*(ptr + i));
    }

    for(int i = 0;i<5;i++){
        printf("%d_element: %d\n",i,ptr[i]);
    }

    // v[i] é equivalente a *(v+i)
}

/* Equivalência Ponteiros-Matrizes */

/*
Se um ponteiro simples permite navegar em uma linha (1D), 
um ponteiro para ponteiro (int **r) permite
navegar em uma grade ou matriz (2D) de forma dinâmica.
*/


void example4(){

    // 1. Matriz Estática (Bloco contínuo na memória)
    int A[2][2] = {
        {1, 0},
        {0, 1}
    };

    // Criando a "ponte": um vetor de ponteiros para as linhas
    int *linhas[2] = { A[0], A[1] }; 

    int **ptr = linhas;

    printf("Iterando via ponteiro de ponteiro:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            // Aplicando a aritmética de dois níveis
            // Lembrando que r[i][j] = *(*(r + i) + j)
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}

void exemple5(){

    int dados[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    
    int *ptr = dados;
    int colunas = 3;

    // Acesso Direto: Usando apenas o ponteiro ptr e aritmética de ponteiros (sem usar colchetes []), 
    // imprima o valor que estaria na Linha 1, Coluna 2 (o valor 60).

    printf("Acesso Direto: %d\n", *(ptr + (1*colunas + 2)));

    //Soma da Diagonal: Crie um loop que percorra a "diagonal principal" dessa matriz
    // fictícia e calcule a soma dos elementos (10 + 50 + 90)

    int soma = 0;
    for(int i = 0;i<3;i++){
        soma +=*(ptr + (i*colunas + i));
    }

    /// Otimizada:

    /*
    int soma = 0;
    int *p_diag = ptr; // Começa no primeiro elemento (10)
    for(int i = 0; i < 3; i++) {
        soma += *p_diag;
        p_diag += (colunas + 1); // Adress arithmethi: estamos alterando apenas o endereço
    }
    */

    printf("Soma Diagonal: %d\n",soma);

    /// Se dados[0] for 0x100, dados[7] será 0x11C

}

// Função que retorna ponteiro

int *exemple6(){

    /// Geralmente retorna algo criado com malloc.
}

// Ponteiro para função

float somar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }

// Esta função recebe um PONTEIRO PARA FUNÇÃO como argumento
// Útil quando queremos passar uma função como argumento
// O parâmetro 'operacao' pode receber qualquer função que siga o padrão float(float, float)

typedef float (*OpMatematica)(float, float);

// Muito mais intuitivo no C++:
//using Operacao = int (*)(int, int);

/*
void calcular(float x, float y, float (*operacao)(float, float)) {
    float resultado = operacao(x, y); // Chama a função através do ponteiro
    printf("Resultado: %.2f\n", resultado);
}
*/

void calcular(float x, float y, OpMatematica operacao) {
    printf("Resultado: %.2f\n", operacao(x, y));
}

void exemple7() {

    float n1 = 10.5, n2 = 5.0;

    /* * O QUE É CALLBACK NESTE EXEMPLO?
    * * A função 'calcular' atua como a função principal (ou caller). Ela recebe um 
    * "Callback" através do parâmetro 'operacao'.
    * * 1. O CONTRATO: A função 'calcular' define que aceita qualquer função que 
    * receba dois floats e retorne um float.
    * * 2. ONDE/QUANDO: A 'calcular' decide o momento exato de disparar a conta 
    * e como o resultado será exibido (printf).
    * * 3. O QUE: As funções 'somar' ou 'subtrair' são os Callbacks reais. Elas 
    * contêm a lógica específica que a função 'calcular' desconhece até 
    * o momento da chamada.
    * * Isso torna o código extensível: você pode criar uma função 'exponencial' 
    * agora e passá-la para 'calcular' sem precisar modificar uma linha sequer 
    * da função 'calcular' original.
    */

    printf("Somando: ");
    calcular(n1, n2, somar); // Passamos o nome da função como argumento

    printf("Subtraindo: ");
    calcular(n1, n2, subtrair);

    printf("Multiplicando: ");
    calcular(n1, n2, multiplicar);
}

int main(void){

    exemple7();
    return 0;
}