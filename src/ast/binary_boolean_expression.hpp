#ifndef KOMPIS_AST_BINARY_BOOLEAN_EXPRESSION_HPP
#define KOMPIS_AST_BINARY_BOOLEAN_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class BinaryBooleanExpression : public Expression
    {
      public:
        enum Operation
        {
          BOOLEAN_AND,
          BOOLEAN_OR,
          BOOLEAN_XOR,
        };

        BinaryBooleanExpression(Operation op,
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
