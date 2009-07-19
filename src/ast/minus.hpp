#ifndef KOMPIS_AST_MINUS_HPP
#define KOMPIS_AST_MINUS_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class Minus : public Expression
    {
      public:
        Minus(Expression &left, Expression &right) : _left(left), _right(right) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_left, &_right;
    };
  }
}

#endif
