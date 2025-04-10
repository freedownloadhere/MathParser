#include "Parser.hpp"

#include "Exception.hpp"

Parser::Parser(Lexer& lex) {
    m_expr = new Expression();

    auto lastExpr = m_expr;

    while(!lex.reachedEnd()) {
        auto currToken = lex.nextToken();
        auto currExpr = new Expression(currToken);

        const int currExprPrec = currExpr->getPrecedence();
        const int lastExprPrec = lastExpr->getPrecedence();

        if(currToken.getType() == Token::Type::BracketRight) {
            while(
                lastExpr->getParent() != nullptr &&
                lastExpr->getToken().getType() != Token::Type::BracketLeft
            ) {
                lastExpr = lastExpr->getParent();
            }

            if(lastExpr->getType() != Token::Type::BracketLeft || lastExpr->getParent() == nullptr)
                throw Exception("Right bracket is missing its left bracket");

            lastExpr->setType(Token::Type::BracketRight);

            continue;
        }

        if(lastExpr->getType() == Token::Type::BracketLeft || currExprPrec > lastExprPrec) {
            lastExpr->setNext(currExpr);
            lastExpr = currExpr;
            continue;
        }

        while(
            lastExpr->getParent()->getType() != Token::Type::BracketLeft &&
            lastExpr->getParent() != nullptr &&
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
