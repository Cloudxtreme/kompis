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
        ThisExpression(int line_num)
          : Expression(line_num) {}

        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
