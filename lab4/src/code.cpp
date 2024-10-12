// вариант 7

#include <iostream>

int main(){
    short prog;
    std::cout << "prog >> ";
    std::cin >> prog;
    if (prog == 1) {
        int a, b, c;
        std::cout << "a >> ";
        std::cin >> a;
        std::cout << "b >> ";
        std::cin >> b;
        std::cout << "c >> ";
        std::cin >> c;
        if (a % b == 0 && b > c) {
            std::cout << (1.0*a/b)+c;
        }else if (a % b == 0 && b < c) {
            std::cout << (1.0*a/b)-c;
        }else{
            std::cout << (a+b)*c;
        }}
    else if (prog == 2) {
        unsigned short n;
        std::string day;
        std::cout << "n >> ";
        std::cin >> n;
        switch (n) {
            case 1: day = "Понедельник"; break;
            case 2: day = "Вторник"; break;
            case 3: day = "Среда"; break;
            case 4: day = "Четверг"; break;
            case 5: day = "Пятница"; break;
            case 6: day = "Суббота"; break;
            case 7: day = "Воскресенье"; break;
            default: day = "Такого дня нет";
        }
        std::cout << day;
    }else if (prog == 3) {
        short x;
        std::cout << "x >> ";
        std::cin >> x;
        if (x == -1) {
            std::cout << "Negative number";
        }else if (x == 1) {
            std::cout << "Positive number";
        }else{
            std::cout << "Увы и ах";
        }
    }
    return 0;
}