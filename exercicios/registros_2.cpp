#include <iostream>
#include<string>
#include <vector>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
    string email;
    Pessoa *contatoEmergencia;
};

Pessoa cadastrar() {
    Pessoa p;
    Pessoa* contato = new Pessoa;
    cout << "Nome:\n";
    cin >> p.nome;
    cout << "Idade:\n";
    cin >> p.idade;
    cout << "Email:\n";
    cin >> p.email;
    cout << "Nome do contato de emergência:\n";
    cin >> contato->nome;
    cout << "Email do contato de emergência:\n";
    cin >> contato->email;
    p.contatoEmergencia = contato;
    return p;
}

void listar(vector<Pessoa> pessoas) {
    for (Pessoa p : pessoas) {
        cout << endl;
        cout << p.nome << endl;
        cout << p.idade << endl;
        cout << p.email << endl;
        cout << p.contatoEmergencia->nome << endl;
        cout << p.contatoEmergencia->idade << endl;
        cout << endl;
    }
}

int main () {
    vector<Pessoa> pessoas;
    Pessoa p;

    int opcao = 0;
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Cadastrar pessoa" << endl;
        cout << "2 - Listar pessoas" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;
        switch (opcao) {
            case 1:
                p = cadastrar();
                pessoas.push_back(p);
                break;
            case 2:
                listar(pessoas);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}
