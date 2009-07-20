#ifndef KOMPIS_AST_NEGATION_EXPRESSION_HPP
#define KOMPIS_AST_NEGATION_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class NegationExpression : public Expression
    {
      public:
        NegationExpression(Expression &expr) : _expr(expr) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_expr;
    };
  }
}

#endif