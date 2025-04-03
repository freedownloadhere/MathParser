#include <iostream>
#include <fstream>
#include <string>

#include "../src/MathParser.hpp"

int main() {
    std::ifstream testInput("tests.txt");
    std::ofstream testResults("testsResult.txt");
    std::string input;

    while(getline(testInput, input)) {
        auto output = MathParser::evaluate(input);
        testResults << output << '\n';
    }

    return 0;
}
