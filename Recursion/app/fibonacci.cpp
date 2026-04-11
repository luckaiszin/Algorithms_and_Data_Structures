#include <iostream>

using namespace std;

/// Implementação do fibonacci em recursão

int fibonacci(int n){

    if(n == 0 || n == 1){ /// Base Case
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2); /// Passo Recursivo
    }
}

int main(){

    int x = fibonacci(7);

    cout << x << endl;

    return 0;
}