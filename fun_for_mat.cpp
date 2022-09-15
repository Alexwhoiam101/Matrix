#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdlib>
#include "matrix.h"
#include <string>

using namespace std;

int compare_up(int x1, int x2) { return x1 - x2; }

int compare_no_up(int x1, int x2) { return x2 - x1; }

void create_mat(Matrix *mat, int row, int col, int maxsize) {
    mat->n = row;
    mat->m = col;
    mat->max_size = maxsize;

    mat->row = new int[row + 1];
    mat->col = new int[maxsize];
    mat->val = new int[maxsize];

    for (int i = 0; i < row + 1; i++) {
        mat->row[i] = 0;
    }
}

void matrix_clear(Matrix *mat) {
    delete[] mat->col;
    delete[] mat->val;
    delete[] mat->row;
}

template<typename T>
void resize(T *&arr, int oldSize, int newSize, const T initVal) {
    T *newArray = new T[newSize];

    std::copy(arr, arr + std::min(oldSize, newSize), newArray);

    if (oldSize < newSize)
        std::fill(newArray + oldSize, newArray + newSize, initVal);

    delete[] arr;
    arr = newArray;
}

int add(Matrix *mat, int row, int col, int val) {
    int i, j;

    if ((row >= mat->n) || (col >= mat->m))
        return 1;
    for (i = mat->row[row]; i < mat->row[row + 1]; i++) {
        if (mat->col[i] == col) {
            if (val) {
                mat->val[i] = val;
                return 0;
            }
            for (j = i; j < (mat->row[mat->n] - 1); j++) {
                mat->val[j] = mat->val[j + 1];
                mat->col[j] = mat->col[j + 1];
            }
            for (j = row + 1; j < (mat->n + 1); j++) {
                mat->row[j]--;
            }

            return 0;
        }
    }

    if (!val)
        return 0;

    if (mat->row[mat->n] == mat->max_size)
        return 2;

    for (j = mat->row[mat->n]; j > i; j--) {
        mat->val[j] = mat->val[j - 1];
        mat->col[j] = mat->col[j - 1];
    }

    mat->val[i] = val;
    mat->col[i] = col;

    for (j = row + 1; j < (mat->n + 1); j++)
        mat->row[j]++;

    return 0;
}

int get(Matrix *mat, int row, int col) {
    for (int i = mat->row[row]; i < mat->row[row + 1]; i++)
        if (mat->col[i] == col)
            return mat->val[i];
    return 0;
}

void print_matrix(Matrix *mat) {
    int i, j;
    for (i = 0; i < mat->n; i++) {
        for (j = 0; j < mat->m; j++)
            cout << get(mat, i, j) << " ";
        cout << endl;
    }
    cout << endl;
}

int getInt(string cap) {
    int in = 0;
    cout << cap << ": ";
    while ((scanf("%d", &in)) != 1) {
        cout << "Error";
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return in;
}

int getIntNoZero(string cap) {
    int in = 0;
    cout << cap << ": ";
    while ((scanf("%d", &in)) != 1 || in < 0) {
        cout << "Error";
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return in;
}

void init(Matrix *mat) {
    int row, col;
    int val;
    char c;
    do {
        row = getIntNoZero("row");
        col = getIntNoZero("column");
        val = getInt("value");
        cout << endl;

        switch (add(mat, row, col, val)) {
            case 1:
                printf("Over there of range\n");
                break;
            case 2:
                printf("Buffer overflow\n");
                break;
            default:
                print_matrix(mat);
                break;
        }

        do {
            cout << "Continue? (y/n)" << endl;
            c = getchar();
            if (c == 'y' || c == 'Y')
                break;
            if (c == 'n' || c == 'N')
                return;
            cout << "Error input" << endl;
            while (getchar() != '\n');
        } while (1);
    } while (1);
}

void my_bubble_sort(int *arr, int begin, int end, int flag)
{
    int temp;

    for (int i = begin; i < end; i++) {
        for (int j = begin; j < end - 1; j++) {
            if (flag == 1 && (arr[j] > arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            } else if (flag == 0 && (arr[j] < arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SortByMax(Matrix *mat) {
    int row;
    int max = 0, max_row = 0;
    for (row = 0; row < mat->n; row++) {
        int sum = 0;
        for (int i = mat->row[row]; i < mat->row[row + 1]; i++)
            sum += mat->val[i];
        if (max < sum) {
            max = sum;
            max_row = row;
        }
    }

    int i = mat->row[max_row];
    int j = mat->row[max_row + 1];
    my_bubble_sort(mat->col, i, j, 1);//up
    if ((mat->val)[i] > 0) {
        my_bubble_sort(mat->val, i, j, 1);//up
    } else {
        my_bubble_sort(mat->val, i, j, 0);//less
    }
}
