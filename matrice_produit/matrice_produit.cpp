//232350 ahmad abou zeid
#include <iostream>

using namespace std;


void allocate(int**& p, int n, int m) {
    p = new int* [n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[m];
    }
}

int** allocate(int n, int m) {
    int** p = new int* [n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[m];
    }
    return p;
}

void fill(int** p, int n, int m, int e = 1) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = i + j * e;
        }
    }
}

void afficher(int** p, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

void deallocation(int**& p, int n) {
    for (int i = 0; i < n; i++) {
        delete[] p[i];
    }
    delete p;
}

void produit_matrice(int**& matrice_3, int**& m1, int**& m2, int l1, int c1, int l2, int c2, int& l3, int& c3) {
    matrice_3 = new int* [l1];
    if (l1 == c2) {
        l3 = l1;
        c3 = c2;
        for (int i = 0; i < l1; i++) {
            matrice_3[i] = new int[c2];
            for (int j = 0; j < c2; j++) {
                matrice_3[i][j] = 0;
                for (int z = 0; z < l2; z++) {
                    matrice_3[i][j] += m1[i][z] * m2[z][j];
                }
            }
        }
    }
}


int main() {
    int n = 3;
    int m = 4;


    int** mat1 = nullptr;

    allocate(mat1, n, m);
    cout << sizeof(mat1) << endl;
    cout << endl;

    fill(mat1, n, m);

    cout << "mat1" << endl;
    afficher(mat1, n, m);


    int** mat2 = nullptr;

    allocate(mat2, m, n);
    cout << sizeof(mat2) << endl;
    cout << endl;

    fill(mat2, m, n);

    cout << "mat2" << endl;
    afficher(mat2, m, n);

    int** matrice_3 = nullptr;
    int n3, m3;
    produit_matrice(matrice_3, mat1, mat2, n, m, m, n, n3, m3);
    cout << "mat3=mat1*mat2" << endl;
    afficher(matrice_3, n3, m3);


    deallocation(mat1, n);
    deallocation(mat2, m);
    deallocation(matrice_3, n3);

    return 0;
}
