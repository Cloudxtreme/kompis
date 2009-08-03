#ifndef KOMPIS_AST_ARRAY_LENGTH_EXPRESSION_HPP
#define KOMPIS_AST_ARRAY_LENGTH_EXPRESSION_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class Visitor;

    class ArrayLengthExpression : public Expression
    {
      public:
        ArrayLengthExpression(Expression *array)
          : _array(array) {}

        void accept(Visitor *visitor);

      //private:
        Expression *_array;
    };
  }
}

#endif
