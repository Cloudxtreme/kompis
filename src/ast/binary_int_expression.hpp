#ifndef KOMPIS_AST_BINARY_INT_EXPRESSION_HPP
#define KOMPIS_AST_BINARY_INT_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class BinaryIntExpression : public Expression
    {
      public:
        enum Operation
        {
          ADD,
          SUB,
          MUL,
          DIV,
        };

        BinaryIntExpression(Operation op,
                            Expression *lhs,
                            Expression *rhs,
                            int line_num = 0)
          : Expression(line_num),
            _op(op),
            _lhs(lhs),
            _rhs(rhs) {}

        VisitorData *accept(Visitor *visitor);
        const char *op_str();

        Operation _op;
        Expression *_lhs, *_rhs;
    };
  }
}

#endif
