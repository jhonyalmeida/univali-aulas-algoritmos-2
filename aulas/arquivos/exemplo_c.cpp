#include <iostream>

using namespace std;

int main() {
    char nomeDoArquivo[50] = "pessoas.csv";
    FILE *arquivo = fopen(nomeDoArquivo, "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo");
        return 1;
    }

    char linha[150];
    char nome[50];
    int idade;
    char email[80];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, " %49[^;];%d;%79[^\n]", nome, &idade, email) == 3) {
            printf("\n%s tem %d anos e e-mail %s", nome, idade, email);
        }
    }
    fclose(arquivo);

    arquivo = fopen(nomeDoArquivo, "a");

    cout << "\n\n--- Nova pessoa ---";
    cout << "\nNome: ";
    cin.getline(nome, sizeof(nome)); // lê a linha inteira, permitindo espaços
    cout << "Idade: ";
    cin >> idade;
    cout << "E-mail: ";
    cin >> ws; // descarta o Enter que sobrou depois da idade
    cin.getline(email, sizeof(email));

    fprintf(arquivo, "\n%s;%d;%s", nome, idade, email);
    fclose(arquivo);

    return 0;
}