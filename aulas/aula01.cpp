/*
 Dado um vetor de 15 números inteiros (pré-inicializado com valores aleatórios ou preenchido pelo usuário), escreva um algoritmo que:
 encontre o maior e o menor valor
 - calcule a média dos elementos
 - conte quantos valores são maiores que a média
 - crie um segundo vetor contendo apenas os valores acima da média
 - exiba todas as informações coletadas acima
*/

#include <iostream>

using namespace std;

int aula01() {

    int vetor[15] = { 1, 2, 3, 43, 5, 6, 7, 83,
        9, 10, 119, 12, 131, 14, 157 };

    int menor = vetor[0];
    int maior = vetor[0];
    double total = vetor[0];
    double media = 0.0;

    for (int i = 1; i < 15; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        total += vetor[i];
    }

    media = total / 15;

    int countAcimaMedia = 0;

    for (int i = 0; i < 15; i++) {
        if (vetor[i] > media) {
            countAcimaMedia++;
        }
    }

    int numerosAcimaMedia[countAcimaMedia];

    int j = 0;
    for (int i = 0; i < 15; i++) {
        if (vetor[i] > media) {
            numerosAcimaMedia[j] = vetor[i];
            j++;
        }
    }


    cout << "Maior: " << maior << "\n";
    cout << "Menor: " << menor << "\n";
    cout << "Média: " << media << "\n";
    cout << "Qtd acima da média: " << countAcimaMedia << "\n";
    cout << "Números acima da média: \n";
    for (int i = 0; i < countAcimaMedia; i++) {
        cout << numerosAcimaMedia[i] << "\n";
    }


    return 0;
}
