#include <iostream>

using namespace std;

template<typename T>
T* filtrar(T* vetor, int tamanho, bool (*filtro)(T), int &novoTamanho) {
    novoTamanho = 0;
    for (int i = 0; i < tamanho; i++) {
        if (filtro(vetor[i])) {
            novoTamanho++;
        }
    }
    T *novoVetor = new T[novoTamanho];
    int counter = 0;
    for (int i = 0; i < tamanho; i++) {
        if (filtro(vetor[i])) {
            novoVetor[counter] = vetor[i];
            counter++;
        }
    }
    return novoVetor;
}

bool isPar(int numero) {
    return (numero % 2 == 0);
}

bool isImpar(int numero) {
    return (numero % 2 != 0);
}

bool isMaiorQue(int comparando, int comparador) {
    return comparando > comparador;
}

int main () {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int novoTamanho;
    int *pares = filtrar(vetor, 9, isPar, novoTamanho);
    for (int i = 0; i < novoTamanho; i++) {
        cout << pares[i] << " ";
    }
    cout << endl;
    int *impares = filtrar(vetor, 9, isImpar, novoTamanho);
    for (int i = 0; i < novoTamanho; i++) {
        cout << impares[i] << " ";
    }

    return 0;
}