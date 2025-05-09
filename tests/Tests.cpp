// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Pch.hpp"

#include "MathEnv.hpp"
#include "Exception.hpp"

int main() {
	std::ifstream testInput("../../../tests/tests.txt");

	MathEnv env;

	int passed = 0, failed = 0;
	while(testInput.good()) {
		int expected;
		std::string toEvaluate;

		testInput >> expected;
		getline(testInput, toEvaluate);

		std::int64_t value = 0;

		try {
			value = env.evaluate(toEvaluate);
		}
		catch (Exception& e) {
			std::cerr << e.what() << '\n';
			failed++;
			continue;
		}

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
