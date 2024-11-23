// вариант 7
#include "funcs.hpp"
#include <iostream>


int main(){
    unsigned short n;
    std::cout << "n >> ";
    std::cin >> n;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }


    Read(matrix, n);
    if (Equals(matrix, n)){
        Replacer(matrix, n);
    }
    Writer(matrix, n);

    
    return 0;
}