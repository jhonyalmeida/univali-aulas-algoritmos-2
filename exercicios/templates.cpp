#include <iostream>
#include <string>

using namespace std;

//Protótipos

template <typename V>
void exibir(V v[], int size);

template <typename U>
void inverter(U v[], int n);

template <typename T>
void ordenar(T v[], int n);

//Main

int main () {
    float vet[10] = {9,8,7,6,5,8,3,2.6,10,0};
    string vet2[3] = {"batata", "alface", "abobora"};
    char vet3[5] = {'a','b','c','d','e'};

    ordenar(vet, 10);
    ordenar(vet2, 3);
    ordenar(vet3, 5);

    exibir(vet, 10);
    exibir(vet2, 3);
    exibir(vet3, 5);
}

//Templates das funções

template <typename V>
void exibir(V v[], int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename U>
void inverter(U v[], int n) {
    U aux;
    for (int i = 0; i < n/2; i++) {
        aux = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = aux;
    }
}

template <typename T>
void ordenar(T v[], int n) {
    T aux;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (v[j] < v[i]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
