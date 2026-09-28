#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int** criarMatrizCpp(int linhas, int colunas) {
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
    return matriz;
}

int** criarMatrizC(int linhas, int colunas) {
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
    return matriz;
}

void exibirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    matriz = nullptr;
}

int main() {
    srand(time(NULL));

    int linhas;
    int colunas;
    int combinacoes;

    cout << "Número de linhas da matriz:" << endl;
    cin >> linhas;

    cout << "Número de colunas da matriz:" << endl;
    cin >> colunas;

    cout << "Número combinações:" << endl;
    cin >> combinacoes;

    int **matriz;
    for (int i = 0; i < combinacoes; i++) {
        cout << "\n";
        matriz = criarMatriz(linhas, colunas);
        exibirMatriz(matriz, linhas, colunas);
        liberarMatriz(matriz, linhas);
    }

    return 0;
}
