#include "Token.hpp"

Token::Token(const Type type) : m_type(type) { }
Token::Token(const std::int64_t number) : m_type(Type::Number) {
    m_as.m_rvalue = new RValue(number);
}
Token::Token(const std::string& label) : m_type(Type::Label) {
    m_as.m_label = new std::string(label);
}

Token::Type Token::getType() const {
    return m_type;
}

void Token::setType(Type type) {
    m_type = type;
}

RValue* Token::getRValue() const {
    assert(m_type == Type::Number);
    return m_as.m_rvalue;
}

std::string* Token::getLabel() const {
    assert(m_type == Type::Label);
    return m_as.m_label;
}
