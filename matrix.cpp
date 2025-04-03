#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) : N(N),data(N, vector<int>(N, 0)) {} // initialize an empty NxN matrix
Matrix::Matrix(const vector<vector<int>>& values) :N(values.size()), data(values) {}

bool Matrix ::loadFromfile(const string& filename, Matrix& mat1 , Matrix& mat2){
    ifstream file(filename);
    if (!file) {
        cerr << "No file found" << filename << endl;
        return false;
    }
    size_t size;
    file >>size;
    if (size <= 0) {
        cerr << "Invalid Matrix" << size << endl;
        return false;
    }
    vector<vector<int>> values1(size, vector<int>(size));
    vector<vector<int>> values2(size, vector<int>(size));

    for(size_t i=0; i < size; ++i)
        for(size_t j=0; j<size; ++j)
            file >> values1[i][j];

    for(size_t i=0; i < size; ++i)
        for(size_t j=0; j<size; ++j)
            file >> values2[i][j];
    mat1 = Matrix(values1);
    mat2 = Matrix(values2);
    return true;
}

void Matrix::print_matrix() const { // print out the matrix
    for(size_t i=0; i < N; ++i){
        for(size_t j=0; j<N; ++j){
            cout <<setw(4) << data[i][j];
        }
        cout << endl;
    }
}
Matrix Matrix::operator+(const Matrix& other) const{
    vector<vector<int>> result(N, vector<int>(N));
    for(size_t i=0; i < N; ++i)
        for(size_t j=0; j<N; ++j)
            result[i][j] = data[i][j] + other.data[i][j];
    return Matrix(result);
}

Matrix Matrix::operator*(const Matrix& other) const{
    vector<vector<int>> result(N, vector<int>(N));
    for(size_t i=0; i < N; ++i)
        for(size_t j=0; j<N; ++j)
            result[i][j] = data[i][j] * other.data[i][j];
    return Matrix(result);
}
