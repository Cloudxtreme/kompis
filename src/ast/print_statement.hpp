#ifndef KOMPIS_AST_PRINT_STATEMENT_HPP
#define KOMPIS_AST_PRINT_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;

    class PrintStatement : public Statement
    {
      public:
        PrintStatement(Expression *expr) : _expr(expr) {}

        void accept(Visitor *visitor);

      //private:
        Expression *_expr;
    };
  }
}

#endif
