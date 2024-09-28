// вариант 7

#include <iostream>
#include <cmath>

int main(){
    short a, b, c;
    double answer;
    std::cout << "Сторона A:" << std::endl;
    std::cin >> a;
    std::cout << "Сторона B:" << std::endl;
    std::cin >> b;
    std::cout << "Сторона C:" << std::endl;
    std::cin >> c;
    answer = sqrt((a*a) + (b*b) + (c*c));
    std::cout << "Главная диагональ - " << answer;

    return 0;
}