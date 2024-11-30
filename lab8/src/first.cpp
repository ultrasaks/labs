// вариант 7
#include "funcs.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


bool hasUniqueSogls(const std::string &word) {
    bool seen[26] = {false};

    for (size_t i = 0; i < word.size(); ++i) {
        if (Sogl(word[i])) {
            int index = Lower(word[i]) - 'a';
            if (seen[index]) {
                return false;
            }
            seen[index] = true;
        }
    }
    return true;
}

bool inList(std::vector<std::string> words, std::string word) {
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == word) {
            return false;
        }
    }
    return true;
}


int main() {
    std::ifstream inputFile("english.txt");
    std::ofstream outputFile("out.txt");

    std::vector<std::string> validWords;
    std::string word;

    while (inputFile >> word) {
        if (inList(validWords, word) && hasUniqueSogls(word)) {
            validWords.push_back(cleanWord(word));
        }
    }

    std::sort(validWords.begin(), validWords.end(), [](std::string a, std::string b) {
        return a.size() > b.size() || (a.size() == b.size() && a < b);
    });

    int size = validWords.size();
    if (size > 2000) {
        size = 2000;
    }

    for (size_t i = 0; i < validWords.size(); ++i) {
        outputFile << validWords[i] << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
