#ifndef KOMPIS_AST_THIS_EXPRESSION_HPP
#define KOMPIS_AST_THIS_EXPRESSION_HPP

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
        ThisExpression(int line_num = 0)
          : Expression(line_num) {}

        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
