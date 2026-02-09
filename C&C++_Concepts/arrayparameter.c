#include <stdio.h>

/// Quero uma função para printar os valores de um array

void print_array(int A[], int tamanho);

int main(void){

    int A[] = {10,23,54,48,87,69,73,120,124,16,45};

    int tam = sizeof(A)/sizeof(A[0]);
    print_array(A,tam);
    return 0;
}

void print_array(int A[], int tamanho){

    for(int i = 0;i<tamanho;i++){
        printf("%d\n",A[i]);
    }
}

// Array as function

