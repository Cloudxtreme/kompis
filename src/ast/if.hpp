#ifndef KOMPIS_AST_IF_THEN_ELSE_HPP
#define KOMPIS_AST_IF_THEN_ELSE_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;

    class IfThenElseStatement : public Statement
    {
      public:
        IfThenElseStatement(Expression &pred, Statement &s1, Statement &s2) : _pred(pred), _s1(s1), _s2(s2) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_pred;
        Statement &_s1, &_s2;
    };
  }
}

#endif
