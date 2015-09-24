//
// Created by jerome on 10/09/15.
//

#include <iostream>
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(int row, int col) {
    matrix = new T *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new T[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = i * col + j;
        }
    }

    size_row = row;
    size_col = col;
}

template<typename T>
Matrix<T> *Matrix<T>::product(const Matrix<T> *a, const Matrix<T> *b) {
    if (a->size_col != b->size_row) {
        throw 1;
    }

    int final_size = a->size_col;

    Matrix<T> *result = new Matrix(final_size, final_size);

    for (int row = 0; row < a->size_row; row++) {
        for (int col = 0; col < b->size_col; col++) {
            for (int inner = 0; inner < final_size; inner++) {
                result->set(row, col, result->get(row, col) + a->get(row, inner) * b->get(inner, col));
            }
        }
    }
    return result;
}


template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    matrix[row][col] = value;
}

template<typename T>
T Matrix<T>::get(int row, int col) const {
    return matrix[row][col];
}


template<typename T>
void Matrix<T>::print() {
    for (int i = 0; i < size_row; i++) {
        for (int j = 0; j < size_col; j++) {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << std::endl;
    }
}

template<typename T>
Matrix<T> *Matrix<T>::operator*(const Matrix<T> &b) {
    return product(this, &b);
}

template<typename T>
unsigned int Matrix<T>::getRow() const {
    return size_row;
}

template<typename T>
unsigned int Matrix<T>::getCol() const {
    return size_col;
}

template
class Matrix<int>;

template
class Matrix<long>;

template
class Matrix<unsigned long>;

template
class Matrix<unsigned long long>;
