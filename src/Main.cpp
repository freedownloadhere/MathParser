#include <iostream>
#include <string>

#include "MathParser.hpp"
#include "SyntaxException.hpp"
#include "LogicException.hpp"

int main() {
    std::string input;
    std::cout << "input le epic expression\n";

    getline(std::cin, input);

    std::cout << "this is what ur expression evaluated to bruh\n";

    try {
        std::cout << MathParser::evaluate(input) << '\n';
    }
    catch(SyntaxException& e) {
        std::cerr << "Syntax Exception: " << e.what() << '\n';
    }
    catch(LogicException& e) {
        std::cerr << "Logic Exception: " << e.what() << '\n';
    }

    return 0;
}
