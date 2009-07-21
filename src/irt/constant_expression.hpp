#ifndef KOMPIS_IRT_CONSTANT_EXPRESSION_HPP
#define KOMPIS_IRT_CONSTANT_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    class ConstantExpression : public Expression
    {
      public:
        ConstantExpression(int value) : _value(value) {}

      private:
        int _value;
    };
  }
}

#endif
