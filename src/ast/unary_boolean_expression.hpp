#ifndef KOMPIS_AST_UNARY_BOOLEAN_EXPRESSION_HPP
#define KOMPIS_AST_UNARY_BOOLEAN_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class UnaryBooleanExpression : public Expression
    {
      public:
        enum Operation
        {
          BOOLEAN_NEG,
        };

        UnaryBooleanExpression(Operation op,
                               Expression *expr,
                               int line_num = 0)
          : Expression(line_num),
            _op(op),
            _expr(expr) {}

        VisitorData *accept(Visitor *visitor);
        const char *op_str();

        Operation _op;
        Expression *_expr;
    };
  }
}

#endif
