#include <iostream>
#include <regex>

bool isPasswordValid(const std::string& password) {
	    if (password.size() < 8) {
	        return false;
	    }
	    std::regex upper_case("[A-Z]");
	    std::regex lower_case("[a-z]");
	    std::regex digit(R"(\d{2,})");
	    std::regex special_char("[^a-zA-Z0-9]");
	
	    if (std::regex_search(password, upper_case) &&
	        std::regex_search(password, lower_case) &&
	        std::regex_search(password, digit) &&
	        std::regex_search(password, special_char)){
	        return true;
	    }
	    return false;
	}
	
	int main(){
	    std::string password;
	    std::cout << "Prosze podac haslo: ";
	    std::cin >> password;
	    if (isPasswordValid(password)) {
	        std::cout << "Haslo spelnia wymogi bezpieczenstwa" << std::endl;
	    }
	    else {
	        std::cout << "Haslo nie spelnia wymogow bezpieczenstwa" << std::endl;
	    }
	}