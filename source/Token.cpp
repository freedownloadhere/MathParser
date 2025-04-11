#include "Token.hpp"

Token::Token(const Type type) : m_type(type) { }
Token::Token(const std::int64_t number) : m_type(Type::Number) {
    m_value = number;
}
Token::Token(const std::string& label) : m_type(Type::Label) {
    m_value = label;
}

Token::Type Token::getType() const {
    return m_type;
}

void Token::setType(Type type) {
    m_type = type;
}

std::int64_t Token::getNumber() const {
    assert(m_type == Type::Number);
    return std::get<std::int64_t>(m_value);
}

const std::string& Token::getLabel() const {
    assert(m_type == Type::Label);
    return std::get<std::string>(m_value);
}
