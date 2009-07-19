#ifndef KOMPIS_AST_TIMES_HPP
#define KOMPIS_AST_TIMES_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class Times : public Expression
    {
      public:
        Times(Expression &left, Expression &right) : _left(left), _right(right) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_left, &_right;
    };
  }
}

#endif
