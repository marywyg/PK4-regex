#include<iostream>
#include<fstream>
#include <regex>


int main() {
    std::ifstream file("PAN-TADEUSZ.txt");
    std::string line;
    std::regex soplica_regex(R"(Soplica\b)");
    std::regex zosia_regex(R"(\bZosia\b)");
    int soplica_count = 0;
    int zosia_count = 0;
    std::string zosia_line;
    std::cout << "Linie ze slowem Soplica: " << std::endl;
    while (std::getline(file, line)) {

        if (std::regex_search(line, soplica_regex)) {
            soplica_count++;
            if (soplica_count <= 20) {
                std::cout << "[" << soplica_count << "] " << line << std::endl;
            }
        }
        std::sregex_iterator zosia_begin(line.begin(), line.end(), zosia_regex);
        std::sregex_iterator zosia_end;
        for (std::sregex_iterator i = zosia_begin; i != zosia_end; ++i) {
            zosia_count++;
            if (zosia_count == 23) {
                zosia_line = line;
                break;
            }
        }
    }
    if (!zosia_line.empty()) {
        std::cout << "Linia z 23-cim wystapieniem slowa Zosia: " << zosia_line << std::endl;
    }

    return 0;
}
