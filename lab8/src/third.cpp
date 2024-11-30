#include "funcs.hpp"

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>


std::vector<char> findUniqueVowels(std::string word) {
    std::vector<char> vowels;
    for (char c : word) {
        if (!Sogl(c) && std::find(vowels.begin(), vowels.end(), std::tolower(c)) == vowels.end()) {
            vowels.push_back(std::tolower(c));
        }
    }
    return vowels;
}

std::string processWord(std::string word) {
    std::vector<char> vowels = findUniqueVowels(word);

    if (vowels.size() >= 4) {
        std::string result = word;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        result += " (";
        for (size_t i = 0; i < vowels.size(); ++i) {
            result += vowels[i];
            if (i != vowels.size() - 1) result += ",";
        }
        result += ")";
        return result;
    }
    return word;
}

int main() {
    std::ifstream inputFile("english.txt");
    std::ofstream outputFile("out.txt");

    std::string word;
    std::string outResult;

    while (inputFile >> word) {
        std::string processedWord = processWord(word);
        outResult += processedWord;

        char nextChar = inputFile.peek();
        while (isLetter(nextChar)) {
            outResult += nextChar;
            inputFile.get();
            nextChar = inputFile.peek();
        }
        outResult += " ";
    }

    outputFile << outResult;

    inputFile.close();
    outputFile.close();

    return 0;
}
