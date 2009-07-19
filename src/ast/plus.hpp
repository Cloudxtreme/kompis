#ifndef KOMPIS_AST_PLUS_HPP
#define KOMPIS_AST_PLUS_HPP

#include "ast/expression.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class Plus : public Expression
    {
      public:
        Plus(Expression *left, Expression *right) : _left(left), _right(right) {}

        void accept(Visitor *visitor)
        {
          visitor->visit(this);
        }

      //private:
        Expression *_left, *_right;
    };
  }
}

#endif
