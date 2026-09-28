#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T, typename U>
U* mapear(T *vetor, int tamanho, U (*mapper)(T)) {
    U *resultado = (U*) malloc(tamanho * sizeof(U));
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = mapper(vetor[i]);
    }
    return resultado;
}

struct Aluno {
    string nome;
    float medias[3];
};

float calcularMediaFinal(Aluno aluno) {
    return (aluno.medias[0] + aluno.medias[1] + aluno.medias[2]) / 3;
}

int main() {
    Aluno alunos[3] = {
        {"Anna", {8.0, 7.5, 9.0}},
        {"Billy", {5.5, 6.0, 7.0}},
        {"Carla", {10.0, 9.0, 8.5}}
    };

    float *mediasFinais = mapear(alunos, 3, calcularMediaFinal);

    for (int i = 0; i < 3; i++) {
        cout << alunos[i].nome << ": " << mediasFinais[i] << endl;
    }

    free(mediasFinais);
}
