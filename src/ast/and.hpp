#ifndef KOMPIS_AST_AND_HPP
#define KOMPIS_AST_AND_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class And : public Expression
    {
      public:
        And(Expression &left, Expression &right) : _left(left), _right(right) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_left, &_right;
    };
  }
}

#endif
