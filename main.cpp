#include <iostream>
#include <algorithm>
#include "matrix.h"
#include <string>

using namespace std;

int main() { 
    int n, m;
    cout << "Input how many rows and columns: "<<endl;
    n = getIntNoZero("Rows");
    m = getIntNoZero("Colums");

    Matrix mat;
    create_mat(&mat, n, m, n * m);
    init(&mat);

    cout << "Old matrix: " << endl;
    print_matrix(&mat);
    SortByMax(&mat);
    cout << "New matrix: " << endl;
    print_matrix(&mat);

    matrix_clear(&mat);
    getchar();
}