#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Retorna um número pseudo-aleatório entre 1 e max
 */
int getNumeroAleatorio(int max) {
    srand(time(nullptr));
    return rand() % max + 1;
}

int main () {
    cout << getNumeroAleatorio(15) << endl;
    return 0;
}