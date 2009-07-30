#ifndef KOMPIS_IRT_TEMPORARY_EXPRESSION_HPP
#define KOMPIS_IRT_TEMPORARY_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    class TemporaryExpression : public Expression
    {
      public:
        TemporaryExpression(int num)
          : _num(num) {}

      private:
        int _num;
    };
  }
}

#endif
