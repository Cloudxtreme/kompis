#ifndef KOMPIS_AST_BINARY_INT_EXPRESSION_HPP
#define KOMPIS_AST_BINARY_INT_EXPRESSION_HPP

#include <string>
#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    namespace binop
    {
      enum BinaryOperation
      {
        ADD,
        SUB,
        MUL,
        DIV,
      };

      const char *str(BinaryOperation b);
    }

    class Visitor;
    class VisitorData;

    class BinaryIntExpression : public Expression
    {
      public:
        BinaryIntExpression(binop::BinaryOperation op,
                            Expression *lhs,
                            Expression *rhs,
                            int line_num = 0)
          : Expression(line_num),
            _op(op),
            _lhs(lhs),
            _rhs(rhs) {}

        VisitorData *accept(Visitor *visitor);

        binop::BinaryOperation _op;
        Expression *_lhs, *_rhs;
    };
  }
}

#endif
