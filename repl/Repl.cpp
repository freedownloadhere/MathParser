#include <iostream>
#include <string>

#include "MathEnv.hpp"
#include "Exception.hpp"

int main() {
	std::cout << "=== Math REPL ===\n";
	std::cout << "Input an expression:\n";

	MathEnv env;

	try {
		while (true) {
			std::cout << "> ";
			std::string input;
			std::int64_t value = 0;
			getline(std::cin, input);
			value = env.evaluate(input);
			std::cout << "Evaluated: " << value << '\n';
		}
	}
	catch(Exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 0;
	}

	return 0;
}
