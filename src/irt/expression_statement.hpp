#ifndef KOMPIS_IRT_EXPRESSION_STATEMENT_HPP
#define KOMPIS_IRT_EXPRESSION_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class Expression;

    class ExpressionStatement : public Statement
    {
      public:
        ExpressionStatement(Expression &expr)
          : _expr(expr) {}

      private:
        Expression &_expr;
    };
  }
}

#endif
