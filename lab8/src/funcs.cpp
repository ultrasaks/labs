#include <string>

char Lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool Sogl(char c) {
    c = Lower(c);
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

std::string cleanWord(std::string word) {
    std::string result;
    for (size_t i = 0; i < word.size(); ++i) {
        if (isLetter(word[i])) {
            result += word[i];
        }
    }
    return result;
}
