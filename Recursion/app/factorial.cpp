#include <iostream>

using namespace std;

/// Implementação da operação factorial em recursão

int factorial(int n){

    if(n == 0){ /// Base Case
        return 1;
    }
    else{
        return n*factorial(n-1); /// Passo Recursivo
    }
}

int main(){

    int x = factorial(2);

    cout << x << endl;

    return 0;
}