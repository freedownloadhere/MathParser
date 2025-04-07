#include <iostream>
#include <string>

#include "MathParser.hpp"
#include "Exception.hpp"

int main() {
    std::string input;
    std::cout << "input le epic expression\n";

    getline(std::cin, input);

    std::cout << "this is what ur expression evaluated to bruh\n";

    try {
        std::cout << MathParser::evaluate(input) << '\n';
    }
    catch(Exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
