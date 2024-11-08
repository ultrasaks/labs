// вариант 7
#include <iostream>
#include <algorithm>
#include <vector> 


bool notsame_digit(int num) {
    int last = num % 10;
    while (num > 0) {
        int cur = num % 10;
        if (cur != last) {
            return true;
        }
        num /= 10;
    }
    return false;
}

bool palindrome(int num) {
    int reversed = 0;
    int original = num;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}


int dig_sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int max_digit(int num) {
    short max_digit = 0;
    short cur;
    while (num > 0) {
        cur = num % 10;
        if (cur > max_digit){
            max_digit = cur;
        }
        num /= 10;
    }
    return max_digit;
}

bool comparison_second(int a, int b) {
    int sum_a = dig_sum(a);
    int sum_b = dig_sum(b);

    if (sum_a != sum_b) 
        return sum_a < sum_b;
    
    int max_a = max_digit(a);
    int max_b = max_digit(b);
    if (max_a != max_b)
        return max_a < max_b;
    
    return a < b;
}

int main(){
    short prog;

    std::cout << "prog >> ";
    std::cin >> prog;

    switch (prog)
    {
    case 1:
        {
            unsigned short n;
            bool need = true;

            std::cout << "size >> ";
            std::cin >> n;
            int* arr = new int[n];

            std::cout << "nums:" << std::endl;
            for (short i = 0; i<n; i++) {
                std::cin >> arr[i];
                if (notsame_digit(arr[i]) && need) {
                    need = false;
                }
            }
            if (need){
                std::sort(arr, arr + n, std::greater<int>());
            }
            for (short i = 0; i<n; i++) {
                std::cout << arr[i] << " ";
            }
            break;}

    case 2:{
        unsigned short n;
        std::cout << "size >> ";
        std::cin >> n;
        int* arr = new int[n];

        std::cout << "nums:" << std::endl;
        for (short i = 0; i<n; i++) {
            std::cin >> arr[i];
        }

        std::sort(arr, arr + n, comparison_second);
        for (short i = 0; i<n; i++) {
            std::cout << arr[i] << " ";
        }

        break;}
    case 3:{
        unsigned short n;
        unsigned short m;
        std::cout << "n >> ";
        std::cin >> n;
        std::cout << "m >> ";
        std::cin >> m;

        int matrix[n][m];

        short max_row = 0;
        int max_row_sum = -1;
        bool no_sum = true;
        int cur_sum;

        std::cout << "nums:" << std::endl;
        for (short i = 0; i<n; i++) {
            cur_sum = 0;
            std::cout << i << " row:" << std::endl;
            for (short j = 0; j<m; j++) {
                std::cin >> matrix[i][j];
                cur_sum += matrix[i][j];
                }
            if (no_sum || cur_sum > max_row) {
                max_row = i;
                max_row_sum = cur_sum;
            }
        }
        for (short i = 0; i<m; i++) {
            matrix[max_row][i] += 1;
        }
        for (short i = 0; i<n; i++) {
            for (short j = 0; j<m; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }



        break;}
    case 4:{
        unsigned short n;
        std::cout << "how many >> ";
        std::cin >> n;
        std::vector<int> arr;
        int num;

        std::cout << "nums:" << std::endl;
        for (short i = 0; i<n; i++) {
            std::cin >> num;

            if (dig_sum(num) != 10){
                arr.push_back(num);
                if (palindrome(num)){
                    arr.push_back(num);
                }
            }
        }

        for (int i: arr) {
            std::cout << i << " ";
        }
        

        break;}
    default:
        std::cout << "нет такого";
    }
    return 0;
}