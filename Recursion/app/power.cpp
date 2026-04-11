#include <iostream>

using namespace std;

/// Operação de Potência: n^b

int power(int n, int b){

    if(b == 0){
        return 1;
    }
    else{
        return n*power(n,b-1);
    }
}


int main(){

    int x = power(3,4);

    cout << x << endl;

    return 0;
}