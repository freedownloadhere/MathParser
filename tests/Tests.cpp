#include <iostream>
#include <fstream>
#include <string>

#include "MathEnv.hpp"

int main() {
	std::ifstream testInput("tests.txt");

	MathEnv env;

	int passed = 0, failed = 0;
	while(testInput.good()) {
		int expected;
		std::string toEvaluate;

		testInput >> expected;
		getline(testInput, toEvaluate);

		int value = env.evaluate(toEvaluate);

		if (value != expected) {
			failed++;
			std::cout << "===========\n";
			std::cout << "FAILED: " << toEvaluate << '\n';
			std::cout << "Expected: " << expected << '\n';
			std::cout << "Value: " << value << '\n';
			std::cout << "===========\n";
			continue;
		}

		passed++;
	}

	std::cout << "FINAL RESULTS:\n";
	std::cout << "Passed " << passed << ", Failed " << failed << '\n';

	return 0;
}
