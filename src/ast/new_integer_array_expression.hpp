#ifndef KOMPIS_AST_NEW_INTEGER_ARRAY_EXPRESSION_HPP
#define KOMPIS_AST_NEW_INTEGER_ARRAY_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;

    class NewIntegerArrayExpression : public Expression
    {
      public:
        NewIntegerArrayExpression(Expression *count)
          : _count(count) {}

        void accept(Visitor *visitor);

      //private:
        Expression *_count;
    };
  }
}

#endif
