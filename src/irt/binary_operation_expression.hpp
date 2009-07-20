#ifndef KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP
#define KOMPIS_IRT_BINARY_OPERATION_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    enum BinaryOperation
    {
      // + - * < and
    };

    class BinaryOperationExpression : public Expression
    {
      public:
        BinaryOperationExpression(BinaryOperation o, Expression &l, Expression &r) : _operation(o), _left(l), _right(r) {}

      private:
        BinaryOperation _operation;
        Expression &_left;
        Expression &_right;
    };
  }
}

#endif
