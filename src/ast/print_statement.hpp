#ifndef KOMPIS_AST_PRINT_STATEMENT_HPP
#define KOMPIS_AST_PRINT_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class PrintStatement : public Statement
    {
      public:
        PrintStatement(Expression *expr,
                       int line_num = 0)
          : Statement(line_num),
            _expr(expr) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Expression *_expr;
    };
  }
}

#endif
