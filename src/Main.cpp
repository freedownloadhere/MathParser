#include <iostream>
#include <string>

#include "MathParser.hpp"

int main() {
    std::string input;
    std::cout << "input le epic expression\n";

    getline(std::cin, input);

    auto lexer = MathParser::lex(input);
    lexer.print();

    //std::cout << "this is what ur expression evaluated to bruh\n";
    //std::cout << MathParser::evaluate(input) << '\n';

    return 0;
}
