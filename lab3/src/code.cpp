// вариант 7

#include <iostream>

int main(){
    int i, x;
    
    std::cout << "i>> ";
    std::cin >> i;
    std::cout << "x>>";
    std::cin >> x;
    
    x |= (1 << i);

    std::cout << "К сожалению, это число превратилось в " << x << std::endl;
    return 0;
}