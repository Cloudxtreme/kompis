#ifndef KOMPIS_AST_ARRAY_LENGTH_EXPRESSION_HPP
#define KOMPIS_AST_ARRAY_LENGTH_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IntArrayLengthExpression : public Expression
    {
      public:
        IntArrayLengthExpression(Expression *array,
                              int line_num)
          : Expression(line_num),
            _array(array) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_array;
    };
  }
}

#endif
