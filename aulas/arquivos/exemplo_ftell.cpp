#include <stdio.h>
#include <string.h>

#define MAX_LINHAS 1000

int main() {
    FILE *arquivo = fopen("../../arquivos/pessoas.csv", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        return 1;
    }

    // 1. Monta o índice: guarda em que byte começa cada linha
    long inicioLinha[MAX_LINHAS];
    int total = 0;
    char buffer[150];

    while (total < MAX_LINHAS) {
        long posicao = ftell(arquivo); // posição antes de ler a linha
        if (fgets(buffer, sizeof(buffer), arquivo) == NULL) {
            break;
        }
        inicioLinha[total] = posicao;
        total++;
    }

    printf("O arquivo tem %d linhas.\n", total);

    // 2. Pede ao usuário o número da linha (começando em 1)
    int numero;
    printf("Qual linha deseja ver? ");
    if (scanf("%d", &numero) != 1 || numero < 1 || numero > total) {
        printf("Linha inválida.\n");
        fclose(arquivo);
        return 1;
    }

    fseek(arquivo, inicioLinha[numero - 1], SEEK_SET);
    fgets(buffer, sizeof(buffer), arquivo);

    printf("Linha %d (byte %ld): %s\n", numero, inicioLinha[numero - 1], buffer);

    fclose(arquivo);
    return 0;
}
