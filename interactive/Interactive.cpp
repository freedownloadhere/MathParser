#include <iostream>
#include <string>

#include "MathEnv.hpp"
#include "Exception.hpp"

int main() {
	std::cout << "(Interactive Test)\n";
	std::cout << "Input an expression:\n";

	std::string input;
	getline(std::cin, input);

	MathEnv env;
	std::int64_t value = 0;

	try {
		value = env.evaluate(input);
	}
	catch(Exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 0;
	}

	std::cout << "Evaluated to: " << value << '\n';
	return 0;
}
