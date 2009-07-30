#ifndef KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP
#define KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    namespace binop
    {
      enum BinaryOperation
      {
        ADD,
        SUB,
        MUL,
        DIV,
        AND,
        OR,
        XOR,
      };
    }

    class BinaryOperationExpression : public Expression
    {
      public:
        BinaryOperationExpression(binop::BinaryOperation op,
                                  Expression &left,
                                  Expression &right)
          : _op(op),
            _left(left),
            _right(right) {}

      private:
        binop::BinaryOperation _op;
        Expression &_left;
        Expression &_right;
    };
  }
}

#endif
