#include <iostream>

using namespace std;

template<typename T>
void duplicarLinha(T m[][3], int i) {
    for(int j = 0; j < 3; j++) {
        m[i][j] *= 2;
    }
}

int main() {
    int mat[3][3] = {
        {6,4,3},
        {2,3,6},
        {3,4,5}
    };

    duplicarLinha(mat, 1);
    cout << mat[1][2];
    return 0;
}








