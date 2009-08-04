#ifndef KOMPIS_AST_ADDITION_EXPRESSION_HPP
#define KOMPIS_AST_ADDITION_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class AdditionExpression : public Expression
    {
      public:
        AdditionExpression(int line_num, Expression *left, Expression *right)
          : Expression(line_num), _left(left), _right(right) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Expression *_left, *_right;
    };
  }
}

#endif
