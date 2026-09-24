#include <iostream>

using namespace std;

int acharMaior(int vet[5], int tamanho) {
    int maior = vet[0];
    for (int i = 1; i < tamanho; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
    return maior;
}

void acharMaior(int vet[5], int tamanho, int &maior) {
    maior = vet[0];
    for (int i = 1; i < tamanho; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
}

int aula04() {
    int vet[5]  = {2,8,3,4,5} ;

    cout << acharMaior(vet, 5) << endl;
    int maior = 0;
    acharMaior(vet, 5, maior);
    cout << maior;

    return 0;
}
