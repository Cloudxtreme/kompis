#ifndef KOMPIS_AST_NOT_HPP
#define KOMPIS_AST_NOT_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class Not : public Expression
    {
      public:
        Not(Expression &expr) : _expr(expr) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_expr;
    };
  }
}

#endif
