#ifndef KOMPIS_AST_LESS_THAN_HPP
#define KOMPIS_AST_LESS_THAN_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class LessThan : public Expression
    {
      public:
        LessThan(Expression &left, Expression &right) : _left(left), _right(right) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_left, &_right;
    };
  }
}

#endif
