#pragma once

#include <cassert>
#include <map>
#include <string>
#include <string_view>
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
        Equals,
    };

    static inline std::map<char, Type> singleCharToToken = {
        {'+', Type::Add},
        {'-', Type::Subtract},
        {'*', Type::Multiply},
        {'/', Type::Divide},
        {'^', Type::Power},
        {'(', Type::BracketLeft},
        {')', Type::BracketRight},
        {'=', Type::Equals},
    };

    static inline std::map<Type, std::string_view> tokenToString = {
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
        {Type::Equals, "Equals"},
    };

    static inline std::map<Type, int> precedence = {
        {Type::Base, 1},
        {Type::Equals, 2},
        {Type::Add, 3},
        {Type::Subtract, 3},
        {Type::Multiply, 4},
        {Type::Divide, 4},
        {Type::Power, 5},
        {Type::Number, 6},
        {Type::Label, 6},
        {Type::BracketLeft, 7},
        {Type::BracketRight, 7},
    };

    Token(const Type type);
    Token(const std::int64_t number);
    Token(const std::string& label);

    Type getType() const;

    void setType(Type type);

    int getNumber() const;

    std::string_view getLabel() const;

private:
    Type m_type = Type::Base;

    std::variant<std::int64_t, std::string> m_value;
};