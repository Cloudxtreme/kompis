#ifndef KOMPIS_AST_ASSIGNMENT_STATEMENT_HPP
#define KOMPIS_AST_ASSIGNMENT_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class Visitor;

    class AssignmentStatement : public Statement
    {
      public:
        AssignmentStatement(Identifier *id, Expression *expr) : _id(id), _expr(expr) {}

        void accept(Visitor *visitor);

      //private:
        Identifier *_id;
        Expression *_expr;
    };
  }
}

#endif
