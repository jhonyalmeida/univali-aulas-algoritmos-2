#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    // Abre o arquivo em modo de leitura e escrita (o arquivo já deve existir)
    FILE *file = fopen("exemplo.txt", "r+");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo ou arquivo não existe.\n");
        return 1;
    }

    char buffer[100];

    cout << "Conteúdo atual do arquivo: \n";
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // 2. Para alternar da leitura para a escrita, use fseek para reposicionar o cursor
    // Aqui vamos reposicionar o cursor para o início do arquivo (ou para onde quiser)
    fseek(file, 0, SEEK_SET);

    // 3. Escrevendo novos dados (sobrescrevendo a partir do ponto atual do cursor)
    fprintf(file, "Batata doce\n");

    // Fecha o arquivo para salvar as alterações
    fclose(file);

    return 0;
}