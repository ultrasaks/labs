// вариант 7

#include <iostream>


int main() {
    int num;
    std::cout << "Число >> ";
    std::cin >> num;

    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&num);
    
    for (size_t i = 0; i < sizeof(num); ++i){
        std::cout << "Байт " << i << ": 0x" 
                  << std::hex << static_cast<int>(bytePtr[i]) << std::endl;
    }



    return 0;
}
