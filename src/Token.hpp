#ifndef H_MATH_EVALUATOR_TOKEN_HEADER_TOKEN_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_TOKEN_HEADER_TOKEN_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <map>
#include <string>

class Token {
public:
    enum class Type {
        Base,
        Invalid,
        Number,
        Add,
        Subtract,
        Multiply,
        Divide,
        Power,
        BracketLeft,
        BracketRight,
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
        {Type::Invalid, "Invalid"},
        {Type::Number, "Number"},
        {Type::Add, "Add"},
        {Type::Subtract, "Subtract"},
        {Type::Multiply, "Multiply"},
        {Type::Divide, "Divide"},
        {Type::Power, "Power"},
        {Type::BracketLeft, "Left Bracket"},
        {Type::BracketRight, "Right Bracket"},
    };

    static inline std::map<Type, int> precedence = {
        {Type::Base, 1},
        {Type::Add, 2},
        {Type::Subtract, 2},
        {Type::Multiply, 3},
        {Type::Divide, 3},
        {Type::Power, 4},
        {Type::Number, 5},
        {Type::BracketLeft, 6},
    };

    Token(const Type type) : m_type(type) { }
    Token(const int value) : m_type(Type::Number), m_value(value) { }

    Type getType() const {
        return m_type;
    }

    int getValue() const {
        return m_value;
    }

private:
    Type m_type = Type::Base;
    int m_value = 0;
};

#endif
