#ifndef KOMPIS_AST_NEGATION_EXPRESSION_HPP
#define KOMPIS_AST_NEGATION_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class NegationExpression : public Expression
    {
      public:
        NegationExpression(Expression *expr,
                           int line_num = 0)
          : Expression(line_num),
            _expr(expr) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Expression *_expr;
    };
  }
}

#endif
