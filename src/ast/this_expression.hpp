#ifndef KOMPIS_AST_THIS_EXPRESSION_HPP
#define KOMPIS_AST_THIS_EXPRESSION_HPP

#include <string>
#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class ThisExpression : public Expression
    {
      public:
        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
