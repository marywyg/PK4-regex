#include <iostream>
#include<fstream>
#include <regex>
#include <set>

int main() {
    std::ifstream file("LOREM-IPSUM.txt");
    std::string line;
    std::regex word_regex(R"(\b[a][A-Za-z]{3,}[mtbr]\b)");
    std::set<std::string> unique_words;

    while (std::getline(file, line)) {
        std::sregex_iterator words_begin(line.begin(), line.end(), word_regex);
        std::sregex_iterator words_end;
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            unique_words.insert(i->str());
        }
    }

    for (const auto& word : unique_words) {
        std::cout << word << std::endl;
    }

    return 0;
}