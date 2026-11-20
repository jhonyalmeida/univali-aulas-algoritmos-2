#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream arquivo("arquivos/pessoas.csv");

    if (!arquivo.is_open()) {
        cout << "Não foi possível abrir o arquivo\n";
        return 1;
    }

    // 1. Monta o índice: guarda em que byte começa cada linha.
    // vector cresce sozinho, então não há limite fixo de linhas.
    vector<streampos> inicioLinha;
    string linha;

    while (true) {
        streampos posicao = arquivo.tellg(); // posição antes de ler a linha
        if (!getline(arquivo, linha)) {
            break;
        }
        inicioLinha.push_back(posicao);
    }

    cout << "O arquivo tem " << inicioLinha.size() << " linhas.\n";

    // 2. Pede ao usuário o número da linha (começando em 1)
    int numero;
    cout << "Qual linha deseja ver? ";
    if (!(cin >> numero) || numero < 1 || numero > (int) inicioLinha.size()) {
        cout << "Linha inválida.\n";
        return 1;
    }

    // 3. A leitura parou no fim do arquivo (estado eof).
    // É preciso limpar esse estado antes do seekg, senão ele não funciona.
    arquivo.clear();

    // Vai direto para o início da linha com seekg e lê só ela
    arquivo.seekg(inicioLinha[numero - 1]);
    getline(arquivo, linha);

    cout << "Linha " << numero << " (byte " << inicioLinha[numero - 1] << "): " << linha << "\n";

    return 0;
}
