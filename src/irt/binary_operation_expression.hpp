#ifndef KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP
#define KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    class BinaryOperationExpression : public Expression
    {
      enum Operation
      {
        ADD,
        SUB,
        MUL,
        DIV,
        AND,
        OR,
      };

      public:
        BinaryOperationExpression(Operation op,
                                  Expression *lhs,
                                  Expression *rhs)
          : _op(op),
            _lhs(lhs),
            _rhs(rhs) {}

      private:
        BinaryOperation _op;
        Expression *_lhs;
        Expression *_rhs;
    };
  }
}

#endif
