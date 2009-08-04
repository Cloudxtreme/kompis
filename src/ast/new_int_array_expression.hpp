#ifndef KOMPIS_AST_NEW_INT_ARRAY_EXPRESSION_HPP
#define KOMPIS_AST_NEW_INT_ARRAY_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class NewIntArrayExpression : public Expression
    {
      public:
        NewIntArrayExpression(Expression *count,
                              int line_num)
          : Expression(line_num),
            _count(count) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_count;
    };
  }
}

#endif
