#ifndef KOMPIS_AST_NEW_INTEGER_ARRAY_EXPRESSION_HPP
#define KOMPIS_AST_NEW_INTEGER_ARRAY_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class NewIntegerArrayExpression : public Expression
    {
      public:
        NewIntegerArrayExpression(Expression *count,
                                  int line_num)
          : Expression(line_num),
            _count(count) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Expression *_count;
    };
  }
}

#endif
