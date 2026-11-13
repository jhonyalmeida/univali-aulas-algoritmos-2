#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Crie um sistema de cadastro simples de contatos
 * (ou produtos, ou outra entidade que preferir),
 * que carregue os dados de um arquivos, permita exibir a
 * lista completa de cadastros , buscar um item específico,
 * ou inserir um novo cadastro que deverá ser agregado ao arquivo.
 */

struct Contato {
    string nome;
    int idade;
    string email;
};

vector<Contato> carregarDados() {
    //FILE *arquivo = fopen("pessoas.csv", "r");
    ifstream arquivo("pessoas.csv");
    vector<Contato> contatos;
    //char linha[120];
    string linha;
    while (getline(arquivo, linha)) {
        Contato contato;
        stringstream linhaPessoa(linha);
        if (getline(linhaPessoa, contato.nome, ';')
            && linhaPessoa >> contato.idade
            && linhaPessoa.ignore()
            && getline(linhaPessoa, contato.email)) {
            contatos.push_back(contato);
        }
    }
    /*
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        Contato contato;
        if (sscanf(linha, " %49[^;];%d;%49[^\n]",
            contato.nome, &contato.idade, contato.email) == 3) {
            contatos.push_back(contato);
        }
    }
    */
    arquivo.close();
    //fclose(arquivo);
    return contatos;
}

void gravar(Contato novoContato) {
    //FILE *arquivo = fopen("pessoas.csv", "a");
    ofstream arquivo("pessoas.csv", ofstream::app);
    //fprintf(arquivo, "\n%s;%d;%s",
    //novoContato.nome,
    //novoContato.idade,
    //novoContato.email);
    //fclose(arquivo);
    arquivo << "\n" <<
        novoContato.nome << ";" << novoContato.idade << ";" << novoContato.email;
    arquivo.close();
}

int main() {
    vector<Contato> contatos = carregarDados();

    for (int i = 0; i < contatos.size(); i++) {
        cout << contatos[i].email << " tem " << contatos[i].idade << " anos\n";
    }

    Contato novoContato;
    cout << "--- Nova pessoa ---";
    cout << "\nDigite seu nome: ";
    cin >> novoContato.nome;
    cout << "\nDigite sua idade: ";
    cin >> novoContato.idade;
    cout << "\nDigite seu e-mail: ";
    cin >> novoContato.email;
    contatos.push_back(novoContato);
    gravar(novoContato);


}