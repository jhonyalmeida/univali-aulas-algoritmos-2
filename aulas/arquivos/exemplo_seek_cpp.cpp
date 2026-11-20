#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Abre o arquivo em modo de leitura e escrita (equivalente ao "r+").
    // Assim como no "r+", o arquivo já deve existir.
    fstream arquivo("exemplo.txt", fstream::in | fstream::out);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo ou arquivo não existe.\n";
        return 1;
    }

    string linha;

    // 1. Lendo o conteúdo atual
    cout << "Conteúdo atual do arquivo:\n";
    while (getline(arquivo, linha)) {
        cout << linha << "\n";
    }

    // 2. Ao terminar a leitura, o stream fica com o estado de fim de arquivo (eof).
    // Enquanto esse estado estiver ativo, nenhuma operação funciona,
    // então é preciso limpá-lo com clear() antes de reposicionar o cursor.
    arquivo.clear();

    // seekp reposiciona o cursor de escrita (p = put); seekg é o de leitura (g = get).
    // Aqui vamos para o início do arquivo, equivalente a fseek(file, 0, SEEK_SET).
    arquivo.seekp(0, fstream::beg);

    // 3. Escrevendo novos dados (sobrescrevendo a partir do ponto atual do cursor)
    arquivo << "Linha sobrescrita no início!\n";

    // Fecha o arquivo para salvar as alterações
    arquivo.close();

    return 0;
}
