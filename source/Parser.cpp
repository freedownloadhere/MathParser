// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Parser.hpp"
#include "Exception.hpp"

Parser::Parser(Lexer& lex, MemoryPool& variableMap, Allocator& allocator) {
    m_expr = allocator.allocate<Expression>();

    auto lastExpr = m_expr;

    while(!lex.reachedEnd()) {
        auto currToken = lex.nextToken();
        auto currExpr = allocator.allocate<Expression>(currToken);

        const int currExprPrec = currExpr->getPrecedence();
        const int lastExprPrec = lastExpr->getPrecedence();

        if (currToken.getType() == &Token::Type::Label) {
            const std::string& label = *currToken.getLabel();
            variableMap.storeVariable(label);
        }

        if(currToken.getType() == &Token::Type::BracketRight) {
            while(
                lastExpr->getParent() != nullptr &&
                lastExpr->getType() != &Token::Type::BracketLeft
            ) {
                lastExpr = lastExpr->getParent();
            }

            if (lastExpr->getType() != &Token::Type::BracketLeft || lastExpr->getParent() == nullptr)
                throw Exception("Right bracket is missing its left bracket");

            lastExpr->setType(&Token::Type::BracketRight);

            continue;
        }

        if(lastExpr->getType() == &Token::Type::BracketLeft || currExprPrec > lastExprPrec) {
            lastExpr->setNext(currExpr);
            lastExpr = currExpr;
            continue;
        }

        while(
            lastExpr->getParent() != nullptr &&
            lastExpr->getParent()->getType() != &Token::Type::BracketLeft &&
            currExprPrec <= lastExpr->getParent()->getPrecedence()
        ) {
            lastExpr = lastExpr->getParent();
        }

        auto parent = lastExpr->getParent();

        if(parent != nullptr) {
            parent->removeChild(lastExpr);
            parent->setNext(currExpr);
        }

        currExpr->setNext(lastExpr);

        lastExpr = currExpr;
    }
}

Expression* Parser::getExpression() const {
    return m_expr;
}
