// вариант 7
#include <iostream>

int main(){
    short prog;
    int n;
    int summ = 0;
    
    std::cout << "prog >> ";
    std::cin >> prog;
    std::cout << "n >> ";
    std::cin >> n;
    
    if (prog == 1){
        bool first = true;
        int minnum = 0;
        int minnum_index = 0;
        int curnum;

        
        for (int i = 0; i < n; i++) {
            std::cout << "num >> ";
            std::cin >> curnum;
            if (curnum % 3 == 0 || curnum % 7 == 0){
                summ += curnum;
                if (first || (curnum < minnum)) {
                    first = false;
                    minnum = curnum;
                    minnum_index = i;
                }
            }
        }
        std::cout << "сумма: " << summ << std::endl << "наименьшее: " << minnum << std::endl 
                  << "под номером " << minnum_index+1 << std::endl;

    }else if (prog == 2){
        short otsech;
        while (n > 0){
            otsech = n % 10;
            n = n / 10;
            if (otsech % 2 == 0){
                summ += otsech;
            }
        }
        std::cout << "Сумма четных: " << summ <<std::endl;
    }

    return 0;
}