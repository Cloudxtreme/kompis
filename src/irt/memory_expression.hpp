#ifndef KOMPIS_IRT_MEMORY_EXPRESSION_HPP
#define KOMPIS_IRT_MEMORY_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    class MemoryExpression : public Expression
    {
      public:
        MemoryExpression(Expression *expr)
          : _expr(expr) {}

      private:
        Expression *_expr;
    };
  }
}

#endif
