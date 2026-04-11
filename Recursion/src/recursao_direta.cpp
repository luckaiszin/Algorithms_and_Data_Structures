#include <iostream>

using namespace std;

///É o tipo mais comum, onde a função chama a si mesma diretamente.
/// Por que funciona: É fácil de visualizar a pilha de chamadas diminuindo o valor de $N$ até chegar em 0.
/// Lógica: $Soma(n) = n + Soma(n-1)$.

int soma(int n){

    if(n == 1){
        return 1;
    }
    return n + soma(n-1);
}

int main(){

    int x = soma(3);

    cout << x << endl;

    return 0;
}