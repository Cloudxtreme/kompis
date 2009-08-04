#ifndef KOMPIS_AST_ARRAY_SUBSCRIPT_EXPRESSION_HPP
#define KOMPIS_AST_ARRAY_SUBSCRIPT_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IntArraySubscriptExpression : public Expression
    {
      public:
        IntArraySubscriptExpression(Expression *array,
                                    Expression *index,
                                    int line_num)
          : Expression(line_num),
            _array(array),
            _index(index) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_array;
        Expression *_index;
    };
  }
}

#endif
