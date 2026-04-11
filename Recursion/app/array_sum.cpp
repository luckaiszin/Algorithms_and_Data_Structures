#include <iostream>

using namespace std;

int sum_array_helper(int *A, int tamanho,int soma){

    if(tamanho == 1){
        return A[tamanho-1];
    }
    else{
        soma += A[tamanho-1] + sum_array_helper((A + 1),tamanho-1,soma);
        return soma;
    }

    return 0;
}


int sum_array(int *A){
    int soma = 0;
    return sum_array_helper(A,sizeof(A)/sizeof(int),soma);
}

int main(){

    int A[] = {2,6,7};
    cout << sum_array(A) << endl;
    return 0;
}