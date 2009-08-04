#ifndef KOMPIS_AST_ARRAY_SUBSCRIPT_EXPRESSION_HPP
#define KOMPIS_AST_ARRAY_SUBSCRIPT_EXPRESSION_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class ArraySubscriptExpression : public Expression
    {
      public:
        ArraySubscriptExpression(Expression *array,
                                 Expression *index,
                                 int line_num)
          : Expression(line_num),
            _array(array),
            _index(index) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Expression *_array;
        Expression *_index;
    };
  }
}

#endif
