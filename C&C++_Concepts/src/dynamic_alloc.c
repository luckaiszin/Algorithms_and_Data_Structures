#include <stdio.h>
#include <stdlib.h>

/*
A alocação dinâmica em C permite que o seu programa solicite memória ao sistema operacional
em tempo de execução (enquanto o programa está rodando), em vez de ter um tamanho fixo definido durante a compilação.
Essa memória é alocada em uma região estruturada especificamente para isso, 
chamada Heap (diferente da Stack, onde ficam as variáveis locais).
*/

/// A função Malloc

/*
O que faz: Aloca um bloco de memória contíguo do tamanho exato especificado (em bytes).

Detalhe crucial: A memória alocada não é inicializada. Ela virá com "lixo" (valores residuais que já estavam na memória).
*/

void example1(){

    int * ptr = (int*) malloc(5*sizeof(int));


    // Checandp se o SO liberou memória

    if(ptr==NULL){
        printf("Erro de memória\n");
        exit(1);
    }

    for(int i = 0; i<5; i++){
        ptr[i] = (i + 1)*10;
        printf("%d \n", ptr[i]);
    }

    free(ptr);
    ptr = NULL;
}

/// A função Calloc

/*
O que faz: Semelhante ao malloc, mas é focada em arrays.
Ela aloca espaço para um número específico de elementos, cada um com um tamanho específico.
Detalhe crucial: Ao contrário do malloc, o calloc inicializa todos os bytes com zero.
*/

void example2(){

    int *ptr = (int*)calloc(5,sizeof(int));
    for(int i = 0; i<5; i++){
        printf("%d \n", ptr[i]);
    }

    free(ptr);
    ptr = NULL;
}

/// A função Realloc

/*
O que faz: Redimensiona um bloco de memória que já foi alocado anteriormente (seja com malloc ou calloc). 
Você pode usá-lo para aumentar ou diminuir o espaço.
Detalhe crucial: Ele tenta expandir o bloco no mesmo endereço atual. 
Se não houver espaço contíguo suficiente,
ele aloca um novo bloco em outro lugar, copia os dados 
antigos para o novo local e libera o bloco antigo automaticamente.
Exemplo: Aumentar o espaço do ponteiro anterior para 10 inteiros.
*/

void example3(){

    //int *ptr = (int*)malloc(3*sizeof(int));
    int *ptr = (int*)calloc(3,sizeof(int));
    //ptr = (int*)realloc(ptr,7*sizeof(int)); /// como foi inicializado com um malloc antes, nos indíces 4,5,6 gerou lixo

    /*
    Se o sistema operacional não tiver memória suficiente para realocar o bloco, 
    a função realloc retornará NULL. Se você atribuir esse NULL diretamente ao ptr,
    você perde a referência para o bloco de memória original, 
    causando um memory leak (vazamento de memória) imediato daquele bloco que já existia.
    */

    // Sempre use um ponteiro temporário para as realocações
    int *temp = (int*)realloc(ptr, 7 * sizeof(int));

    if (temp == NULL) {
        printf("Erro: Memória insuficiente para realocar.\n");
        // O bloco original apontado por 'ptr' continua intacto e acessível.
        free(ptr); // Libera o que já existia antes de sair
        exit(1);
    } else {
        // Só atualiza o ponteiro principal se a realocação foi um sucesso
        ptr = temp; 
    }
    for(int i = 0; i<6; i++){
        printf("%d \n", ptr[i]);
    }

    free(ptr);
    ptr = NULL;
}


/// Free

/*
O que faz: Devolve a memória dinamicamente alocada para o sistema operacional, 
para que possa ser usada por outros programas ou outras partes do seu código.
Detalhe crucial: É obrigatório usar o free quando a memória não for mais necessária. 
Esquecer de usá-lo causa o que chamamos de memory leak (vazamento de memória), 
onde seu programa consome cada vez mais RAM até travar.

free(ptr);
ptr = NULL; // Boa prática para evitar ponteiros soltos (dangling pointers)

Um dangling pointer (ou ponteiro pendente/solto) acontece 
quando um ponteiro continua apontando para um endereço de memória que já foi liberado ou desalocado.

Imagine que o ponteiro é um cartão de visitas com o endereço de uma casa. 
Se a casa for demolida, o endereço no cartão continua o mesmo, mas se você tentar 
ir até lá, não encontrará o que esperava. Você estará acessando um local que não "te pertence" mais.
*/

/*
// C++ Style
int* ptr = new int(10); // Aloca um int e já inicializa com 10
delete ptr;             // Libera a memória

int* array = new int[5]; // Aloca um array de 5 inteiros
delete[] array;          // Nota: para arrays, usamos delete[]
*/

int main(void){

    example3();
    return 0;
}