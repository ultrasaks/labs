#include "funcs.hpp"
#include <iostream>
#include <algorithm>

void Read(int** matrix, short n) {
    std::cout << "nums:" << std::endl;
    for (short i = 0; i<n; i++) {
        std::cout << i << " line: " << std::endl;
        for (short j = 0; j<n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

int dig_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int elems_sum(int* matrix, short n){
    int sum;
    for (short i = 0; i<n; i++) {
        sum += matrix[i];
    }
    return sum;
}

bool Equals(int** matrix, short n) {
    int min = INT32_MAX;
    int max = INT32_MIN;
    for (short i = 0; i<n; i++) {
        std::cout << i << " line: " << std::endl;
        for (short j = 0; j<n; j++) {
            if (matrix[i][j] > max){max=matrix[i][j];}
            if (matrix[i][j] < min){min=matrix[i][j];}
        }
    }
    if (dig_sum(max) == dig_sum(min)){
        return true;
    }
    return false;
}

void Replacer(int** matrix, short n) {
    int row_sums[n];
    int row_indexes[n];
    
    for (short i = 0; i<n; i++) {
        row_sums[i] = elems_sum(matrix[i], n);
        row_indexes[i] = i;
    }

    for (short i = 0; i<n-1; i++) {
        for (short j = 0; j<n-i-1; j++) {
            if (row_sums[j] > row_sums[j + 1]) {
                std::swap(row_sums[j], row_sums[j + 1]);
                std::swap(row_indexes[j], row_indexes[j + 1]);
            }
        }
    }

    int temp_matrix[n][n];
    for (short i = 0; i<n; i++) {
        for (short j = 0; j<n; j++) {
            temp_matrix[i][j] = matrix[row_indexes[i]][j];
        }
    }
    for (short i = 0; i<n; i++) {
        for (short j = 0; j<n; j++) {
            matrix[i][j] = temp_matrix[i][j];
        }
    }
}

void Writer(int** matrix, short n) {
    for (short i = 0; i<n; i++) {
        std::cout << std::endl;
        for (short j = 0; j<n; j++) {
            std::cout << matrix[i][j] << " ";
        }
    }
}