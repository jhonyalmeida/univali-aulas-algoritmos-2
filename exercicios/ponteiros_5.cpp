#include <iostream>

using namespace std;

void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << ", ";
    }
}

int main () {
    int tamanho;
    cout << "Qual o tamanho do vetor?" << endl;
    cin >> tamanho;

    int *vetor = (int*) malloc(sizeof(int) * tamanho);

    int pares = 0;

    cout << "Digite os elementos:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cin >> vetor[i];
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    int *vetorPares = (int*) malloc(sizeof(int) * pares);
    int atual = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            vetorPares[atual] = vetor[i];
            atual++;
        }
    }

    cout << "Vetor original:" << endl;
    exibirVetor(vetor, tamanho);

    cout << "Vetor pares:" << endl;
    exibirVetor(vetorPares, pares);

    vetor = nullptr;

    free(vetor);
    free(vetorPares);

    vetor = nullptr;
    vetorPares = nullptr;

    cout << "Teste";

    return 0;
}
