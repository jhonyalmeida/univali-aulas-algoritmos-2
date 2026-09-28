#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));
    int *vet = new int[10];
    int *pointer = vet;
    for (int i = 0; i < 10; i++) {
        *pointer = rand() % 10;
        pointer++;
    }
    pointer -= 10;
    for (int i = 0; i < 10; i++) {
        cout << pointer << ": " << *pointer << " " << endl;
        pointer++;
    }
    delete vet;
}