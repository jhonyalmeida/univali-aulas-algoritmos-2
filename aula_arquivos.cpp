#include <iostream>

using namespace std;

int main() {
    FILE *arquivo = fopen("pessoas.txt", "w");

    if (arquivo == NULL) {
        cout << "arquivo não encontrado";
        return 1;
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        cout << linha;
    }

    fclose(arquivo);

    return 0;
}