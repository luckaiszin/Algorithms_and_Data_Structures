#include <iostream>

// Função de Ackermann
unsigned long long ackermann(unsigned long long m, unsigned long long n) {
    if (m == 0) {
        return n + 1;
    } 
    else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } 
    else {
        // Exemplo clássico de NESTED RECURSION
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    unsigned long long m = 3, n = 4;
    std::cout << "Calculando A(" << m << ", " << n << ")..." << std::endl;
    std::cout << "Resultado: " << ackermann(m, n) << std::endl;
    return 0;
}