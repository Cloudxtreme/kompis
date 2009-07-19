#ifndef KOMPIS_AST_PRINT_HPP
#define KOMPIS_AST_PRINT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;

    class Print : public Statement
    {
      public:
        Print(Expression &expr) : _expr(expr) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_expr;
    };
  }
}

#endif
