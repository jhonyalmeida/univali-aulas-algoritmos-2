#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string nomeDoArquivo = "pessoas.csv";

    // Leitura: ifstream substitui fopen modo leitura
    ifstream entrada(nomeDoArquivo);

    if (!entrada.is_open()) {
        cout << "Não foi possível abrir o arquivo";
        return 1;
    }

    string linha;
    string nome;
    int idade;
    string email;
    while (getline(entrada, linha)) {
        stringstream ss(linha);
        // getline com delimitador ';' substitui o sscanf com %[^;]
        // ss.ignore() pula o ';' que fica depois da idade
        if (getline(ss, nome, ';') && ss >> idade && ss.ignore() && getline(ss, email)) {
            cout << "\n" << nome << " tem " << idade << " anos e e-mail " << email;
        }
    }
    entrada.close();

    // Escrita: ofstream com ofstream::app substitui fopen(..., "a")
    // Para escrita em modo sobrescrita ("w"), trocar o parâmetro por ofstream::out
    ofstream saida(nomeDoArquivo, ofstream::app);

    if (!saida.is_open()) {
        cout << "Não foi possível abrir o arquivo para escrita";
        return 1;
    }

    cout << "\n\n--- Nova pessoa ---";
    cout << "\nNome: ";
    getline(cin, nome);
    cout << "Idade: ";
    cin >> idade;
    cout << "E-mail: ";
    getline(cin >> ws, email); // ws descarta o Enter que sobrou depois da idade

    saida << "\n" << nome << ";" << idade << ";" << email;
    saida.close();

    return 0;
}
