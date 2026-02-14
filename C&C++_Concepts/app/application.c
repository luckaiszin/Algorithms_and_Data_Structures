#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int id;
    char title[20];
    char autor[20];
    int year;

} livro;

livro* adicionarLivro(livro li, livro* catalogo, int* quantidade_de_livros, int* capacidade_atual){

    if(*quantidade_de_livros == *capacidade_atual){
        /// Usa o Realloc para alocar mais espaço no heap
        *capacidade_atual += *capacidade_atual;
        livro *temp = (livro *)realloc(catalogo,(*capacidade_atual)*sizeof(livro)); // O realloc elimina o endereço original
        if(temp == NULL){
            printf("Erro: Memória insuficiente para realocar.\n");
            free(catalogo); // Libera o que já existia antes de sair
            exit(1);
        }
        else{
            catalogo = temp;
            catalogo[*quantidade_de_livros] = li;
            *quantidade_de_livros += 1;
        }
        
    }
    else{
        catalogo[*quantidade_de_livros] = li;
        *quantidade_de_livros += 1;
    }

    return catalogo;
}

void listarLivro(livro* catalogo,int* quantidade_de_livro){
    for(int i = 0; i<*quantidade_de_livro; i++){
        printf("%s \n",(catalogo + i)->title);
    }
}

livro* liberarCatalogo(livro* catalogo){
    free(catalogo);
    catalogo = NULL;
    return catalogo;
}

int main(void){

    int capacidade_atual = 2;
    int quantidade_de_livros = 0;
    livro *catalogo;
    catalogo = (livro*)calloc(capacidade_atual,sizeof(livro));

    return 0;
}