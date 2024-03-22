#include <iostream>
#include <regex>

bool isEmailValid(const std::string& email) {

	std::regex email_regex(
		R"(^[a-zA-Z0-9._]+@[a-zA-Z.-]+\.[a-zA-Z]{2,3}$)"
	);

	return std::regex_match(email, email_regex);
}
int main() {
	std::string email;
	std::cout << "Prosze podac adres e-mail: ";
	std::cin >> email;
	if (isEmailValid(email)) {
		std::cout << "Poprawny adres e-mail." << std::endl;
	}
	else {
		std::cout << "Niepoprawny adres e-mail." << std::endl;
	}
	return 0;
}
