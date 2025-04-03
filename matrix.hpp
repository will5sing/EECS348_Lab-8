#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <string>

class Matrix {
public:
    Matrix(std::size_t N);  // Constructor to initialize NxN matrix with 0s
    Matrix(const std::vector<std::vector<int>>& nums);  // Constructor to initialize matrix from a 2D vector

    Matrix operator+(const Matrix &rhs) const; // Matrix addition
    Matrix operator*(const Matrix &rhs) const; // Matrix multiplication
    void set_value(std::size_t i, std::size_t j, int n); // Set value at position (i, j)
    int get_value(std::size_t i, std::size_t j) const; // Get value at position (i, j)
    int get_size() const; // Get matrix size (N)
    int sum_diagonal_major() const; // Sum of major diagonal
    int sum_diagonal_minor() const; // Sum of minor diagonal
    void swap_rows(std::size_t r1, std::size_t r2); // Swap rows
    void swap_cols(std::size_t c1, std::size_t c2); // Swap columns
    void print_matrix() const; // Print matrix
    bool loadFromFile(const std::string& filename, Matrix& mat1, Matrix& mat2);
private:
    size_t N;
    std :: vector<std::vector<int>> data;
};

#endif // __MATRIX_HPP__