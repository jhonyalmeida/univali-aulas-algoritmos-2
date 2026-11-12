#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    // Estilo C++

    // Escrita
    ofstream saida("exemplo_cpp.txt");
    if (saida.is_open()) {
        saida << "Olá, Mundo em C++!" << endl;
        saida.close(); //
    }

    // Leitura
    ifstream entrada("exemplo_cpp.txt");
    string linha;
    if (entrada.is_open()) {
        while (getline(entrada, linha)) {
            cout << linha << endl;
        }
        entrada.close();
    }


    // Estilo C

    // Escrita
    FILE *arquivo = fopen("exemplo_c.txt", "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "Olá, Mundo em C++!\n");
        fclose(arquivo);
    }

    // Leitura
    char linha_2[100];
    arquivo = fopen("exemplo_c.txt", "r");
    if (arquivo != NULL) {
        while (fgets(linha_2, sizeof(linha_2), arquivo) != NULL) {
            cout << linha_2 << endl;
        }
        fclose(arquivo);
    }

    return 0;
}