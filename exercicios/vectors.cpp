#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Protótipos das funções

vector<int> criarVetor();
int acharMaior(vector<int> vec);
int acharMenor(vector<int> vec);
float calcularMedia(vector<int> vec);
float acharMediana(vector<int> vec);
template <typename T> void ordenar(vector<T> &v);

//Main

int main() {
    vector<int> vec = criarVetor();

    int maior = acharMaior(vec);
    int menor = acharMenor(vec);
    float media = calcularMedia(vec);
    float med = acharMediana(vec);

    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;
    cout << "Media: " << media << endl;
    cout << "Mediana: " << med;

    return 0;
}

//Funções

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