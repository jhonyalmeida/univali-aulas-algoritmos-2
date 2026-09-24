#include <iostream>
#include<string>
#include <vector>

using namespace std;

struct Curso {
    int codigo;
    string nome;
    float duracaoHoras;
};

void cadastrar(vector<Curso>& cursos) {
    Curso curso = {};
    cout<<"Digite o codigo do curso: \n";
    cin>>curso.codigo;
    cout<<"Digite o nome do curso: \n";
    cin>>curso.nome;
    cout<<"Digite o duracao do curso: \n";
    cin>>curso.duracaoHoras;
    cursos.push_back(curso);
}

void exibirTodos(vector<Curso> cursos) {
    for (int i = 0; i < cursos.size(); i++) {
        cout << cursos[i].codigo << " - " << cursos[i].nome << endl;
    }
}

Curso buscar(vector<Curso> cursos, int codigo) {
    for (int i = 0; i < cursos.size(); i++) {
        if (cursos[i].codigo == codigo) {
            return cursos[i];
        }
    }
    return Curso{0,"",0};
}

void buscarCurso(vector<Curso> cursos) {
    cout<<"Qual o código?\n";
    int codigo;
    cin>>codigo;
    Curso c = buscar(cursos, codigo);
    cout << c.codigo << " - " << c.nome << endl;
}

int exercicioRegistros1 () {
    vector<Curso> cursos;
    bool saida = false;
    int opcao = 0;
    while (!saida) {
        cout<<"Digite uma opcao: \n";
        cout<<"1 - Cadastrar curso\n";
        cout<<"2 - Exibir todos\n";
        cout<<"3 - Buscar\n";
        cout<<"4 - Sair\n";
        cin >> opcao;
        switch (opcao) {
            case 1:
                cadastrar(cursos);
                break;
            case 2:
                exibirTodos(cursos);
                break;
            case 3:
                buscarCurso(cursos);
                break;
            case 4:
                saida = true;
        }
    }

    return 0;
}
