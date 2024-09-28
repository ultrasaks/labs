// вариант 7

#include <iostream>
#include <cmath>

int main(){
    unsigned short a, b, c;
    float answer;
    std::cout << "Сторона A:" << std::endl;
    std::cin >> a;
    std::cout << "Сторона B:" << std::endl;
    std::cin >> b;
    std::cout << "Сторона C:" << std::endl;
    std::cin >> c;
    answer = sqrt((1.0*a*a) + (b*b) + (c*c));
    std::cout << "Главная диагональ - " << answer;

    return 0;
}