// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Token.hpp"

const Token::Type Token::Type::Base{ "Base", 1 };
const Token::Type Token::Type::Equals{ "Equals", 2, '=' };
const Token::Type Token::Type::Add{ "Add", 3, '+' };
const Token::Type Token::Type::Subtract{ "Subtract", 3, '-' };
const Token::Type Token::Type::Multiply{ "Multiply", 4, '*' };
const Token::Type Token::Type::Divide{ "Divide", 4, '/' };
const Token::Type Token::Type::Power{ "Power", 5, '^' };
const Token::Type Token::Type::Number{ "Number", 6};
const Token::Type Token::Type::Label{ "Label", 6 };
const Token::Type Token::Type::BracketLeft{ "Open Bracket", 7, '(' };
const Token::Type Token::Type::BracketRight{ "Closed Bracket", 7, ')' };

Token::Token(const Type* type) : m_type(type) { }
Token::Token(const std::int64_t number) : m_type(&Type::Number) {
    m_as.m_rvalue = new RValue(number);
}
Token::Token(const std::string& label) : m_type(&Type::Label) {
    m_as.m_label = new std::string(label);
}

const Token::Type* Token::getType() const {
    return m_type;
}

void Token::setType(const Type* type) {
    m_type = type;
}

RValue* Token::getRValue() const {
    assert(m_type == &Type::Number);
    return m_as.m_rvalue;
}

std::string* Token::getLabel() const {
    assert(m_type == &Type::Label);
    return m_as.m_label;
}

const Token::Type* Token::Type::getFromChar(char c) {
    if (m_singleCharToToken.count(c) == 0)
        return nullptr;
    return m_singleCharToToken.at(c);
}

std::int32_t Token::Type::getID() const {
    return m_id;
}

std::string_view Token::Type::getName() const {
    return m_name;
}

std::int32_t Token::Type::getPrecedence() const {
    return m_precedence;
}

Token::Type::Type(std::string_view name, std::int32_t precedence, char charMapping) 
    : m_name(name), m_precedence(precedence)
{
    static int lastID = 0;
    m_id = lastID++;
    if (charMapping == 0) return;
    assert(m_singleCharToToken.count(charMapping) == 0);
    m_singleCharToToken.try_emplace(charMapping, this);
}
