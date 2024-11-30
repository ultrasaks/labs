#include "funcs.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <cctype>


bool isPalindrome(const std::string word) {
    int n = word.size();
    for (int i = 0; i < n / 2; ++i) {
        if (word[i] != word[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int countSogls(const std::string& word) {
    int count = 0;
    for (char c : word) {
        if (Sogl(c)) {
            ++count;
        }
    }
    return count;
}

std::string removeGlas(const std::string& word) {
    std::string result;
    for (char c : word) {
        if (Sogl(c)) {
            result += c;
        }
    }
    return result;
}


std::vector<std::string> SplitWords(std::string text) {
    std::vector<std::string> words;
    std::string currentWord;
    for (char c : text) {
        if (std::isalpha(c)) {
            currentWord += c;
        } else if (!currentWord.empty()) {
            words.push_back(currentWord);
            currentWord.clear();
        }
    }
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }
    return words;
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::cin >> input;

    std::vector<std::string> words = SplitWords(input);

    bool hasPalindrome = false;
    for (int i = 0; i < words.size(); i++){
        if (words[i].size() > 1 && isPalindrome(words[i])) {
            hasPalindrome = true;
            break;
        }
    }

    if (hasPalindrome) {
        for (int i = 0; i < words.size(); i++){
            words[i] = removeGlas(words[i]);
        }
        std::sort(words.rbegin(), words.rend(), std::greater<>());
    } else {
        std::sort(words.begin(), words.end(), [](std::string a, std::string b) {
            return countSogls(a) > countSogls(b);
        });
    }

    for (int i = 0; i < words.size(); i++){
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
