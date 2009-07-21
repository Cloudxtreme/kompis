#ifndef KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP
#define KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    enum BinaryOperator
    {
      ADDITION_OPERATOR,                // +
      SUBTRACTION_OPERATOR,             // -
      MULTIPLICAION_OPERATOR,           // *
      DIVISION_OPERATOR,                // /
      CONJUNCTION_OPERATOR,             // and
      DISJUNCTION_OPERATOR,             // or
      EXCLUSIVE_DISJUNCTION_OPERATOR,   // xor
    };

    class BinaryOperationExpression : public Expression
    {
      public:
        BinaryOperationExpression(BinaryOperator o, Expression &l, Expression &r) : _operation(o), _left(l), _right(r) {}

      private:
        BinaryOperator _operation;
        Expression &_left;
        Expression &_right;
    };
  }
}

#endif
