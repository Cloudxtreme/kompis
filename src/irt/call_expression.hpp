#ifndef KOMPIS_IRT_CALL_EXPRESSION_HPP
#define KOMPIS_IRT_CALL_EXPRESSION_HPP

#include <list>
#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    class CallExpression : public Expression
    {
      public:
        CallExpression(Expression *function,
                       ExpressionList *args)
          : _function(function),
            _args(args) {}

      private:
        Expression *_function;
        ExpressionList *_args;
    };
  }
}

#endif
