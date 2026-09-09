#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

//Fórmula 2D: Para dois pontos A = (x₁, y₁) e B = (x₂, y₂), a fórmula é |x₁ - x₂| + |y₁ - y₂|.

struct Posicao {
    int x; //linha
    int y; //coluna
};

int calcularDistancia(Posicao p1, Posicao p2) {
    int x = abs(p1.x - p2.x);
    int y = abs(p1.y - p2.y);
    return x + y;
}
