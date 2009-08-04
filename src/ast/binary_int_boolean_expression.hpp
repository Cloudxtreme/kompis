#ifndef KOMPIS_AST_BINARY_INT_BOOLEAN_EXPRESSION_HPP
#define KOMPIS_AST_BINARY_INT_BOOLEAN_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class BinaryIntBooleanExpression : public Expression
    {
      public:
        enum Operation
        {
          EQ,
          NE,
          LT,
          LE,
          GT,
          GE,
        };

        BinaryIntBooleanExpression(Operation op,
                                   Expression *left,
                                   Expression *right,
                                   int line_num = 0)
          : Expression(line_num),
            _op(op),
            _left(left),
            _right(right) {}

        VisitorData *accept(Visitor *visitor);
        const char *op_str();

        Operation _op;
        Expression *_left, *_right;
    };
  }
}

#endif
