#ifndef H_MATH_EVALUATOR_PARSER_HEADER_PARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_PARSER_HEADER_PARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include "Expression.hpp"
#include "Lexer.hpp"

class Parser {
public:
    Parser(Lexer& lex) {
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

                assert(lastExpr->getType() == Token::Type::BracketLeft);
                assert(lastExpr->getParent() != nullptr);

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

    const Expression* getExpression() {
        return m_expr;
    }

private:
    Expression* m_expr;
};

#endif
