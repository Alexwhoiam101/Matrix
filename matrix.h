#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

struct Matrix {
    int n, m, max_size;
    int *row;
    int *col;
    int *val;
};

int compare_up(const void *x1, const void *x2);
int compare_no_up(const void *x1, const void *x2);
void create_mat(Matrix *mat, int row, int col, int maxsize);
void matrix_clear(Matrix *mat);
template<typename T>
void resize(T *&arr, int oldSize, int newSize, const T initVal);
int add(Matrix *mat, int row, int col, int val);
int get(Matrix *mat, int row, int col);
void print_matrix(Matrix *mat);
int getInt(std::string cap);
int getIntNoZero(std::string cap);
void init(Matrix *mat);
void SortByMax(Matrix *mat);

#endif //UNTITLED_MATRIX_H
