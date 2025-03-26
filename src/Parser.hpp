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
            auto token = lex.nextToken();
            auto currExpr = new Expression(token);

            int currExprPrec = currExpr->getPrecedence();

            if(
                currExprPrec > lastExpr->getPrecedence() ||
                token.getType() == Token::Type::BracketLeft
            ) {
                lastExpr->setNext(currExpr);
                lastExpr = currExpr;
                continue;
            }

            if(token.getType() == Token::Type::BracketRight) {
                while(
                    lastExpr->getParent() != nullptr &&
                    lastExpr->getToken().getType() != Token::Type::BracketLeft
                ) {
                    lastExpr = lastExpr->getParent();
                }

                assert(lastExpr->getParent() != nullptr);
                assert(lastExpr->getToken().getType() == Token::Type::BracketLeft);

                auto subExpr = lastExpr->getUnary();
                auto superExpr = lastExpr->getParent();
                lastExpr->removeChild(subExpr);
                superExpr->removeChild(lastExpr);
                superExpr->setNext(subExpr);

                lastExpr = subExpr;
                continue;
            }

            while(
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
