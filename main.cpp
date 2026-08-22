#include <iostream>
#include <string>

using namespace std;

template <typename T, typename V>
V somar(T t1, T t2);


template <typename V>
void somar(V v1[3], V v2[3], V res[3]) {
    for (int i = 0; i < 3; i++) {
        res[i] = somar(v1[i], v2[i]);
    }
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

template <typename T>
void ordenar(vector<T> &v) {
    T aux;
    int n = v.size();
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

template <typename V>
void exibir(V v[], int size);


vector<int> criarVetor() {
    vector<int> vec;
    int num;
    while (true) {
        cout<<"Digite um número\n";
        cin >> num;
        if (num == 0) {
            break;
        }
        vec.push_back(num);
    }
    return vec;
}

int acharMaior(vector<int> vec) {
    int maior = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (maior < vec[i]) {
            maior = vec[i];
        }
    }
    return maior;
}

int acharMenor(vector<int> vec) {
    int menor = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (menor > vec[i]) {
            menor = vec[i];
        }
    }
    return menor;
}

float calcularMedia(vector<int> vec) {
    float soma = 0;
    for (int i = 0; i < vec.size(); i++) {
        soma += vec[i];
    }
    return soma / vec.size();
}

float acharMediana(vector<int> vec) {
    ordenar(vec);
    int meio = vec.size() / 2;
    if (vec.size() % 2 == 0) {
       float soma = vec[meio - 1] + vec[meio];
       return soma / 2;
    } else {
       return vec[meio];
    }
}

int main () {
    vector<int> vec = criarVetor();

    int maior = acharMaior(vec);
    int menor = acharMenor(vec);
    float media = calcularMedia(vec);
    float med = acharMediana(vec);

    cout << maior << " " << menor << " " << media << endl;
    cout << "Mediana: " << med;

    return 0;
}





template <typename V>
void exibir(V v[], int size) {
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T, typename V>
V somar(T t1, T t2) {
    return t1+t2;
}

// float vet[10] = {9,8,7,6,5,8,3,2.6,10,0};
// string vet2[3] = {"batata", "alface", "abobora"};
// char vet3[5] = {'a','b','c','d','e'};
//
// ordenar(vet, 10);
// ordenar(vet2, 3);
// ordenar(vet3, 5);
//
// exibir(vet, 10);
// exibir(vet2, 3);
// exibir(vet3, 5);








//
// vector<int> vecInt;
// vecInt.push_back(8);
// vecInt.push_back(2);
// vecInt.push_back(5);
//
// cout << "\nVector loop by index: ";
// for (int i = 0; i < vecInt.size(); i++) {
//     cout << vecInt[i] << " ";
// }
//
// cout << "\nVector loop by element: ";
// for (const auto num : vecInt) {
//     cout << num << " ";
// }