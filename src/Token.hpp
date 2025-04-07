#ifndef H_MATH_EVALUATOR_TOKEN_HEADER_TOKEN_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_TOKEN_HEADER_TOKEN_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <cassert>
#include <map>
#include <string>
#include <variant>

class Token {
public:
    enum class Type {
        Base,
        Number,
        Add,
        Subtract,
        Multiply,
        Divide,
        Power,
        BracketLeft,
        BracketRight,
        Label,
    };

    static inline std::map<char, Type> singleCharToToken = {
        {'+', Type::Add},
        {'-', Type::Subtract},
        {'*', Type::Multiply},
        {'/', Type::Divide},
        {'^', Type::Power},
        {'(', Type::BracketLeft},
        {')', Type::BracketRight},
    };

    static inline std::map<Type, std::string> tokenToString = {
        {Type::Base, "Base"},
        {Type::Number, "Number"},
        {Type::Add, "Add"},
        {Type::Subtract, "Subtract"},
        {Type::Multiply, "Multiply"},
        {Type::Divide, "Divide"},
        {Type::Power, "Power"},
        {Type::BracketLeft, "Left Bracket"},
        {Type::BracketRight, "Right Bracket"},
        {Type::Label, "Label"},
    };

    static inline std::map<Type, int> precedence = {
        {Type::Base, 1},
        {Type::Add, 2},
        {Type::Subtract, 2},
        {Type::Multiply, 3},
        {Type::Divide, 3},
        {Type::Power, 4},
        {Type::Number, 5},
        {Type::Label, 5},
        {Type::BracketLeft, 6},
        {Type::BracketRight, 6},
    };

    Token(const Type type);
    Token(const int number);
    Token(const std::string& label);

    Type getType() const;

    void setType(Type type);

    int getNumber() const;

    const std::string& getLabel() const;

private:
    Type m_type = Type::Base;

    std::variant<int, std::string> m_value;
};

#endif
