#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>

using namespace std;

const int CHEGADA = 10;

void correr(string nome) {

    int posicao = 0;

    while (posicao < CHEGADA) {

        usleep(60000 * 1000);
        posicao++;

        cout << nome << " |" << string(posicao, '=') << ">"
                     << (CHEGADA - posicao) << "| "
                     << posicao << "/" << CHEGADA << "\n";
    }

    cout << ">>> " + nome + " cruzou a linha de chegada!\n";
}

int main() {
    srand(time(NULL));

    cout << "Preparar... Apontar... Já!\n\n";

    thread corredor1(correr, "Thread A");
    thread corredor2(correr, "Thread B");
    thread corredor3(correr, "Thread C");
    thread corredor4(correr, "Thread D");

    corredor4.join();
    corredor1.join();
    corredor2.join();
    corredor3.join();

    cout << "\nFim da corrida! A ordem de chegada aparece acima.\n";

    return 0;
}
