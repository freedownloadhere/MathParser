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

	try {
		std::cout << "Evaluated to: " << env.evaluate(input) << '\n';
	}
	catch(Exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}
