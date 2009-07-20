#ifndef KOMPIS_AST_THIS_EXPRESSION_HPP
#define KOMPIS_AST_THIS_EXPRESSION_HPP

#include <string>
#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class ThisExpression : public Expression
    {
      public:
        void accept(Visitor &visitor);
    };
  }
}

#endif
