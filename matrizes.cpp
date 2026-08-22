#include <iostream>
#include "matrizes.hpp"

using namespace std;

void multiplicarMatriz (int matriz [3][3], int multiplicador) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = matriz[i][j] * multiplicador;
        }
    }
}

void exibirMatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout<< matriz[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}
