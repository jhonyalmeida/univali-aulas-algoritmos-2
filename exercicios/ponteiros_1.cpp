#include <iostream>

using namespace std;

struct Pessoa {
    string nome;
    Pessoa *contato;
    string *outroNome;
};


void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << ", ";
    }
}

int exercicioPonteiros1() {
    Pessoa p;
    p.nome = "Joao";

    p.contato = new Pessoa();
    p.contato->nome = "Maria";

    cout << p.contato->outroNome << endl;

    int tamanho;
    cout << "Qual o tamanho do vetor?" << endl;
    cin >> tamanho;

    int *vetor1 = new int[6];

    int *vetor = vetor1;
    cout<<vetor;
    cout<<*vetor;

    int pares = 0;

    cout << "Digite os elementos:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cin >> vetor[i];
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    int *vetorPares = new int[pares];
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

    delete[] vetor;
    delete[] vetorPares;
}
