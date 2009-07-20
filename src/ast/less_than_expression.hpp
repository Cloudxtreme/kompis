#ifndef KOMPIS_AST_LESS_THAN_EXPRESSION_HPP
#define KOMPIS_AST_LESS_THAN_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class LessThanExpression : public Expression
    {
      public:
        LessThanExpression(Expression &left, Expression &right) : _left(left), _right(right) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_left, &_right;
    };
  }
}

#endif
