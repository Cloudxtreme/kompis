#ifndef KOMPIS_AST_WHILE_DO_STATEMENT_HPP
#define KOMPIS_AST_WHILE_DO_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;

    class WhileDoStatement : public Statement
    {
      public:
        WhileDoStatement(Expression *pred, Statement *s) : _pred(pred), _s(s) {}

        void accept(Visitor *visitor);

      //private:
        Expression *_pred;
        Statement *_s;
    };
  }
}

#endif
