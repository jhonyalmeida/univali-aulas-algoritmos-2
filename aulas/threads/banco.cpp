#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void rendimento(int &saldo, mutex &mtx) {
    while (true) {
        mtx.lock();
        saldo += 1;
        mtx.unlock();
        sleep(60);
    }
}

void sacarValor(int &saldo, int valor, mutex &mtx) {
    mtx.lock();
    saldo -= valor;
    mtx.unlock();
}

void depositarValor(int &saldo, int valor, mutex &mtx) {
    mtx.lock();
    saldo += valor;
    mtx.unlock();
}

void interface(int &saldo, mutex &mtx) {
    int acao = 0;
    int valor = 0;
    while (acao != 3) {
        cout << "O que deseja fazer?" << endl;
        cout << "(0) Ver saldo" << endl;
        cout << "(1) Saque" << endl;
        cout << "(2) Depósito" << endl;
        cout << "(3) Sair" << endl;
        cin >> acao;
        if (acao == 1) {
            cout << "Qual o valor?" << endl;
            cin >> valor;
            sacarValor(saldo, valor, mtx);
        }
        if (acao == 2) {
            cout << "Qual o valor?" << endl;
            cin >> valor;
            depositarValor(saldo, valor, mtx);
        }
        if (acao == 3) {
            exit(0);
        }
        cout << "Saldo atual: " << saldo << endl;
    }
}

int main() {
    int saldo = 100;
    mutex m;

    thread a = thread(rendimento, ref(saldo), ref(m));
    thread b = thread(interface, ref(saldo), ref(m));

    a.join();
    b.join();

    cout << saldo << endl;
    return 0;
}
