#include <iostream>

using namespace std;

/// Ocorre quando uma função A chama uma função B, e a função B chama a função A.

bool is_even(int n);
bool is_odd(int n);

bool is_even(int n){

    if(n==0){
        return true;
    }
    else{
        return is_odd(n-1);
    }
}

bool is_odd(int n){
    if(n==0){
        return false;
    }
    else{
        return is_even(n-1);
    }
}

int main(){

    cout << is_even(4) <<endl;
    return 0;
}